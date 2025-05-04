#include "dados_teste.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TEMPO_CARREGAMENTO 1

void popularDadosTeste(Receita** listaR, Ingrediente** listaI)
{
    printf("=== Carregando dados de teste ===\n");

    // Adiciona ingredientes manualmente um por um
    adicionarIngrediente(listaI, "Farinha de trigo", "xícara", 2.0, 1, 0);
    adicionarIngrediente(listaI, "Açúcar", "xícara", 1.0, 1, 0);
    adicionarIngrediente(listaI, "Ovos", "unidade", 3.0, 1, 0);
    adicionarIngrediente(listaI, "Leite", "ml", 200.0, 1, 0);
    adicionarIngrediente(listaI, "Fermento", "colher de chá", 1.0, 1, 0);
    adicionarIngrediente(listaI, "Sal", "pitada", 0.5, 0, 0);
    adicionarIngrediente(listaI, "Manteiga", "colher de sopa", 2.0, 1, 0);
    adicionarIngrediente(listaI, "Chocolate em pó", "colher de sopa", 3.0, 0, 0);
    adicionarIngrediente(listaI, "Óleo", "colher de sopa", 2.0, 1, 0);
    adicionarIngrediente(listaI, "Canela", "colher de chá", 0.5, 0, 0);
    
    printf("\n10 ingredientes básicos adicionados\n");

    adicionarReceita(listaR, "Bolo Simples", "Misture os secos. Adicione os líquidos. Asse por 40min.");
    Receita* atual = *listaR;
    while(atual != NULL && strcmp(atual->nome, "Bolo Simples") != 0) {
        atual = atual->prox;
    }
    if(atual != NULL) {
        adicionarIngrediente(&(atual->listaI), "Farinha de trigo", "xícara", 2.0, 1, 0);
        adicionarIngrediente(&(atual->listaI), "Açúcar", "xícara", 1.0, 1, 0);
        adicionarIngrediente(&(atual->listaI), "Ovos", "unidade", 3.0, 1, 0);
        adicionarIngrediente(&(atual->listaI), "Leite", "ml", 200.0, 1, 0);
        adicionarIngrediente(&(atual->listaI), "Fermento", "colher de chá", 1.0, 1, 0);
        printf("- Bolo Simples com 5 ingredientes adicionado\n");
    }

    adicionarReceita(listaR, "Panquecas", "Misture líquidos primeiro. Frite em frigideira quente.");
    atual = *listaR;
    while(atual != NULL && strcmp(atual->nome, "Panquecas") != 0) {
        atual = atual->prox;
    }
    if(atual != NULL) {
        adicionarIngrediente(&(atual->listaI), "Farinha de trigo", "xícara", 1.5, 1, 0);
        adicionarIngrediente(&(atual->listaI), "Ovos", "unidade", 2.0, 1, 0);
        adicionarIngrediente(&(atual->listaI), "Leite", "ml", 300.0, 1, 0);
        adicionarIngrediente(&(atual->listaI), "Manteiga", "colher de sopa", 1.0, 1, 0);
        printf("- Panquecas com 4 ingredientes (favorita) adicionada\n");
    }

    adicionarReceita(listaR, "Chocolate Quente", "Aqueça o leite. Misture o chocolate. Adoce a gosto.");
    atual = *listaR;
    while(atual != NULL && strcmp(atual->nome, "Chocolate Quente") != 0) {
        atual = atual->prox;
    }
    if(atual != NULL) {
        adicionarIngrediente(&(atual->listaI), "Leite", "ml", 300.0, 1, 0);
        adicionarIngrediente(&(atual->listaI), "Chocolate em pó", "colher de sopa", 3.0, 0, 0);
        adicionarIngrediente(&(atual->listaI), "Açúcar", "colher de sopa", 2.0, 1, 0);
        printf("- Chocolate Quente com 3 ingredientes adicionado\n");
    }
    printf("\n=== Total: 3 receitas adicionadas ===\n\n");

    system("clear");
}
