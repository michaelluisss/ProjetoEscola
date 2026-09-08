#ifndef PROFESSOR_H
#define PROFESSOR_H

#define TAM_PROFESSOR 5

typedef struct
{
    int matricula;
    char nome[99];
    char sexo;
    char dataNascimento[99];
    char cpf[12];
    int deletado; // 0 para não deletado

}Professor;

extern Professor professores[TAM_PROFESSOR]; //avisa para outro arquivo.c q essa variavel existe mas q foi criada em outro arquivo, para poder ser utilizada

void cadastrarProfessores(Professor *professores);
void listarProfessores(Professor *professores);
void atualizarProfessores(Professor *professores);
void excluirProfessores(Professor *professores);

void menuProfessor(void);


#endif 