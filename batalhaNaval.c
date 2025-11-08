#include <stdio.h>

#define TAM 10      // Tamanho do tabuleiro (10x10)
#define NAVIO 3     // Valor que representa um navio
#define AGUA 0      // Valor que representa água
#define TAM_NAVIO 3 // Tamanho fixo de cada navio

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;

    // 1️⃣ Inicializa o tabuleiro com 0 (água)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // 2️⃣ Coordenadas iniciais dos navios (definidas diretamente no código)

    // Navio 1 → horizontal
    int linhaH = 1;
    int colH = 2;

    // Navio 2 → vertical
    int linhaV = 5;
    int colV = 4;

    // Navio 3 → diagonal principal (↘)
    int linhaD1 = 0;
    int colD1 = 6;

    // Navio 4 → diagonal secundária (↙)
    int linhaD2 = 6;
    int colD2 = 6;

    // 3️⃣ Função auxiliar para verificar se uma posição está livre
    auto int posicao_livre(int l, int c) {
        if (l < 0 || l >= TAM || c < 0 || c >= TAM)
            return 0; // fora do tabuleiro
        return tabuleiro[l][c] == AGUA;
    }

    // 4️⃣ Posicionar navio horizontal
    if (colH + TAM_NAVIO <= TAM) {
        int sobrepoe = 0;
        for (i = 0; i < TAM_NAVIO; i++) {
            if (!posicao_livre(linhaH, colH + i)) sobrepoe = 1;
        }
        if (!sobrepoe) {
            for (i = 0; i < TAM_NAVIO; i++)
                tabuleiro[linhaH][colH + i] = NAVIO;
        }
    }

    // 5️⃣ Posicionar navio vertical
    if (linhaV + TAM_NAVIO <= TAM) {
        int sobrepoe = 0;
        for (i = 0; i < TAM_NAVIO; i++) {
            if (!posicao_livre(linhaV + i, colV)) sobrepoe = 1;
        }
        if (!sobrepoe) {
            for (i = 0; i < TAM_NAVIO; i++)
                tabuleiro[linhaV + i][colV] = NAVIO;
        }
    }

    // 6️⃣ Posicionar navio diagonal ↘ (linha e coluna aumentam)
    if (linhaD1 + TAM_NAVIO <= TAM && colD1 + TAM_NAVIO <= TAM) {
        int sobrepoe = 0;
        for (i = 0; i < TAM_NAVIO; i++) {
            if (!posicao_livre(linhaD1 + i, colD1 + i)) sobrepoe = 1;
        }
        if (!sobrepoe) {
            for (i = 0; i < TAM_NAVIO; i++)
                tabuleiro[linhaD1 + i][colD1 + i] = NAVIO;
        }
    }

    // 7️⃣ Posicionar navio diagonal ↙ (linha aumenta, coluna diminui)
    if (linhaD2 + TAM_NAVIO <= TAM && colD2 - (TAM_NAVIO - 1) >= 0) {
        int sobrepoe = 0;
        for (i = 0; i < TAM_NAVIO; i++) {
            if (!posicao_livre(linhaD2 + i, colD2 - i)) sobrepoe = 1;
        }
        if (!sobrepoe) {
            for (i = 0; i < TAM_NAVIO; i++)
                tabuleiro[linhaD2 + i][colD2 - i] = NAVIO;
        }
    }

    // 8️⃣ Exibir o tabuleiro
    printf("=== TABULEIRO COMPLETO - NIVEL AVENTUREIRO ===\n\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
