#include <stdio.h>

#define TAM 10       // Tamanho do tabuleiro (10x10)
#define TAM_HAB 5    // Tamanho fixo das habilidades (5x5)
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Função para inicializar o tabuleiro
void inicializar_tabuleiro(int tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tab[i][j] = AGUA;
        }
    }
}

// Função para imprimir o tabuleiro
void imprimir_tabuleiro(int tab[TAM][TAM]) {
    printf("\n=== TABULEIRO COM HABILIDADES ===\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            // Exibir de forma mais visual
            if (tab[i][j] == AGUA)
                printf(" ~ ");   // Água
            else if (tab[i][j] == NAVIO)
                printf(" N ");   // Navio
            else if (tab[i][j] == HABILIDADE)
                printf(" * ");   // Área afetada
        }
        printf("\n");
    }
}

// Função para gerar a matriz de habilidade em forma de cone
void gerar_cone(int cone[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= TAM_HAB / 2 - i && j <= TAM_HAB / 2 + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }
}

// Função para gerar a matriz de habilidade em forma de cruz
void gerar_cruz(int cruz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }
}

// Função para gerar a matriz de habilidade em forma de octaedro (losango)
void gerar_octaedro(int octa[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro)
                octa[i][j] = 1;
            else
                octa[i][j] = 0;
        }
    }
}

// Função para sobrepor a habilidade no tabuleiro
void aplicar_habilidade(int tab[TAM][TAM], int hab[TAM_HAB][TAM_HAB], int linha_centro, int col_centro) {
    int centro = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (hab[i][j] == 1) {
                int linha = linha_centro - centro + i;
                int coluna = col_centro - centro + j;

                // Garantir que está dentro dos limites do tabuleiro
                if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                    if (tab[linha][coluna] == AGUA)
                        tab[linha][coluna] = HABILIDADE;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    // 1️⃣ Inicializar o tabuleiro
    inicializar_tabuleiro(tabuleiro);

    // 2️⃣ Posicionar alguns navios fixos (como nos níveis anteriores)
    for (int i = 0; i < 3; i++) {
        tabuleiro[2][2 + i] = NAVIO; // horizontal
        tabuleiro[6 + i][5] = NAVIO; // vertical
    }

    // 3️⃣ Gerar as matrizes das habilidades
    gerar_cone(cone);
    gerar_cruz(cruz);
    gerar_octaedro(octaedro);

    // 4️⃣ Aplicar as habilidades em pontos diferentes do tabuleiro
    aplicar_habilidade(tabuleiro, cone, 3, 3);      // Cone centrado em (3,3)
    aplicar_habilidade(tabuleiro, cruz, 5, 7);      // Cruz centrada em (5,7)
    aplicar_habilidade(tabuleiro, octaedro, 8, 2);  // Octaedro centrado em (8,2)

    // 5️⃣ Exibir o tabuleiro final
    imprimir_tabuleiro(tabuleiro);

    return 0;
}
