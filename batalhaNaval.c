#include <stdio.h>

// Constantes do jogo
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    printf("=== BATALHA NAVAL - POSICIONAMENTO DE NAVIOS ===\n\n");

    // Inicializa o tabuleiro com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Navio 1 - Horizontal (linha 2, coluna 3)
    int linha_navio1 = 2;
    int coluna_navio1 = 3;
    
    // Verifica se o navio horizontal cabe no tabuleiro
    if (coluna_navio1 + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio horizontal não cabe no tabuleiro na posição especificada.\n");
        return 1;
    }
    
    // Posiciona o navio horizontal
    for (int j = coluna_navio1; j < coluna_navio1 + TAMANHO_NAVIO; j++) {
        tabuleiro[linha_navio1][j] = NAVIO;
    }

    // Navio 2 - Vertical (linha 5, coluna 7)
    int linha_navio2 = 5;
    int coluna_navio2 = 7;
    
    // Verifica se o navio vertical cabe no tabuleiro
    if (linha_navio2 + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio vertical não cabe no tabuleiro na posição especificada.\n");
        return 1;
    }
    
    // Verifica sobreposição com o navio horizontal
    for (int i = linha_navio2; i < linha_navio2 + TAMANHO_NAVIO; i++) {
        if (tabuleiro[i][coluna_navio2] == NAVIO) {
            printf("Erro: Navios estão se sobrepondo.\n");
            return 1;
        }
    }
    
    // Posiciona o navio vertical
    for (int i = linha_navio2; i < linha_navio2 + TAMANHO_NAVIO; i++) {
        tabuleiro[i][coluna_navio2] = NAVIO;
    }

    // Exibe o tabuleiro
    printf("Tabuleiro com navios posicionados:\n");
    printf("  0 1 2 3 4 5 6 7 8 9\n"); // Índices das colunas
    
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i); // Índice da linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // Legenda
    printf("\nLegenda:\n");
    printf("0 - Água\n");
    printf("3 - Parte de um navio\n");

    return 0;
}
