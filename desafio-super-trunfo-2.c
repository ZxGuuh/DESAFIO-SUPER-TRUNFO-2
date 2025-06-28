#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta do Super Trunfo
typedef struct {
    char nome[50];
    char estado[30];
    char codigo[10];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
    float pibPerCapita;
} Carta;

// Função que calcula a densidade demográfica e PIB per capita
void calcularIndicadores(Carta *c) {
    c->densidadeDemografica = c->populacao / c->area;
    c->pibPerCapita = c->pib / c->populacao;
}

// Função que exibe o menu de atributos
void mostrarMenuAtributos(int opcaoIgnorar) {
    printf("Escolha um atributo para comparação:\n");

    if (opcaoIgnorar != 1) printf("1 - População\n");
    if (opcaoIgnorar != 2) printf("2 - Área\n");
    if (opcaoIgnorar != 3) printf("3 - PIB\n");
    if (opcaoIgnorar != 4) printf("4 - Pontos Turísticos\n");
    if (opcaoIgnorar != 5) printf("5 - Densidade Demográfica\n");
}

// Função que retorna o valor do atributo escolhido
float obterValorAtributo(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontosTuristicos;
        case 5: return c.densidadeDemografica;
        default: return 0;
    }
}

// Função que retorna o nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

// Função principal
int main() {
    // Cartas pré-definidas
    Carta brasilia = {"Brasília", "Distrito Federal", "DF01", 3055149, 5802.0, 273.5, 15};
    Carta recife = {"Recife", "Pernambuco", "PE01", 1653461, 218.5, 69.0, 10};

    // Calcula os atributos derivados
    calcularIndicadores(&brasilia);
    calcularIndicadores(&recife);

    int atributo1 = 0, atributo2 = 0;

    // ======== MENU INTERATIVO ========
    printf("===== SUPER TRUNFO: COMPARAÇÃO AVANÇADA =====\n");

    // Escolha do primeiro atributo
    do {
        mostrarMenuAtributos(0);
        printf("Digite o número do primeiro atributo: ");
        scanf("%d", &atributo1);

        if (atributo1 < 1 || atributo1 > 5)
            printf("Opção inválida. Tente novamente.\n");

    } while (atributo1 < 1 || atributo1 > 5);

    // Escolha do segundo atributo (sem repetir o primeiro)
    do {
        mostrarMenuAtributos(atributo1);
        printf("Digite o número do segundo atributo (diferente do primeiro): ");
        scanf("%d", &atributo2);

        if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1)
            printf("Opção inválida. Tente novamente.\n");

    } while (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1);

    // ==== OBTÉM VALORES DOS ATRIBUTOS ESCOLHIDOS ====
    float valB1 = obterValorAtributo(brasilia, atributo1);
    float valB2 = obterValorAtributo(brasilia, atributo2);
    float valR1 = obterValorAtributo(recife, atributo1);
    float valR2 = obterValorAtributo(recife, atributo2);

    // Exibe os valores
    printf("\n===== COMPARAÇÃO FINAL =====\n");
    printf("Atributos escolhidos: %s e %s\n", nomeAtributo(atributo1), nomeAtributo(atributo2));

    printf("\n-- %s --\n", brasilia.nome);
    printf("%s: %.2f\n", nomeAtributo(atributo1), valB1);
    printf("%s: %.2f\n", nomeAtributo(atributo2), valB2);

    printf("\n-- %s --\n", recife.nome);
    printf("%s: %.2f\n", nomeAtributo(atributo1), valR1);
    printf("%s: %.2f\n", nomeAtributo(atributo2), valR2);

    // === COMPARAÇÃO INDIVIDUAL POR ATRIBUTO ===
    int pontosB = 0, pontosR = 0;

    // Comparação do primeiro atributo
    if (atributo1 == 5) {
        pontosB += (valB1 < valR1) ? 1 : (valB1 > valR1) ? 0 : 0;
        pontosR += (valB1 > valR1) ? 1 : (valB1 < valR1) ? 0 : 0;
    } else {
        pontosB += (valB1 > valR1) ? 1 : (valB1 < valR1) ? 0 : 0;
        pontosR += (valB1 < valR1) ? 1 : (valB1 > valR1) ? 0 : 0;
    }

    // Comparação do segundo atributo
    if (atributo2 == 5) {
        pontosB += (valB2 < valR2) ? 1 : (valB2 > valR2) ? 0 : 0;
        pontosR += (valB2 > valR2) ? 1 : (valB2 < valR2) ? 0 : 0;
    } else {
        pontosB += (valB2 > valR2) ? 1 : (valB2 < valR2) ? 0 : 0;
        pontosR += (valB2 < valR2) ? 1 : (valB2 > valR2) ? 0 : 0;
    }

    // ==== SOMA TOTAL DOS ATRIBUTOS ====
    float somaB = (atributo1 == 5 ? -valB1 : valB1) + (atributo2 == 5 ? -valB2 : valB2);
    float somaR = (atributo1 == 5 ? -valR1 : valR1) + (atributo2 == 5 ? -valR2 : valR2);

    printf("\nSoma total de atributos:\n");
    printf("%s: %.2f\n", brasilia.nome, somaB);
    printf("%s: %.2f\n", recife.nome, somaR);

    // Resultado final
    if (somaB > somaR) {
        printf("\nResultado Final: %s venceu!\n", brasilia.nome);
    } else if (somaR > somaB) {
        printf("\nResultado Final: %s venceu!\n", recife.nome);
    } else {
        printf("\nResultado Final: Empate!\n");
    }

    return 0;
}
