#include <stdio.h>
#include "aluno.h"


int main(void) {
  Aluno alunos[TAM];

  int opcao;

  int sair = 0; //falso

  while (!sair){
    printf("Projeto Escola\n");
    printf("0 - Sair\n");
    printf("1 - Aluno\n");
    printf("2 - Professor\n");
    printf("3 - Disciplina\n");
  
    scanf("%d", &opcao);

    switch (opcao){


      case 0:{
        sair = 1;
        break;
      }
      case 1:{
        printf("Módulo Aluno\n");
        int op = 0;
        printf("0 - Sair\n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Atualizar aluno\n");
        printf("3 - Listar aluno\n");
        printf("4 - Excluir aluno\n");
        scanf("%d",&op);
        switch (op)
        {
          case  0:
          sair = 0;
          break;
          case  1:
          cadastrarAlunos(alunos);
          break;
        
        default:
          break;
        }

        break;
      }
      case 2:{
        printf("Módulo Professor\n");
        break;
      }
      case 3:{
        printf("Módulo Disciplina\n");
        break;
      }
      default:{
        printf("Opção Inválida\n");  
      }
    }
  }
  
  return 0;
}