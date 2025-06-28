#include <stdio.h> // biblioteca padrão de entrada e saída
#include <string.h> // biblioteca para usar strings (cadeias de caracteres)

// -------------------------
// Definindo a estrutura "Carta"
// -------------------------
/*
   A estrutura "Carta" serve para guardar todos os dados de uma cidade.
   Ela agrupa várias variáveis em um único "tipo".
*/
typedef struct {
    char estado[30];               // Estado da cidade (ex: "Distrito Federal")
    char codigo[10];               // Código da carta (ex: "DF01")
    char nome[50];                 // Nome da cidade (ex: "Brasília")
    int populacao;                 // População total da cidade
    float area;                    // Área em quilômetros quadrados
    float pib;                     // Produto Interno Bruto em bilhões
    int pontosTuristicos;         // Número de pontos turísticos
    float densidadePopulacional;  // População / Área
    float pibPerCapita;           // PIB / População
} Carta;

// -------------------------
// Função para calcular indicadores (densidade e PIB per capita)
// -------------------------
void calcularIndicadores(Carta *carta) {
    // Cálculo da densidade populacional
    carta->densidadePopulacional = carta->populacao / carta->area;

    // Cálculo do PIB per capita
    carta->pibPerCapita = carta->pib / carta->populacao;
}

// -------------------------
// Função para imprimir os dados de uma carta
// -------------------------
void imprimirCarta(Carta carta) {
    printf("Cidade: %s (%s)\n", carta.nome, carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per capita: %.2f\n", carta.pibPerCapita);
    printf("-----------------------------------------\n");
}

// -------------------------
// Função que compara duas cartas usando o PIB per capita
// -------------------------
void compararCartas(Carta carta1, Carta carta2) {
    printf("=== COMPARAÇÃO DE CARTAS ===\n");
    printf("Atributo escolhido: PIB per capita\n\n");

    // Mostrar as duas cartas
    printf("Carta 1:\n");
    imprimirCarta(carta1);

    printf("Carta 2:\n");
    imprimirCarta(carta2);

    // Lógica para determinar qual carta venceu
    if (carta1.pibPerCapita > carta2.pibPerCapita) {
        printf("Resultado: Carta 1 (%s) venceu com PIB per capita maior!\n", carta1.nome);
    }
    else if (carta1.pibPerCapita < carta2.pibPerCapita) {
        printf("Resultado: Carta 2 (%s) venceu com PIB per capita maior!\n", carta2.nome);
    }
    else {
        printf("Resultado: Empate! As duas cartas têm o mesmo PIB per capita.\n");
    }
}

// -------------------------
// Função principal (main)
// -------------------------
int main() {
    // Declarando duas variáveis do tipo Carta
    Carta brasilia;
    Carta recife;

    // Preenchendo os dados da carta de Brasília
    strcpy(brasilia.estado, "Distrito Federal");
    strcpy(brasilia.codigo, "DF01");
    strcpy(brasilia.nome, "Brasília");
    brasilia.populacao = 3055149;
    brasilia.area = 5802.0;
    brasilia.pib = 273.5;
    brasilia.pontosTuristicos = 15;

    // Preenchendo os dados da carta de Recife
    strcpy(recife.estado, "Pernambuco");
    strcpy(recife.codigo, "PE01");
    strcpy(recife.nome, "Recife");
    recife.populacao = 1653461;
    recife.area = 218.5;
    recife.pib = 69.0;
    recife.pontosTuristicos = 10;

    // Calculando os indicadores das duas cidades
    calcularIndicadores(&brasilia);
    calcularIndicadores(&recife);

    // Comparando as duas cartas
    compararCartas(brasilia, recife);

    return 0; // Fim do programa
}
