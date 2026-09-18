#ifndef ALUNO_H
#define ALUNO_H

#define TAM_ALUNO 5

typedef struct
{
    int matricula;
    char nome[99];
    char sexo;
    char dataNascimento[99];
    char cpf[11];
    int deletado; // 0 para não deletado
    int disciplinas[4];
    int qtdDisciplinas;
}Aluno;

extern Aluno alunos[TAM_ALUNO];

void cadastrarAlunos(Aluno *alunos);
void listarAlunos(Aluno *alunos);
void atualizarAlunos(Aluno *alunos);
void excluirAlunos(Aluno *alunos);

void menuAluno(void);


#endif 