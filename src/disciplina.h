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
    int matriculaProfessor[TAM_PROFESSOR];
    int matriculaAluno[TAM_ALUNO];
    int deletado;
    
}Disciplina;

void cadastrarDisciplinas(Disciplina *disciplinas, Professor *professores);
void listarDisciplinas(Disciplina *disciplinas , Professor *professores);
void atualizarDisciplinas(Disciplina *disciplinas, Professor *professores);
void excluirDisciplinas(Disciplina *disciplinas, Professor *professores);

void menuDisciplina(void);


#endif