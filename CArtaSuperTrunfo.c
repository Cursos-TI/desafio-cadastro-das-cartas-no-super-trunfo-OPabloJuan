#include <stdio.h>

// Função para mostrar o menu de atributos (exceto o atributo excluído)
void mostrarMenu(int excluir) {
    printf("\nEscolha o atributo para comparar:\n");
    if (excluir != 1) printf("1 - Populacao\n");
    if (excluir != 2) printf("2 - Area\n");
    if (excluir != 3) printf("3 - PIB\n");
    if (excluir != 4) printf("4 - Numero de Pontos Turisticos\n");
    if (excluir != 5) printf("5 - Densidade Demografica\n");
    printf("Digite sua escolha: ");
}

// Função para obter o valor do atributo escolhido da carta 1
float getValorAtributoCarta1(int atributo, int populacao, float area, float pib, int pontosTuristicos, float densidade) {
    switch (atributo) {
        case 1: return (float)populacao;
        case 2: return area;
        case 3: return pib;
        case 4: return (float)pontosTuristicos;
        case 5: return densidade;
        default: return 0.0f; // não esperado
    }
}

// Função para obter o valor do atributo escolhido da carta 2
float getValorAtributoCarta2(int atributo, int populacao, float area, float pib, int pontosTuristicos, float densidade) {
    // mesma lógica que a função anterior, mas para a segunda carta
    switch (atributo) {
        case 1: return (float)populacao;
        case 2: return area;
        case 3: return pib;
        case 4: return (float)pontosTuristicos;
        case 5: return densidade;
        default: return 0.0f;
    }
}

// Função para exibir o nome do atributo pelo número
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "Populacao";
        case 2: return "Area";
        case 3: return "PIB";
        case 4: return "Numero de Pontos Turisticos";
        case 5: return "Densidade Demografica";
        default: return "Desconhecido";
    }
}

int main() {
    // Cartas
    char nomeCidade1[] = "Joao Pessoa";
    int populacao1 = 833932;
    float area1 = 21148.0f;
    float pib1 = 36.257f;
    int pontosTuristicos1 = 15;
    float densidade1 = populacao1 / area1;

    char nomeCidade2[] = "Pernambuco";
    int populacao2 = 9540000;
    float area2 = 98076.0f;
    float pib2 = 288.67f;
    int pontosTuristicos2 = 16;
    float densidade2 = populacao2 / area2;

    int escolha1 = 0, escolha2 = 0;

    // Escolha do primeiro atributo
    do {
        mostrarMenu(0);
        scanf("%d", &escolha1);
        if (escolha1 < 1 || escolha1 > 5) {
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (escolha1 < 1 || escolha1 > 5);

    // Escolha do segundo atributo (não pode ser igual ao primeiro)
    do {
        mostrarMenu(escolha1);
        scanf("%d", &escolha2);
        if (escolha2 < 1 || escolha2 > 5) {
            printf("Opcao invalida. Tente novamente.\n");
        } else if (escolha2 == escolha1) {
            printf("Voce ja escolheu este atributo. Escolha outro.\n");
        }
    } while (escolha2 < 1 || escolha2 > 5 || escolha2 == escolha1);

    // Obtém valores dos atributos para as duas cartas
    float valor1_attr1 = getValorAtributoCarta1(escolha1, populacao1, area1, pib1, pontosTuristicos1, densidade1);
    float valor1_attr2 = getValorAtributoCarta1(escolha2, populacao1, area1, pib1, pontosTuristicos1, densidade1);
    float valor2_attr1 = getValorAtributoCarta2(escolha1, populacao2, area2, pib2, pontosTuristicos2, densidade2);
    float valor2_attr2 = getValorAtributoCarta2(escolha2, populacao2, area2, pib2, pontosTuristicos2, densidade2);

    // Função auxiliar: compara um atributo, retorna 1 se carta1 vence, 0 se carta2 vence, -1 empate
    int comparar(int atributo, float val1, float val2) {
        if (val1 == val2) return -1; // empate
        if (atributo == 5) { // densidade: menor vence
            return (val1 < val2) ? 1 : 0;
        } else { // demais atributos: maior vence
            return (val1 > val2) ? 1 : 0;
        }
    }

    // Comparações individuais
    int resultado_attr1 = comparar(escolha1, valor1_attr1, valor2_attr1);
    int resultado_attr2 = comparar(escolha2, valor1_attr2, valor2_attr2);

    // Soma dos valores para decidir vencedor geral
    // Para densidade, invertendo para que soma faça sentido (usando o inverso)
    float valor1_attr1_para_soma = (escolha1 == 5) ? (1.0f / valor1_attr1) : valor1_attr1;
    float valor1_attr2_para_soma = (escolha2 == 5) ? (1.0f / valor1_attr2) : valor1_attr2;
    float valor2_attr1_para_soma = (escolha1 == 5) ? (1.0f / valor2_attr1) : valor2_attr1;
    float valor2_attr2_para_soma = (escolha2 == 5) ? (1.0f / valor2_attr2) : valor2_attr2;

    float soma1 = valor1_attr1_para_soma + valor1_attr2_para_soma;
    float soma2 = valor2_attr1_para_soma + valor2_attr2_para_soma;

    // Determinar vencedor da soma
    int resultado_geral = (soma1 > soma2) ? 1 : ((soma1 < soma2) ? 0 : -1);

    // Exibição dos resultados
    printf("\n=== Resultado da Comparacao ===\n\n");
    printf("Cartas comparadas: %s x %s\n\n", nomeCidade1, nomeCidade2);

    printf("Atributo 1: %s\n", nomeAtributo(escolha1));
    printf("  %s: %.3f\n", nomeCidade1, valor1_attr1);
    printf("  %s: %.3f\n", nomeCidade2, valor2_attr1);
    printf("  Vencedor deste atributo: %s\n\n",
           resultado_attr1 == -1 ? "Empate" : (resultado_attr1 == 1 ? nomeCidade1 : nomeCidade2));

    printf("Atributo 2: %s\n", nomeAtributo(escolha2));
    printf("  %s: %.3f\n", nomeCidade1, valor1_attr2);
    printf("  %s: %.3f\n", nomeCidade2, valor2_attr2);
    printf("  Vencedor deste atributo: %s\n\n",
           resultado_attr2 == -1 ? "Empate" : (resultado_attr2 == 1 ? nomeCidade1 : nomeCidade2));

    printf("Soma dos atributos (ajustada para densidade):\n");
    printf("  %s: %.3f\n", nomeCidade1, soma1);
    printf("  %s: %.3f\n", nomeCidade2, soma2);

    if (resultado_geral == 1) {
        printf("\nResultado final: %s venceu a rodada!\n", nomeCidade1);
    } else if (resultado_geral == 0) {
        printf("\nResultado final: %s venceu a rodada!\n", nomeCidade2);
    } else {
        printf("\nResultado final: Empate!\n");
    }

    return 0;
}

