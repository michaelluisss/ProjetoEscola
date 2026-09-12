#include "aluno.h"
#include "professor.h"
#include "disciplina.h"
#include "validacoes.h"
#include <stdio.h>
#include <string.h>

extern Aluno alunos[TAM_ALUNO];
extern Professor professores[TAM_PROFESSOR];
extern Disciplina disciplinas[TAM_DISCIPLINA];
extern int qtdDisciplina;

static void popularDadosTeste(void);

int main(void)
{

  int opcao;

  // Temporário: remover antes do commit final.
  popularDadosTeste();

  int sair = 0; // falso

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
      menuDisciplina();
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

static void popularDadosTeste(void)
{
  // Bloco temporário para facilitar testes. Remover antes do commit final.
  memset(alunos, 0, sizeof(alunos));
  memset(professores, 0, sizeof(professores));
  memset(disciplinas, 0, sizeof(disciplinas));
  qtdDisciplina = 0;

  alunos[0].matricula = 1;
  snprintf(alunos[0].nome, sizeof(alunos[0].nome), "%s", "Maria Silva");
  alunos[0].sexo = 'F';
  snprintf(alunos[0].dataNascimento, sizeof(alunos[0].dataNascimento), "%s", "01011999");
  snprintf(alunos[0].cpf, sizeof(alunos[0].cpf), "%s", "1234567890");
  alunos[0].deletado = 0;

  alunos[1].matricula = 2;
  snprintf(alunos[1].nome, sizeof(alunos[1].nome), "%s", "Joao Pereira");
  alunos[1].sexo = 'M';
  snprintf(alunos[1].dataNascimento, sizeof(alunos[1].dataNascimento), "%s", "02021998");
  snprintf(alunos[1].cpf, sizeof(alunos[1].cpf), "%s", "9876543210");
  alunos[1].deletado = 0;

  alunos[2].matricula = 3;
  snprintf(alunos[2].nome, sizeof(alunos[2].nome), "%s", "Ana Souza");
  alunos[2].sexo = 'F';
  snprintf(alunos[2].dataNascimento, sizeof(alunos[2].dataNascimento), "%s", "03032000");
  snprintf(alunos[2].cpf, sizeof(alunos[2].cpf), "%s", "1112223334");
  alunos[2].deletado = 0;

  professores[0].matricula = 1;
  snprintf(professores[0].nome, sizeof(professores[0].nome), "%s", "Carlos Rocha");
  professores[0].sexo = 'M';
  snprintf(professores[0].dataNascimento, sizeof(professores[0].dataNascimento), "%s", "15051980");
  snprintf(professores[0].cpf, sizeof(professores[0].cpf), "%s", "12345678901");
  professores[0].deletado = 0;

  professores[1].matricula = 2;
  snprintf(professores[1].nome, sizeof(professores[1].nome), "%s", "Patricia Lima");
  professores[1].sexo = 'F';
  snprintf(professores[1].dataNascimento, sizeof(professores[1].dataNascimento), "%s", "21061985");
  snprintf(professores[1].cpf, sizeof(professores[1].cpf), "%s", "10987654321");
  professores[1].deletado = 0;

  professores[2].matricula = 3;
  snprintf(professores[2].nome, sizeof(professores[2].nome), "%s", "Paulo Costa");
  professores[2].sexo = 'M';
  snprintf(professores[2].dataNascimento, sizeof(professores[2].dataNascimento), "%s", "05021976");
  snprintf(professores[2].cpf, sizeof(professores[2].cpf), "%s", "22233344455");
  professores[2].deletado = 0;

  snprintf(disciplinas[0].nome, sizeof(disciplinas[0].nome), "%s", "Programacao I");
  snprintf(disciplinas[0].codigo, sizeof(disciplinas[0].codigo), "%s", "PROG1");
  disciplinas[0].semestre = 1;
  disciplinas[0].matriculaProfessor = 1;
  disciplinas[0].deletado = 0;
  qtdDisciplina++;

  snprintf(disciplinas[1].nome, sizeof(disciplinas[1].nome), "%s", "Banco de Dados");
  snprintf(disciplinas[1].codigo, sizeof(disciplinas[1].codigo), "%s", "BD001");
  disciplinas[1].semestre = 3;
  disciplinas[1].matriculaProfessor = 2;
  disciplinas[1].deletado = 0;
  qtdDisciplina++;

  snprintf(disciplinas[2].nome, sizeof(disciplinas[2].nome), "%s", "Algoritmos");
  snprintf(disciplinas[2].codigo, sizeof(disciplinas[2].codigo), "%s", "ALG01");
  disciplinas[2].semestre = 2;
  disciplinas[2].matriculaProfessor = 3;
  disciplinas[2].deletado = 0;
  qtdDisciplina++;
}