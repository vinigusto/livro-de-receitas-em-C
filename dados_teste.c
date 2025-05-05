#include "dados_teste.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TEMPO_CARREGAMENTO 1

void popularDadosTeste(Receita** listaR, Ingrediente** listaI)
{
    printf("=== Carregando dados de teste ===\n");

    // Adiciona ingredientes manualmente um por um
    adicionarIngrediente(listaI, "Farinha de trigo", "xicara", 2.0, 1, 0);
    adicionarIngrediente(listaI, "Acucar", "xicara", 1.0, 1, 0);
    adicionarIngrediente(listaI, "Ovos", "unidade", 3.0, 1, 0);
    adicionarIngrediente(listaI, "Leite", "ml", 200.0, 1, 0);
    adicionarIngrediente(listaI, "Fermento", "colher de cha", 1.0, 1, 0);
    adicionarIngrediente(listaI, "Sal", "pitada", 0.5, 0, 0);
    adicionarIngrediente(listaI, "Manteiga", "colher de sopa", 2.0, 1, 0);
    adicionarIngrediente(listaI, "Chocolate em po", "colher de sopa", 3.0, 0, 0);
    adicionarIngrediente(listaI, "Oleo", "colher de sopa", 2.0, 1, 0);
    adicionarIngrediente(listaI, "Canela", "colher de cha", 0.5, 0, 0);
    printf("\n10 ingredientes basicos adicionados\n");
    system("cls");

    adicionarReceita(listaR, "Bolo Simples", "Misture os secos. Adicione os liquidos. Asse por 40min.");
    Receita* atual = *listaR;
    while(atual != NULL && strcmp(atual->nome, "Bolo Simples") != 0) {
        atual = atual->prox;
    }
    if(atual != NULL) {
        adicionarIngrediente(&(atual->listaI), "Farinha de trigo", "xicara", 2.0, 1, 0);
        adicionarIngrediente(&(atual->listaI), "Acucar", "xicara", 1.0, 1, 0);
        adicionarIngrediente(&(atual->listaI), "Ovos", "unidade", 3.0, 1, 0);
        adicionarIngrediente(&(atual->listaI), "Leite", "ml", 200.0, 1, 0);
        adicionarIngrediente(&(atual->listaI), "Fermento", "colher de cha", 1.0, 1, 0);
        printf("- Bolo Simples com 5 ingredientes adicionado\n");
    }
    system("cls");

    adicionarReceita(listaR, "Panquecas", "Misture liquidos primeiro. Frite em frigideira quente.");
    atual = *listaR;
    while(atual != NULL && strcmp(atual->nome, "Panquecas") != 0) {
        atual = atual->prox;
    }
    if(atual != NULL) {
        adicionarIngrediente(&(atual->listaI), "Farinha de trigo", "xicara", 1.5, 1, 0);
        adicionarIngrediente(&(atual->listaI), "Ovos", "unidade", 2.0, 1, 0);
        adicionarIngrediente(&(atual->listaI), "Leite", "ml", 300.0, 1, 0);
        adicionarIngrediente(&(atual->listaI), "Manteiga", "colher de sopa", 1.0, 1, 0);
        printf("- Panquecas com 4 ingredientes (favorita) adicionada\n");
    }
    system("cls");

    adicionarReceita(listaR, "Chocolate Quente", "Aqueca o leite. Misture o chocolate. Adoce a gosto.");
    atual = *listaR;
    while(atual != NULL && strcmp(atual->nome, "Chocolate Quente") != 0) {
        atual = atual->prox;
    }
    if(atual != NULL) {
        adicionarIngrediente(&(atual->listaI), "Leite", "ml", 300.0, 1, 0);
        adicionarIngrediente(&(atual->listaI), "Chocolate em po", "colher de sopa", 3.0, 0, 0);
        adicionarIngrediente(&(atual->listaI), "Acucar", "colher de sopa", 2.0, 1, 0);
        printf("- Chocolate Quente com 3 ingredientes adicionado\n");
    }
    system("cls");
}
