#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados da carta
typedef struct {
    char nome[50];
    char estado[30];
    char codigo[10];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

// Função para calcular densidade populacional e PIB per capita
void calcularIndicadores(Carta *carta) {
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}

// Função para exibir o menu e retornar a escolha do usuário
int exibirMenu() {
    int opcao;
    printf("\n===== SUPER TRUNFO: COMPARAÇÃO DE CIDADES =====\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);
    return opcao;
}

// Função que realiza a comparação com base no atributo escolhido
void compararCartas(Carta c1, Carta c2, int atributo) {
    float valor1 = 0, valor2 = 0;
    char nomeAtributo[50];

    switch (atributo) {
        case 1:  // População
            valor1 = c1.populacao;
            valor2 = c2.populacao;
            strcpy(nomeAtributo, "População");
            break;

        case 2:  // Área
            valor1 = c1.area;
            valor2 = c2.area;
            strcpy(nomeAtributo, "Área");
            break;

        case 3:  // PIB
            valor1 = c1.pib;
            valor2 = c2.pib;
            strcpy(nomeAtributo, "PIB");
            break;

        case 4:  // Pontos turísticos
            valor1 = c1.pontosTuristicos;
            valor2 = c2.pontosTuristicos;
            strcpy(nomeAtributo, "Pontos Turísticos");
            break;

        case 5:  // Densidade Demográfica (regra invertida)
            valor1 = c1.densidadePopulacional;
            valor2 = c2.densidadePopulacional;
            strcpy(nomeAtributo, "Densidade Demográfica");
            break;

        default:
            printf("Opção inválida! Por favor, reinicie o programa e escolha entre 1 e 5.\n");
            return;
    }

    // Mostrar os dados comparados
    printf("\n=== Comparação de Cartas (Atributo: %s) ===\n", nomeAtributo);
    printf("Carta 1 - %s: %.2f\n", c1.nome, valor1);
    printf("Carta 2 - %s: %.2f\n", c2.nome, valor2);

    // Lógica de decisão
    if (atributo == 5) { // Densidade Demográfica: vence o menor
        if (valor1 < valor2) {
            printf("Resultado: %s venceu!\n", c1.nome);
        } else if (valor1 > valor2) {
            printf("Resultado: %s venceu!\n", c2.nome);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else { // Nos demais atributos: vence o maior
        if (valor1 > valor2) {
            printf("Resultado: %s venceu!\n", c1.nome);
        } else if (valor1 < valor2) {
            printf("Resultado: %s venceu!\n", c2.nome);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
}

// Função principal
int main() {
    // Criando as duas cartas
    Carta brasilia = {"Brasília", "Distrito Federal", "DF01", 3055149, 5802.0, 273.5, 15};
    Carta recife = {"Recife", "Pernambuco", "PE01", 1653461, 218.5, 69.0, 10};

    // Calculando indicadores
    calcularIndicadores(&brasilia);
    calcularIndicadores(&recife);

    // Mostrando menu e capturando escolha
    int opcao = exibirMenu();

    // Realizando comparação com base na opção
    compararCartas(brasilia, recife, opcao);

    return 0;
}
