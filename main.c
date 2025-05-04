//#include <system.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ingrediente.h"
#include "menu.h"
#include "receita.h"
#include "dados_teste.h"

int main() {
    creditos();
    Receita *listaReceitas = NULL;
    Ingrediente* listaIngredientes = NULL;

    criarLivroReceitasVazio(&listaReceitas);
    popularDadosTeste(&listaReceitas, &listaIngredientes);

    int op = -1;
    char nome[50];
    char novoNome[50];
    char nomeIngrediente[50];
    char instrucoes[100];
    char unidade[20];
    float qtd;
    int essencial;


    do {
        imprimirCabecalho();
        imprimirComandosMenu();
        printf("Escolha uma opção: ");

        // Ler a opção
        if (scanf("%d", &op) != 1) {
            limparBuffer();
            op = -1; // Forçar opção inválida
        }
        
        limparBuffer();
        printf("\n");
        
        switch (op) {
            case 1: // Adicionar receita
                printf("\n");
                printf("=== Adicionar Receita ===\n");
                printf("Digite o nome da receita: ");
                scanf(" %49[^\n]", nome);
                limparBuffer();
                printf("Digite o modo de preparo: ");
                scanf(" %99[^\n]", instrucoes);
                adicionarReceita(&listaReceitas, nome, instrucoes);
                break;

            case 2: // Remover receita
                printf("\n");
                printf("=== Remover Receita ===\n");
                printf("Digite o nome da receita: ");
                scanf(" %49[^\n]", nome);
                removerReceita(&listaReceitas, nome);
                break;

            case 3: // Buscar receita
                printf("\n");
                printf("=== Buscar Receita ===\n");
                printf("Digite o nome da receita: ");
                scanf(" %49[^\n]", nome);
                buscarReceita(&listaReceitas, nome);
                break;

            case 4: // Exibir receitas
                printf("\n");
                printf("=== Lista de Receitas ===\n");
                exibirReceitas(&listaReceitas);
                break;

            case 5: // Favoritar receita
                printf("\n");
                printf("=== Favoritar Receita ===\n");
                exibirReceitas(&listaReceitas);
                printf("Digite o nome da receita: ");
                scanf(" %49[^\n]", nome);
                favoritarReceita(&listaReceitas, nome);
                break;

            case 6: // Listar favoritas
                printf("\n");
                printf("=== Lista de Receitas Favoritas ===\n");
                listarReceitasFavoritas(&listaReceitas);
                break;

            case 7: // Adicionar ingrediente a receita
                printf("\n=== Adicionar Ingrediente a Receita ===\n");
                exibirReceitas(&listaReceitas);
                printf("Digite o nome da receita: ");
                scanf(" %49[^\n]", nome);
                limparBuffer();
                printf("Digite o nome do ingrediente: ");
                scanf(" %49[^\n]", nomeIngrediente);
                printf("Digite a unidade de medida: ");
                scanf(" %19[^\n]", unidade);
                printf("Digite a quantidade: ");
                scanf("%f", &qtd);
                printf("É essencial? (1-Sim / 0-Não): ");
                scanf("%d", &essencial);
                adicionarIngredienteReceita(&listaReceitas, nome, nomeIngrediente, unidade, qtd, essencial);
                break;

            case 8: // Remover ingrediente de receita
                printf("\n=== Remover Ingrediente de Receita ===\n");
                exibirReceitas(&listaReceitas);
                printf("Digite o nome da receita: ");
                scanf(" %49[^\n]", nome);
                limparBuffer();
                printf("Digite o nome do ingrediente: ");
                scanf(" %49[^\n]", nomeIngrediente);
                removerIngredienteReceita(&listaReceitas, nome, nomeIngrediente);
                break;

            case 9: // Listar ingredientes de receita
                printf("\n=== Listar Ingredientes de Receita ===\n");
                exibirReceitas(&listaReceitas);
                printf("Digite o nome da receita: ");
                scanf(" %49[^\n]", nome);
                limparBuffer();
                listarIngredientesReceita(&listaReceitas, nome);
                break;

            case 10: // Adicionar ingrediente
                printf("Digite o nome do ingrediente: ");
                scanf(" %49[^\n]", nome);
                printf("Digite a unidade de medida: ");
                scanf(" %19[^\n]", unidade);
                printf("Digite a quantidade: ");
                scanf("%f", &qtd);
                printf("É essencial? (1-Sim / 0-Não): ");
                scanf("%d", &essencial);
                adicionarIngrediente(&listaIngredientes, nome, unidade, qtd, essencial, 2);
                break;

            case 11: // Remover ingrediente
                printf("\n");
                printf("=== Remover Ingrediente ===\n");
                printf("Digite o nome do ingrediente: ");
                scanf(" %49[^\n]", nome);
                removerIngrediente(&listaIngredientes, nome);
                break;

            case 12: // Buscar ingrediente
                printf("\n");
                printf("=== Buscar Ingrediente ===\n");
                printf("Digite o nome do ingrediente: ");
                scanf(" %49[^\n]", nome);
                buscarIngrediente(&listaIngredientes, nome);
                break;

            case 13: // Exibir ingredientes
                printf("\n");
                printf("=== Lista de Ingredientes ===\n");
                exibirIngredientes(&listaIngredientes);
                break;

            case 14: // Marcar ingrediente essencial
                printf("\n");
                printf("=== Marcar Ingrediente como Essencial ===\n");
                printf("Digite o nome do ingrediente: ");
                scanf(" %49[^\n]", nome);
                ingredienteEssencial(&listaIngredientes, nome);
                break;

            case 15: // Listar essenciais
                printf("\n");
                printf("=== Lista de Ingredientes Essenciais ===\n");
                listarIngredientesEssenciais(&listaIngredientes);
                break;

            case 16: // Reordenar ingredientes
                printf("\n");
                printf("=== Reordenar Ingredientes ===\n");
                reordenarIngredientes(&listaIngredientes);
                printf("Ingredientes reordenados alfabeticamente!\n");
                break;

            case 17: // Renomear ingrediente
                printf("\n");
                printf("=== Renomear Ingrediente ===\n");
                printf("Digite o nome atual do ingrediente: ");
                scanf(" %49[^\n]", nome);
                printf("Digite o novo nome: ");
                scanf(" %49[^\n]", novoNome);
                renomearIngrediente(&listaIngredientes, nome, novoNome);
                break;

            case 0: // Sair
                printf("\n");
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida!\n");
                break;
        }
        
        printf("\nPressione Enter para continuar...");
        getchar();
        printf("\e[1;1H\e[2J");
        system("clear");
        
    } while (op != 0);

    printf("\nObrigado por usar o nosso Livro de Receitas!\n");
    return 0;
}