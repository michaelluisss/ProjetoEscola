#ifndef PROFESSOR_H
#define PROFESSOR_H

#define TAM 5

typedef struct
{
    int matricula;
    char nome[99];
    char sexo;
    char dataNascimento[99];
    char cpf[11];
    int deletado; // 0 para não deletado

}Professor;

void cadastrarProfessores(Professor *professores);
void listarProfessores(Professor *professores);
void atualizarProfessores(Professor *professores);
void excluirProfessores(Professor *professores);

void menuProfessor(void);


#endif 