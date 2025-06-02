#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta de país
typedef struct {
    char nome[30];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
} Carta;

// Função para comparar as cartas conforme o atributo escolhido
void compararCartas(Carta c1, Carta c2, int escolha) {
    printf("\nComparando: %s vs %s\n\n", c1.nome, c2.nome);

    switch (escolha) {
        case 1:
            // Nome só serve pra mostrar mesmo
            printf("Nome dos países:\n%s vs %s\n", c1.nome, c2.nome);
            printf("Esse atributo não serve pra comparar, só pra exibir mesmo.\n");
            break;

        case 2:
            // Comparação por população
            printf("População:\n%d (%s) vs %d (%s)\n", c1.populacao, c1.nome, c2.populacao, c2.nome);
            if (c1.populacao > c2.populacao)
                printf("Vencedor: %s\n", c1.nome);
            else if (c2.populacao > c1.populacao)
                printf("Vencedor: %s\n", c2.nome);
            else
                printf("Empate!\n");
            break;

        case 3:
            // Comparação por área
            printf("Área:\n%.2f km² (%s) vs %.2f km² (%s)\n", c1.area, c1.nome, c2.area, c2.nome);
            if (c1.area > c2.area)
                printf("Vencedor: %s\n", c1.nome);
            else if (c2.area > c1.area)
                printf("Vencedor: %s\n", c2.nome);
            else
                printf("Empate!\n");
            break;

        case 4:
            // Comparação por PIB
            printf("PIB:\n%.2f bilhões (%s) vs %.2f bilhões (%s)\n", c1.pib, c1.nome, c2.pib, c2.nome);
            if (c1.pib > c2.pib)
                printf("Vencedor: %s\n", c1.nome);
            else if (c2.pib > c1.pib)
                printf("Vencedor: %s\n", c2.nome);
            else
                printf("Empate!\n");
            break;

        case 5:
            // Comparação por pontos turísticos
            printf("Pontos Turísticos:\n%d (%s) vs %d (%s)\n", c1.pontosTuristicos, c1.nome, c2.pontosTuristicos, c2.nome);
            if (c1.pontosTuristicos > c2.pontosTuristicos)
                printf("Vencedor: %s\n", c1.nome);
            else if (c2.pontosTuristicos > c1.pontosTuristicos)
                printf("Vencedor: %s\n", c2.nome);
            else
                printf("Empate!\n");
            break;

        case 6:
            // Comparação por densidade (menor vence aqui!)
            printf("Densidade Demográfica:\n%.2f hab/km² (%s) vs %.2f hab/km² (%s)\n", c1.densidade, c1.nome, c2.densidade, c2.nome);
            if (c1.densidade < c2.densidade)
                printf("Vencedor: %s (menor densidade vence)\n", c1.nome);
            else if (c2.densidade < c1.densidade)
                printf("Vencedor: %s (menor densidade vence)\n", c2.nome);
            else
                printf("Empate!\n");
            break;

        default:
            printf("Opção inválida. Tente outra!\n");
    }
}

int main() {
    // Cartas de exemplo
    Carta pais1 = {"Brasil", 213000000, 8515767.0, 1440.0, 10, 213000000 / 8515767.0};
    Carta pais2 = {"Canadá", 38000000, 9984670.0, 1800.0, 7, 38000000 / 9984670.0};

    int opcao;

    // Menu de seleção
    printf("=== SUPER TRUNFO - COMPARAÇÃO DE PAÍSES ===\n\n");
    printf("Escolha o que você quer comparar:\n");
    printf("1 - Nome do País\n");
    printf("2 - População\n");
    printf("3 - Área\n");
    printf("4 - PIB\n");
    printf("5 - Pontos Turísticos\n");
    printf("6 - Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    // Chama a comparação
    compararCartas(pais1, pais2, opcao);

    return 0;
}
