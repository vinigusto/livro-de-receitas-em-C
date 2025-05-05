#include "ingrediente.h"
#include "receita.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEMPO_CARREGAMENTO 1

void adicionarIngrediente(Ingrediente** listaI, char nome[], char unidade[], float qtd, int essencial, int tempo_load) {
    Ingrediente *novo = (Ingrediente *) malloc (sizeof(Ingrediente));
    if(novo == NULL){
        printf("Erro ao alocar memoria para ingrediente.\n");
        return;
    }

    strcpy(novo->nome, nome);
    strcpy(novo->unidade, unidade);
    novo->qtd = qtd;
    novo->essencial = essencial;
    novo->prox = NULL;
    novo->ant = NULL;

    if(*listaI == NULL)
    {
        *listaI = novo; // lista vazia
    }
    else
    {
        Ingrediente *atual = *listaI;
        while(atual->prox != NULL)
        {
            atual = atual->prox;
        }
        atual->prox = novo;
        novo->ant = atual;
        //printf("Ingrediente '%s' adicionado com sucesso.\n", nome);
    }
    printf("\n");
    sleep(tempo_load);
}

void removerIngrediente(Ingrediente **listaI, char nome[])
{
    if (*listaI == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    Ingrediente* atual = *listaI;
    Ingrediente* anterior = NULL;

    // Percorre a lista até encontrar o ingrediente ou chegar ao final
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            if (anterior == NULL) { // Remoção do primeiro elemento
                *listaI = atual->prox;
                if (*listaI != NULL) {
                    (*listaI)->ant = NULL;
                }
            } else {
                anterior->prox = atual->prox; // Remoção de um elemento no meio ou final
                if (atual->prox != NULL) {
                    atual->prox->ant = anterior;
                }
            }
            free(atual);
            printf("Ingrediente removido com sucesso.\n");
            printf("\n");
            sleep(TEMPO_CARREGAMENTO);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    printf("\n");
    sleep(3);
    printf("Ingrediente '%s' nao encontrado.\n", nome);
}

void buscarIngrediente(Ingrediente** listaI, char nome[])
{
    Ingrediente* atual = *listaI;

    while (atual != NULL) // Percorre a lista até encontrar o ingrediente ou chegar ao final
    {
        if (strcmp(atual->nome, nome) == 0)
        {
            printf("Ingrediente encontrado:\n");
            printf("Nome: %s\n", atual->nome);
            printf("Unidade: %s\n", atual->unidade);
            printf("Quantidade: %.2f\n", atual->qtd);
            printf("Essencial: %s\n", atual->essencial ? "Sim" : "Nao");
            printf("\n");
            sleep(TEMPO_CARREGAMENTO);
            return;
        }
        atual = atual->prox;
    }
    printf("\n");
    printf("Ingrediente '%s' nao encontrado.\n", nome);
    sleep(TEMPO_CARREGAMENTO);
}

void exibirIngredientes(Ingrediente** listaI)
{
    Ingrediente* atual = *listaI;

    if (atual == NULL) {
        printf("Lista vazia.\n");
        printf("\n");
        sleep(TEMPO_CARREGAMENTO);
        return;
    }

    printf("Lista de Ingredientes:\n");
    int cont = 1;
    while (atual != NULL)
    {
        printf("%d. %s | Unidade: %s | Quantidade: %.2f | Essencial: %s\n",
               cont, atual->nome, atual->unidade, atual->qtd,
               atual->essencial ? "Sim" : "Nao");
        atual = atual->prox;
        cont++;
    }


}

void ingredienteEssencial(Ingrediente** listaI, char nome[])
{
    Ingrediente* atual = *listaI;

    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            atual->essencial = !atual->essencial; // Alterna entre -1 e 1
            printf("Ingrediente '%s' marcado como %s.\n",
                   nome, atual->essencial ? "essencial" : "nao essencial");
            printf("\n");
            sleep(TEMPO_CARREGAMENTO);
            return;
        }
        atual = atual->prox;
    }

    printf("Ingrediente '%s' nao encontrado.\n", nome);
}

void listarIngredientesEssenciais(Ingrediente** listaI)
{
    Ingrediente* atual = *listaI;
    int encontrados = 0;

    printf("Ingredientes Essenciais:\n");
    while (atual != NULL) {
        if (atual->essencial) {
            printf("Nome: %s | Unidade: %s | Quantidade: %.2f\n",
                   atual->nome, atual->unidade, atual->qtd);
            encontrados++;
        }
        atual = atual->prox;
    }

    if (encontrados == 0)
    {
        printf("Nenhum ingrediente essencial encontrado.\n");
    }
}

void reordenarIngredientes(Ingrediente** listaI){
    int trocado;
    Ingrediente* ptr1;
    Ingrediente* lptr = NULL;

    if (*listaI == NULL) {
        return;
    }

    do {
        trocado = 0;
        ptr1 = *listaI;

        while (ptr1->prox != lptr) {
            if (strcmp(ptr1->nome, ptr1->prox->nome) > 0) {
                // Troca os dados dos nós
                char tempNome[50];
                char tempUnidade[20];
                float tempQtd;
                int tempEssencial;

                // Copia dados do ptr1 para temp
                strcpy(tempNome, ptr1->nome);
                strcpy(tempUnidade, ptr1->unidade);
                tempQtd = ptr1->qtd;
                tempEssencial = ptr1->essencial;

                // Copia dados do próximo para ptr1
                strcpy(ptr1->nome, ptr1->prox->nome);
                strcpy(ptr1->unidade, ptr1->prox->unidade);
                ptr1->qtd = ptr1->prox->qtd;
                ptr1->essencial = ptr1->prox->essencial;

                // Copia dados de temp para próximo
                strcpy(ptr1->prox->nome, tempNome);
                strcpy(ptr1->prox->unidade, tempUnidade);
                ptr1->prox->qtd = tempQtd;
                ptr1->prox->essencial = tempEssencial;

                trocado = 1;
            }
            ptr1 = ptr1->prox;
        }
        lptr = ptr1;
    } while (trocado);
}

void renomearIngrediente(Ingrediente** listaI, char nome[], char novoNome[])
{
    Ingrediente* atual = *listaI;

    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            strcpy(atual->nome, novoNome);
            printf("Nome do ingrediente alterado de '%s' para '%s'.\n", nome, novoNome);
            printf("\n");
            sleep(TEMPO_CARREGAMENTO);
            return;
        }
        atual = atual->prox;
    }
    printf("\n");
    sleep(TEMPO_CARREGAMENTO);
    printf("Ingrediente '%s' nao encontrado.\n", nome);
}
