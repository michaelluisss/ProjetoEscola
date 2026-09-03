#ifndef ALUNO_H
#define ALUNO_H
#define TAM 5

typedef struct
{
    int matricula;
    char nome[99];
    char sexo;
    char dataNascimento[99];
    char cpf[11];
    int deletado; // 0 para não deletado

}Aluno;

int verificarDataNascimento(char dataNascimento[]);
void cadastrarAlunos(Aluno *alunos);
void listarAlunos(Aluno *alunos);
void atualizarAlunos(Aluno *alunos);
void excluirAlunos(Aluno *alunos);

void menuAluno(void);


#endif 