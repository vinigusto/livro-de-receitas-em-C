#ifndef RECEITA_H_
#define RECEITA_H_
#include "ingrediente.h"

typedef struct receita{
    char nome[50];
    char modoPreparo[100];
    Ingrediente *listaI;
    int favorita;
    struct receita *prox;
} Receita;

void criarLivroReceitasVazio(Receita** listaR);
void adicionarReceita (Receita** listaR, char nome[], char instrucoes[]); // ok
void removerReceita(Receita** listaR, char nome[]);
void buscarReceita(Receita** listaR, char nome[]); // ok
void exibirReceitas (Receita** listaR); // ok
void favoritarReceita(Receita** listaR, char nome[]); //ok
void listarReceitasFavoritas(Receita** listaR);

void listarIngredientesReceita(Receita** listaR, char nomeReceita[]);
void adicionarIngredienteReceita(Receita** listaR, char nomeReceita[], char nomeIngrediente[], char unidade[], float qtd, int essencial);
void removerIngredienteReceita(Receita** listaR, char nomeReceita[], char nomeIngrediente[]);

#endif