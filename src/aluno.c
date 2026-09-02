#include <stdio.h>
#include "aluno.h"
#include <stdlib.h>



Aluno alunos[TAM];


void cadastrarAlunos(Aluno *alunos){
    for(int i = 1;i != (TAM+1); i++){

        getchar();
        printf("Formulario\n");
        printf("\nNUMERO DA MATRICULA: %d",i);
        alunos[i].matricula = i;

        printf("\nNOME: ");
        fgets(alunos[i].nome,sizeof(alunos[i].nome),stdin);

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
    printf("Listagem de alunos\n\n");
    int i = 1;
    while(alunos[i].matricula > 0 && alunos[i].matricula<=TAM){
        printf("Matricula: %d\nNome: %s\nData de nascimento: %s\nSexo: %c\nCpf: %s\n\n",alunos[i].matricula,alunos[i].nome,alunos[i].dataNascimento,alunos[i].sexo,alunos[i].cpf);
        i++;
    }

   
 }
int menuAluno(int op){
    printf("Módulo Aluno\n");
    printf("0 - Sair\n");
    printf("1 - Cadastrar aluno\n");
    printf("2 - Atualizar aluno\n");
    printf("3 - Listar aluno\n");
    printf("4 - Excluir aluno\n");
    scanf(" %d",&op);
    switch (op)
    {
    case  0:
    
    break;
    case  1:
    cadastrarAlunos(alunos);
    break;
    case  3:
    listarAlunos(alunos);
    break;
    
    default:
    break;
    }
    return op;
}
