#include <stdio.h>
#include "aluno.h"
#include <stdlib.h>


void cadastrarAlunos(Aluno *alunos){
    for(int i = 1;i != (TAM+1); i++){
        printf("Formulario\n");
        printf("\nNUMERO DA MATRICULA: %d",i);
        alunos[i].matricula = i;

        printf("\nNOME: ");
        scanf(" %s",alunos[i].nome);

        printf("\nDATA DE NASCIMENTO: ");
        scanf(" %s",alunos[i].dataNascimento);

        printf("\nSEXO: ");
        scanf(" %c",&alunos[i].sexo);

        printf("\nCPF: ");
        scanf(" %s",alunos[i].cpf);

        
    }
    for(int i = 1;i != (TAM+1); i++){
        printf("%d\n%s\n%s\n%c\n%s\n\n",alunos[i].matricula,alunos[i].nome,alunos[i].dataNascimento,alunos[i].sexo,alunos[i].cpf);

    }
    
}
 void listarAlunos(Aluno *alunos){
    for(int i = 1;i != (TAM+1); i++){
        printf("listagem de alunos\n");
        printf("Matricula: %d\nNome: %s\nData de nascimento: %s\nSexo: %c\nCpf: %s\n\n",alunos[i].matricula,alunos[i].nome,alunos[i].dataNascimento,alunos[i].sexo,alunos[i].cpf);

    }
 }

