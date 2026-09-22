#ifndef RELATORIOS_H
#define RELATORIOS_H

#include "disciplina.h"
#include "aluno.h"
#include "professor.h"


void listarDisciplinasSemAlunos(Disciplina *disciplinas, Professor *professores);
void listarAlunosPorSexo(Aluno *alunos);
void listarAlunosPorNome(Aluno *alunos);
void listarAlunosPorData(Aluno *alunos);


void menuRelatorios(void);

#endif 