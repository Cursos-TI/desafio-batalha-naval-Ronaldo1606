#include <stdio.h>

#define TAM 10      // Tamanho do tabuleiro (10x10)
#define NAVIO 3     // Valor que representa o navio
#define AGUA 0      // Valor que representa a água
#define TAM_NAVIO 3 // Tamanho fixo dos navios

int main() {
    int tabuleiro[TAM][TAM]; // Matriz 10x10 representando o tabuleiro
    int i, j;

    // 1️⃣ Inicializar o tabuleiro com água (0)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // 2️⃣ Definir coordenadas iniciais dos navios
    // Navio 1 → horizontal
    int linhaH = 2; // linha inicial
    int colH = 4;   // coluna inicial

    // Navio 2 → vertical
    int linhaV = 5; // linha inicial
    int colV = 7;   // coluna inicial

    // 3️⃣ Validar se os navios cabem no tabuleiro
    // (Para simplificação, assume-se que as coordenadas estão corretas)
    if (colH + TAM_NAVIO <= TAM && linhaV + TAM_NAVIO <= TAM) {

        // 4️⃣ Posicionar navio horizontal
        for (i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaH][colH + i] = NAVIO;
        }

        // 5️⃣ Posicionar navio vertical
        for (i = 0; i < TAM_NAVIO; i++) {
            // Garantir que não haja sobreposição
            if (tabuleiro[linhaV + i][colV] == AGUA) {
                tabuleiro[linhaV + i][colV] = NAVIO;
            }
        }
    } else {
        printf("Erro: Coordenadas inválidas, o navio sairia do tabuleiro.\n");
        return 1;
    }

    // 6️⃣ Exibir o tabuleiro
    printf("=== TABULEIRO DE BATALHA NAVAL ===\n\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
