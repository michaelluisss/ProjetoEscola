#ifndef ALUNO_H
#define ALUNO_H
#define TAM 2

typedef struct
{
    int matricula;
    char nome[99];
    char sexo;
    char dataNascimento[10];
    char cpf[11];

}Aluno;

void cadastrarAlunos(Aluno *alunos);
void listarAlunos(Aluno *alunos);
void atualizarAlunos(Aluno *alunos);

int menuAluno(int op);


#endif 