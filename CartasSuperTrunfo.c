#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar uma carta de cidade
typedef struct {
    char codigo[4]; // Código da carta (ex: A01)
    char estado;    // Letra do estado (A, B, C...)
    int cidade;     // Número da cidade (1, 2, 3, 4)
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Carta;

// Função para cadastrar uma carta
Carta cadastrar_carta() {
    Carta carta;

    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", carta.codigo);

    // Extrai a letra do estado e o número da cidade do código
    carta.estado = carta.codigo[0];
    carta.cidade = atoi(&carta.codigo[1]);

    printf("Digite a população: ");
    scanf("%d", &carta.populacao);

    printf("Digite a área (em km²): ");
    scanf("%f", &carta.area);

    printf("Digite o PIB (em milhões de R$): ");
    scanf("%f", &carta.pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta.pontos_turisticos);

    return carta;
}

// Função para exibir os dados de uma carta
void exibir_carta(Carta carta) {
    printf("\n--- Dados da Cidade ---\n");
    printf("Código: %s\n", carta.codigo);
    printf("Estado: %c\n", carta.estado);
    printf("Cidade: %d\n", carta.cidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f milhões de R$\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
}

int main() {
    Carta cartas[8][4]; // Matriz para armazenar as cartas de cada estado/cidade

    // Loop para cadastrar as cartas
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            printf("\n--- Cadastro da Carta %c%d ---\n", 'A' + i, j + 1);
            cartas[i][j] = cadastrar_carta();
        }
    }

    // Loop para exibir os dados das cartas
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            exibir_carta(cartas[i][j]);
        }
    }

    return 0;
}