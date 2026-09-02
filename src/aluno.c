#include <stdio.h>
#include "aluno.h"
#include <stdlib.h>



Aluno alunos[TAM];


void cadastrarAlunos(Aluno *alunos){
    for(int i = 0; i < TAM; i++){

        getchar();
        printf("Formulario\n");
        printf("\nNUMERO DA MATRICULA: %d",i+1);
        alunos[i].matricula = i+1;

        printf("\nNOME: ");
        fgets(alunos[i].nome,sizeof(alunos[i].nome),stdin);

        printf("\nDATA DE NASCIMENTO: ");
        scanf(" %s",alunos[i].dataNascimento);

        printf("\nSEXO: ");
        scanf(" %c",&alunos[i].sexo);

        printf("\nCPF: ");
        scanf(" %s",alunos[i].cpf);

        
    }
    for(int i = 0;i < TAM; i++){
        printf("%d\n%s\n%s\n%c\n%s\n\n",alunos[i].matricula,alunos[i].nome,alunos[i].dataNascimento,alunos[i].sexo,alunos[i].cpf);

    }
    
}

void atualizarAlunos(Aluno *alunos){
    int matricula;
    int opcao;
    
    printf("Digite a matricula do aluno que deseja atualizar: ");
    scanf("%d",&matricula);
    
    for(int i = 0; i < TAM; i++){
        if(alunos[i].matricula == matricula){
            printf("Qual informação deseja atualizar?\n");
            printf("1 - Nome\n");
            printf("2 - Sexo\n");
            printf("3 - Data de nascimento\n");
            printf("4 - CPF\n");

            scanf("%d", &opcao);

            switch(opcao){
                
                case 1:
                    printf("Digite o novo nome: ");
                    getchar();
                    fgets(alunos[i].nome,sizeof(alunos[i].nome),stdin);
                    break;
                case 2:
                    printf("Digite o novo sexo: ");
                    scanf(" %c",&alunos[i].sexo);
                    break;
                case 3:
                    printf("Digite a nova data de nascimento: ");
                    scanf(" %s",alunos[i].dataNascimento);
                    break;
                case 4:
                    printf("Digite o novo CPF: ");
                    scanf(" %s",alunos[i].cpf);
                    break;
                default:
                    printf("Opção inválida\n");
            }
            return;
        }
    }
    printf("Aluno não encontrado\n");
}

 void listarAlunos(Aluno *alunos){
    printf("Listagem de alunos\n\n");
    for(int i = 0; i < TAM; i++){
        printf("Matricula: %d\nNome: %s\nData de nascimento: %s\nSexo: %c\nCpf: %s\n\n",alunos[i].matricula,alunos[i].nome,alunos[i].dataNascimento,alunos[i].sexo,alunos[i].cpf);
    }
 }

void menuAluno(void){
    int op;
    
    do{
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
        case 2:
        atualizarAlunos(alunos);
        break;
        case  3:
        listarAlunos(alunos);
        break;
        
        default:
        printf("Opção inválida!\n");
        break;
        }
    }while(op != 0);
}
