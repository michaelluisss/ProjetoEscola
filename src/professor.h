#ifndef PROFESSOR_H
#define PROFESSOR_H

#define TAM_PROFESSOR 5
#define MAX_DISCIPLINA 4

typedef struct Professor
{
    int matricula;
    char nome[99];
    char sexo;
    char dataNascimento[99];
    char cpf[12];
    int deletado; // 0 para não deletado
    int disciplinas[4];
    int qtdDisciplinas;
}Professor;

extern Professor professores[TAM_PROFESSOR]; //avisa para outro arquivo.c q essa variavel existe mas q foi criada em outro arquivo, para poder ser utilizada
extern int qtdProfessores;

void cadastrarProfessores(Professor *professores);
void listarProfessores(Professor *professores);
void atualizarProfessores(Professor *professores);
void excluirProfessores(Professor *professores);

void menuProfessor(void);


#endif 