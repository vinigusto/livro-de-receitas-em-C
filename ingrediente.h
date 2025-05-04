#ifndef INGREDIENTE_H_
#define INGREDIENTE_H_

typedef struct ingrediente{
    char nome[50];
    char unidade[20];
    float qtd;
    int essencial;
    struct ingrediente *prox;
    struct ingrediente *ant;
} Ingrediente;

void adicionarIngrediente(Ingrediente** listaI, char nome[], char unidade[], float qtd, int essencial, int tempo_load);
void removerIngrediente(Ingrediente **listaI, char nome[]);
void buscarIngrediente(Ingrediente** listaI, char nome[]);
void exibirIngredientes(Ingrediente** listaI);
void ingredienteEssencial(Ingrediente** listaI, char nome[]); // marca e desmarca
void listarIngredientesEssenciais(Ingrediente** listaI);
void reordenarIngredientes(Ingrediente** listaI); 
void renomearIngrediente(Ingrediente** listaI, char nome[], char novoNome[]);

#endif