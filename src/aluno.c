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

        printf("%d, %s, %s, %c, %s\n",alunos[i].matricula,alunos[i].nome,alunos[i].dataNascimento,alunos[i].sexo,alunos[i].cpf);

    }

    
}


