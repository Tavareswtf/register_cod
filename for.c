#include <stdio.h>
#include <string.h>

// Definindo a estrutura para os itens
struct Item {
    int codigo;
    char nome[50];
    float preco;
};

int main() {
    int numItens;

    printf("Quantos itens você deseja inserir? ");
    scanf("%d", &numItens);

    // Criando um array de itens com base no número fornecido pelo usuário
    struct Item itens[numItens];

    // Inicializando o array de códigos para verificar duplicatas
    int codigosInseridos[numItens];
    memset(codigosInseridos, 0, sizeof(codigosInseridos));

    // Preenchendo os detalhes dos itens
    for (int i = 0; i < numItens; i++) {
        printf("\nItem %d:\n", i + 1);
        printf("Código: ");
        scanf("%d", &itens[i].codigo);

        // Verificando se o código já foi inserido
        if (codigosInseridos[itens[i].codigo] == 1) {
            printf("Código já inserido. Insira um código diferente.\n");
            i--; // Volta para o item anterior
            continue;
        }
        codigosInseridos[itens[i].codigo] = 1;

        printf("Nome: ");
        scanf("%s", itens[i].nome);

        printf("Preço: ");
        scanf("%f", &itens[i].preco);
    }

    // Imprimindo a lista de itens
    printf("\nLista de Itens:\n");
    for (int i = 0; i < numItens; i++) {
        printf("Código: %d, Nome: %s, Preço: %.2f\n", itens[i].codigo, itens[i].nome, itens[i].preco);
    }

    // Calculando o total dos preços
    float totalPreco = 0;
    for (int i = 0; i < numItens; i++) {
        totalPreco += itens[i].preco;
    }
    printf("\nTotal dos preços: %.2f\n", totalPreco);

    return 0;
}
