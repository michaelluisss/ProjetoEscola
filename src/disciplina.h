#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include "professor.h"
#include "aluno.h"
#define TAM_DISCIPLINA 8


typedef struct 
{
    char nome[99];
    char codigo[7];
    int semestre;
    int matriculaProfessor;
    int qtdProfessor;
    int qtdAluno;
    int matriculaAluno[TAM_ALUNO];
    int deletado;
    
}Disciplina;

extern Disciplina disciplinas[TAM_DISCIPLINA];
extern int qtdDisciplina;

void cadastrarDisciplinas(Disciplina *disciplinas, Professor *professores);
void listarDisciplinasComAlunos(Disciplina *disciplinas, Professor *professores, Aluno *alunos);
void atualizarDisciplinas(Disciplina *disciplinas, Professor *professores);
void excluirDisciplinas(Disciplina *disciplinas, Professor *professores);
void adicionarAlunoDisciplina(Disciplina *disciplinas, Aluno *alunos);
void removerAlunoDisciplina(Disciplina *disciplinas, Aluno *alunos);

void menuDisciplina(void);


#endif