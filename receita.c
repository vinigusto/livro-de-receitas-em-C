#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "receita.h"
#include "ingrediente.h"

#define TEMPO_CARREGAMENTO 1

void criarLivroReceitasVazio(Receita** listaR)
{
    *listaR = NULL;
    //printf("Livro de receitas criado com sucesso!\n");
    return;
}

void adicionarReceita (Receita** listaR, char nome[], char instrucoes[]){
    Receita *novo = (Receita *) malloc (sizeof(Receita));
    if(novo == NULL){
        printf("Erro\n");
        return;
    }

    strcpy(novo->nome, nome);
    strcpy(novo->modoPreparo, instrucoes);
    novo->listaI = NULL;
    novo->favorita = -1; // -1 = não favoritada, 1 = favoritada
    novo->prox = NULL;

    if(*listaR == NULL)
    {
        *listaR = novo; // lista vazia
    }
    else
    {
        Receita *atual = *listaR;
        while(atual->prox != NULL)
        {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

void removerReceita(Receita** listaR, char nome[]){
    if (*listaR == NULL) {
        printf("Lista de receitas vazia\n");
        return;
    }
    Receita *atual = *listaR;
    Receita *anterior = NULL;

    while(atual != NULL && strcmp(atual->nome, nome) != 0){
        anterior = atual;
        atual = atual->prox;
    }
    if(atual == NULL){
        printf("Receita nao encontrada\n");
        return;
    }
    if(anterior == NULL){
        *listaR = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    Ingrediente *ingredienteAtual = atual->listaI;
    Ingrediente *proximoIngrediente;

    while (ingredienteAtual != NULL) {
        proximoIngrediente = ingredienteAtual->prox; // Salva o ponteiro para o próximo
        removerIngrediente(&(atual->listaI), ingredienteAtual->nome);
        ingredienteAtual = proximoIngrediente; // Move para o próximo ingrediente
    }
    atual->listaI = NULL;

    if (anterior == NULL) {
        *listaR = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
}

void buscarReceita(Receita** listaR, char nome[]){
    Receita *atual = *listaR;

    while(atual != NULL) {
        if(strcmp(atual->nome, nome) == 0){
            printf("Receita encontrada: %s\n", atual->nome);
            printf("Modo de preparo: %s\n", atual->modoPreparo);
            printf("Ingredientes:\n");
            exibirIngredientes(&(atual->listaI));  // Agora mostra os ingredientes
            printf("Favorita: %s\n", atual->favorita == 1 ? "Sim" : "Nao");
            printf("\n");
            return;
        }
        atual = atual->prox;
    }

    printf("Receita nao encontrada\n");
    printf("\n");

    return;
}

void exibirReceitas(Receita** listaR) {
    Receita *atual = *listaR;

    if(atual == NULL) {
        printf("Nenhuma receita cadastrada.\n");
        printf("\n");
        sleep(TEMPO_CARREGAMENTO);
        return;
    }

    int contador = 1;
    while(atual != NULL) {
        if(atual->favorita == 1) {
            printf("%d. * %s\n", contador, atual->nome);  // Estrela para favoritas
        } else {
            printf("%d.   %s\n", contador, atual->nome);  // Espaços para manter alinhamento
        }
        atual = atual->prox;
        contador++;
    }

    printf("-----------------------\n");
    printf("Total: %d receitas\n", contador-1);
    printf("\n");
    sleep(TEMPO_CARREGAMENTO);
}

void favoritarReceita(Receita** listaR, char nome[])
{
    if (*listaR == NULL) {
        printf("Lista de receitas vazia\n");
        printf("\n");
        sleep(3);
        return;
    }

    Receita *atual = *listaR;
    while(atual != NULL) {
        if(strcmp(atual->nome, nome) == 0) {
            atual->favorita *= (-1);  // Alterna entre -1 e 1
            if(atual->favorita == 1) {
                printf("Receita '%s' favoritada com sucesso!\n", nome);
            } else {
                printf("Receita '%s' desfavoritada com sucesso!\n", nome);
            }
            printf("\n");
            sleep(TEMPO_CARREGAMENTO);
            return;
        }
        atual = atual->prox;
    }
    printf("Receita '%s' nao encontrada\n", nome);
    printf("\n");
    sleep(TEMPO_CARREGAMENTO);
}

void listarReceitasFavoritas(Receita** listaR){
    Receita *atual = *listaR;

    if(listaR == NULL){
        printf("Lista de receitas vazia\n");
        printf("\n");
        sleep(TEMPO_CARREGAMENTO);
        return;
    }

    int contagemFavoritas = 0;
    while(atual != NULL){
        if(atual->favorita == 1){
            contagemFavoritas++;
        }
        atual = atual->prox;
    }

    if(contagemFavoritas > 0)
    {
        for(atual = *listaR; atual != NULL; atual = atual->prox)
        {
            if(atual->favorita == 1){
                printf("Receita: %s\n", atual->nome);
                printf("Modo de preparo: %s\n", atual->modoPreparo);
                printf("Ingredientes:\n");
                    exibirIngredientes(&(atual->listaI));
            }
            printf("\n");
        }
    }
    else
    {
        printf("Nenhuma receita favoritada\n");
    }
    printf("\n");
    sleep(TEMPO_CARREGAMENTO);
}

void adicionarIngredienteReceita(Receita** listaR, char nomeReceita[], char nomeIngrediente[], char unidade[], float qtd, int essencial) {
    if (*listaR == NULL) {
        printf("Lista de receitas vazia.\n");
        printf("\n");
        sleep(3);
        return;
    }

    Receita* atual = *listaR;
    while (atual != NULL && strcmp(atual->nome, nomeReceita) != 0) {
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Receita '%s' nao encontrada.\n", nomeReceita);
        printf("\n");
        sleep(TEMPO_CARREGAMENTO);
        return;
    }

    Ingrediente* ing = atual->listaI;
    while (ing != NULL) {
        if (strcmp(ing->nome, nomeIngrediente) == 0) {
            printf("Ingrediente '%s' ja existe na receita.\n", nomeIngrediente);
            printf("\n");
            sleep(TEMPO_CARREGAMENTO);
            return;
        }
        ing = ing->prox;
    }

    adicionarIngrediente(&(atual->listaI), nomeIngrediente, unidade, qtd, essencial, 2);
}

void removerIngredienteReceita(Receita** listaR, char nomeReceita[], char nomeIngrediente[]) {
    if (*listaR == NULL) {
        printf("Lista de receitas vazia.\n");
        printf("\n");
        sleep(TEMPO_CARREGAMENTO);
        return;
    }

    Receita* atual = *listaR;
    while (atual != NULL && strcmp(atual->nome, nomeReceita) != 0) {
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Receita '%s' não encontrada.\n", nomeReceita);
        printf("\n");
        sleep(3);
        return;
    }

    removerIngrediente(&(atual->listaI), nomeIngrediente);
}

void listarIngredientesReceita(Receita** listaR, char nomeReceita[]) {
    if (*listaR == NULL) {
        printf("Lista de receitas vazia.\n");
        printf("\n");
        sleep(TEMPO_CARREGAMENTO);
        return;
    }

    Receita* atual = *listaR;
    while (atual != NULL && strcmp(atual->nome, nomeReceita) != 0) {
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Receita '%s' nao encontrada.\n", nomeReceita);
        printf("\n");
        sleep(TEMPO_CARREGAMENTO);
        return;
    }

    printf("\nIngredientes da receita '%s':\n", nomeReceita);
    exibirIngredientes(&(atual->listaI));
}
