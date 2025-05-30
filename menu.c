#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void creditos(){
  printf("                #################################################\n");
  printf("                ## Trabalho de Algoritmos e Estrutura de Dados ##\n");
  printf("                #################################################\n\n");
  printf("                                    Professora\n");
  printf("                           Maria Adriana Vidigal de Lima\n\n");
  printf("                                      Alunos\n");
  printf("                            Amanda Resende Fernandes\n");
  printf("                              Vinicius A. de Souza\n\n");

  desenhar_bolo();

  sleep(1);
  printf("\n\n                      Pressione Enter para continuar...\n");
  getchar();
}

void imprimirComandosMenu(){
  printf("\n=== Gerenciar Receitas ===\n");
  printf("01 - Adicionar receita\n");
  printf("02 - Remover receita\n");
  printf("03 - Buscar receita\n");
  printf("04 - Exibir receitas\n");
  printf("05 - Favoritar receita\n");
  printf("06 - Listar receitas favoritas\n");
  printf("07 - Adicionar ingrediente a receita\n");
  printf("08 - Remover ingrediente de receita\n");
  printf("09 - Exibir ingredientes da receita\n");

  printf("\n=== Gerenciar Dispensa de Ingredientes ===\n");
  printf("10 - Adicionar ingrediente\n");
  printf("11 - Remover ingrediente\n");
  printf("12 - Buscar ingrediente\n");
  printf("13 - Exibir ingredientes\n");
  printf("14 - Marcar ingrediente como essencial\n");
  printf("15 - Listar ingredientes essenciais\n");
  printf("16 - Reordenar ingredientes\n");
  printf("17 - Renomear ingrediente\n");

  printf("\n0 - Sair\n");
}

void imprimirCabecalho()
{
  printf("###############################################\n");
  printf("###   Bem-vindo ao seu Livro de Receitas!   ###\n");
  printf("###############################################\n");
}

void desenhar_bolo(){
    printf("      *                                             *\n");
    printf("                                               *\n");
    printf("                    *\n");
    printf("                                  *\n");
    printf("                                                            *\n");
    printf("         *\n");
    printf("                                                  *\n");
    printf("             *\n");
    printf("                           *             *\n");
    printf("                                                     *\n");
    printf("      *                                                               *\n");
    printf("               *\n");
    printf("                               (             )\n");
    printf("                       )      (*)           (*)      (\n");
    printf("              *       (*)      |             |      (*)\n");
    printf("                       |      |~|           |~|      |          *\n");
    printf("                      |~|     | |           | |     |~|\n");
    printf("                      | |     | |           | |     | |\n");
    printf("                     ,| |a@@@@| |@@@@@@@@@@@| |@@@@a| |.\n");
    printf("                .,a@@@| |@@@@@| |@@@@@@@@@@@| |@@@@@| |@@@@a,.\n");
    printf("              ,a@@@@@@| |@@@@@@@@@@@@.@@@@@@@@@@@@@@| |@@@@@@@a,\n");
    printf("             a@@@@@@@@@@@@@@@@@@@@@' . `@@@@@@@@@@@@@@@@@@@@@@@@a\n");
    printf("             ;`@@@@@@@@@@@@@@@@@@'   .   `@@@@@@@@@@@@@@@@@@@@@';\n");
    printf("             ;@@@`@@@@@@@@@@@@@'     .     `@@@@@@@@@@@@@@@@'@@@;\n");
    printf("             ;@@@;,.aaaaaaaaaa       .       aaaaa,,aaaaaaa,;@@@;\n");
    printf("             ;;@;;;;@@@@@@@@;@      @.@      ;@@@;;;@@@@@@;;;;@@;\n");
    printf("             ;;;;;;;@@@@;@@;;@    @@ . @@    ;;@;;;;@@;@@@;;;;;;;\n");
    printf("             ;;;;;;;;@@;;;;;;;  @@   .   @@  ;;;;;;;;;;;@@;;;;@;;\n");
    printf("             ;;;;;;;;;;;;;;;;;@@     .     @@;;;;;;;;;;;;;;;;@@@;\n");
    printf("         ,%%%%%%;;;;;;;;@;;;;;;;;       .       ;;;;;;;;;;;;;;;;@@;;%%%%%%,\n");
    printf("      .%%%%%%%%%%%%;;;;;;;@@;;;;;;;;     ,%%%%%%,     ;;;;;;;;;;;;;;;;;;;;%%%%%%%%%%%%,\n");
    printf("     .%%%%%%%%%%%%%%;;;;;;;@@;;;;;;;;   ,%%%%%%%%%%%%%%,   ;;;;;;;;;;;;;;;;;;;;%%%%%%%%%%%%%%,\n");
    printf("     %%%%%%%%%%%%%%%%`;;;;;;;;;;;;;;;;  %%%%%%%%%%%%%%%%%%%%%%  ;;;;;;;;;;;;;;;;;;;'%%%%%%%%%%%%%%%%\n");
    printf("     %%%%%%%%%%%%%%%%%%%%%%%%`;;;;;;;;;;;;,%%%%%%%%%%%%%%%%%%%%%%%%%%,;;;;;;;;;;;;;;;'%%%%%%%%%%%%%%%%%%%%%%%%\n");
    printf("     `%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%,,,,,,,%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%,,,,,,,%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%'\n");
    printf("       `%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%'\n");
    printf("           `%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%'\n");
    printf("                  \"\"\"\"\"\"\"\"\"\"\"\"\"\"\"`,,,,,,,,,'\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\n");
    printf("                                 `%%%%%%%%%%%%%%'\n");
    printf("                                  `%%%%%%%%%%'\n");
    printf("                                    %%%%%%\n");
    printf("                                   %%%%%%%%\n");
    printf("                                .,%%%%%%%%%%%%%%,.\n");
    printf("                           ,%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%,\n");
}
