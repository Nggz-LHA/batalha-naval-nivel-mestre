#include <stdio.h>

#define TAM 10         // Tamanho do tabuleiro 10x10
#define TAM_NAVIO 3    // Tamanho fixo dos navios
#define NAVIO 3        // Valor para representar navio no tabuleiro
#define HABILIDADE 5   // Valor para representar área afetada pela habilidade

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    char linha[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };

    printf("  ");
    for (int j = 0; j < TAM; j++) {
        printf("%d ", j);
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%c ", linha[i]);
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para aplicar a habilidade Cone
void aplicarHabilidadeCone(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j <= i; j++) {
            if (linha + i < TAM && coluna - j >= 0) {
                tabuleiro[linha + i][coluna - j] = HABILIDADE;
            }
            if (linha + i < TAM && coluna + j < TAM) {
                tabuleiro[linha + i][coluna + j] = HABILIDADE;
            }
        }
    }
}

// Função para aplicar a habilidade Cruz
void aplicarHabilidadeCruz(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < TAM; i++) {
        if (linha + i < TAM) {
            tabuleiro[linha + i][coluna] = HABILIDADE;
        }
        if (coluna + i < TAM) {
            tabuleiro[linha][coluna + i] = HABILIDADE;
        }
    }
}

// Função para aplicar a habilidade Octaedro
void aplicarHabilidadeOctaedro(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j <= i; j++) {
            if (linha + i < TAM && coluna - j >= 0) {
                tabuleiro[linha + i][coluna - j] = HABILIDADE;
            }
            if (linha + i < TAM && coluna + j < TAM) {
                tabuleiro[linha + i][coluna + j] = HABILIDADE;
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // Posiciona os navios (valor 3)
    tabuleiro[2][3] = NAVIO;
    tabuleiro[3][2] = NAVIO;
    tabuleiro[3][3] = NAVIO;
    tabuleiro[4][2] = NAVIO;

    // Aplica as habilidades
    aplicarHabilidadeCone(tabuleiro, 3, 6);
    aplicarHabilidadeCruz(tabuleiro, 5, 1);
    aplicarHabilidadeOctaedro(tabuleiro, 5, 5);

    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}