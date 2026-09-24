#include "aluno.h"
#include "professor.h"
#include "disciplina.h"
#include "validacoes.h"
#include "relatorios.h"
#include <stdio.h>
#include <string.h>

extern Aluno alunos[TAM_ALUNO];
extern Professor professores[TAM_PROFESSOR];
extern Disciplina disciplinas[TAM_DISCIPLINA];
extern int qtdDisciplina;

int main(void)
{

  int opcao;

  int sair = 0;

  while (!sair)
  {
    printf("Projeto Escola\n");
    printf("0 - Sair\n");
    printf("1 - Aluno\n");
    printf("2 - Professor\n");
    printf("3 - Disciplina\n");
    printf("4 - Relatorios\n");

    scanf(" %d", &opcao);

    switch (opcao)
    {

    case 0:
    {
      sair = 1;
      break;
    }
    case 1:
    {
      menuAluno();
      break;
    }
    case 2:
    {
      menuProfessor();
      break;
    }
    case 3:
    {
      menuDisciplina();
      break;
    }
    case 4:
    {
      menuRelatorios();
      break;
    }
    default:
    {
      printf("Opção Inválida\n");
    }
    }
  }
  return 0;
}
