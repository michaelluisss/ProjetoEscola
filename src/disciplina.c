
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disciplina.h"
#include "professor.h"

Disciplina disciplinas[TAM_DISCIPLINA];

int qtdDisciplina = 0; 

void cadastrarDisciplinas(Disciplina *disciplinas, Professor *professores)
{

    for (int i = qtdDisciplina; i < TAM_DISCIPLINA; i++)
    {
        getchar();
        printf("Formulario\n");
        disciplinas[i].deletado = 0;

        printf("\nNOME: ");
        fgets(disciplinas[i].nome, sizeof(disciplinas[i].nome), stdin);

        printf("Codigo: ");
        scanf(" %s", disciplinas[i].codigo);

        printf("SEMESTRE: ");
        scanf(" %d", &disciplinas[i].semestre);

        printf("\nPROFESSORES CADASTRADOS:\n");

        for(int j = 0; j < TAM_PROFESSOR; j++)
        {
            if (professores[j].deletado == 0)
            {
                printf("Matricula:%d Nome:%s\n", professores[j].matricula, professores[j].nome);
            }
        }
        int encontrou = 0;

        while(encontrou == 0)
        {

           
            int disciplinasMatriculadas = 0;
            printf("Digite a quantidade de disciplinas o professor estar ministrando: ");
            scanf(" %d", &disciplinas[i].qtdProfessor);
            for(int j = 1;j<= disciplinas[i].qtdProfessor;j++){
                
                printf("Digite a matricula do professor n° %d: ",j);
                scanf(" %d", &disciplinas[i].matriculaProfessor);
            }

            for(int j = 0; j < TAM_PROFESSOR; j++)
            {
                if (professores[j].deletado == 0 && disciplinas[i].matriculaProfessor == professores[j].matricula)
                {
                    encontrou = 1;
                    qtdDisciplina++;
                    break;
                }
            }

            if(!encontrou)
            {
                printf("Matricula invalida, tente novamente.\n");
            }
        }


        char op;
        printf("\nDeseja continuar?(s/n)\n");
        scanf(" %c", &op);
        if (op == 's' || op == 'S')
        {
        }
        else if (op == 'n' || op == 'N')
        {
            return;
        }
        else
        {
            printf("opção Invalida");
        }
    }
    for (int i = 0; i < TAM_DISCIPLINA; i++)
    {
        printf("%s\n%s\n%d\n%d\n\n", disciplinas[i].nome, disciplinas[i].codigo, disciplinas[i].semestre, disciplinas[i].matriculaProfessor);
    }
}

void atualizarDisciplinas(Disciplina *disciplinas, Professor *professores)
{
    char codigo[7];
    int opcao;

    printf("Digite o código da disciplina que deseja atualizar: ");
    getchar();
    fgets(codigo, sizeof(codigo), stdin);
    codigo[strcspn(codigo, "\n")] = '\0';

    for (int i = 0; i < TAM_DISCIPLINA; i++)
    {
        if (strcmp(disciplinas[i].codigo, codigo) == 0)
        {

            printf("\nDados atuais:\n");
            printf("Código: %s\n", disciplinas[i].codigo);
            printf("Nome: %s", disciplinas[i].nome);
            printf("Semestre: %d\n", disciplinas[i].semestre);
            for (int j = 0; j < TAM_PROFESSOR; j++)
            {
                if (professores[j].matricula == disciplinas[i].matriculaProfessor)
                {
                    printf("Professor: %s\n", professores[j].nome);
                    break;
                }
            }

            printf("Qual informação deseja atualizar?\n");
            printf("1 - Nome\n");
            printf("2 - Semestre\n");
            printf("3 - Professor\n");

            scanf("%d", &opcao);

            switch (opcao)
            {

            case 1:
                printf("Digite o novo nome: ");
                getchar();
                fgets(disciplinas[i].nome, sizeof(disciplinas[i].nome), stdin);
                break;
            case 2:
                printf("Digite o novo semestre: ");
                scanf("%d", &disciplinas[i].semestre);
                break;
            case 3:
                printf("Digite a nova matrícula do professor: ");
                scanf("%d", &disciplinas[i].matriculaProfessor);
                break;
            default:
                printf("Opção inválida\n");
            }
            return;
        }
    }
    printf("Disciplina não encontrada\n");
}


void listarDisciplinas(Disciplina *disciplinas, Professor *professores) //testar funçãos
{
    printf("Listagem de Disciplinas\n\n");
    for (int i = 0; i < qtdDisciplina; i++)
    {
        if (disciplinas[i].nome[0] != '\0' && disciplinas[i].deletado == 0)
        {
            printf("Nome: %s\nCodigo: %s\nSemestre: %d\n",
                   disciplinas[i].nome, disciplinas[i].codigo, disciplinas[i].semestre);
             
            for (int j = 0; j < TAM_PROFESSOR; j++)
            {
                if (professores[j].matricula == disciplinas[i].matriculaProfessor)
                {
                    printf("Professor: %s\n", professores[j].nome);
                    break;
                }
            }
            for(int j = 0; j < disciplinas[i].qtdAluno; j++)
            {
                for(int k = 0; k < TAM_ALUNO; k++)
                {
                    if(alunos[k].matricula == disciplinas[i].matriculaAluno[j])
                    {
                        printf("Aluno: %s\n", alunos[k].nome);
                        break;
                    }
                }
            }
            
        }
    }
}

void excluirDisciplinas(Disciplina *disciplinas, Professor *professores)
{
    char codigo[7];
    printf("Digite o código da disciplina que deseja excluir: ");
    getchar();
    fgets(codigo, sizeof(codigo), stdin);
    codigo[strcspn(codigo, "\n")] = '\0';

    for (int i = 0; i < qtdDisciplina; i++)
    {
        if (strcmp(disciplinas[i].codigo, codigo) == 0)
        {
            for (int j = i; j < qtdDisciplina - 1; j++)
            {
                disciplinas[j] = disciplinas[j + 1];
            }
            qtdDisciplina--;
            disciplinas[qtdDisciplina].deletado = 1;

            printf("Disciplina excluída com sucesso\n");
            return;
        }
    }
    printf("Disciplina não encontrada\n");
}


void adicionarAlunoDisciplina(Disciplina *disciplinas, Aluno *alunos)
{
    char codigo[7];
    int matriculaAluno;

    printf("Digite o código da disciplina que deseja adicionar o aluno: ");
    getchar();
    fgets(codigo, sizeof(codigo), stdin);
    codigo[strcspn(codigo, "\n")] = '\0';

    for(int i = 0; i < qtdDisciplina; i++)
    {
        if (strcmp(disciplinas[i].codigo, codigo) == 0)
        {
            printf("Digite a matricula do aluno que deseja adicionar:");
            scanf("%d", &matriculaAluno);

            for(int j = 0; j < TAM_ALUNO; j++)
            {
                if(alunos[j].matricula == matriculaAluno && alunos[j].deletado == 0)
                {
                    disciplinas[i].matriculaAluno[disciplinas[i].qtdAluno] = matriculaAluno;
                    disciplinas[i].qtdAluno++;
                    printf("Aluno adicionado com sucesso!\n");
                    return;
                }
            }
            printf("Aluno não encontrado!\n");
            return;
        }
    }
    printf("Disciplina não encontrada!\n");
}

void removerAlunoDisciplina(Disciplina *disciplinas, Aluno *alunos)
{
    char codigo[7];
    int matriculaAluno;

    printf("Digite o código da disciplina que deseja remover o aluno: ");
    getchar();
    fgets(codigo, sizeof(codigo), stdin);
    codigo[strcspn(codigo, "\n")] = '\0';

    for(int i = 0; i < qtdDisciplina; i++)
    {
        if (strcmp(disciplinas[i].codigo, codigo) == 0)
        {
            printf("Digite a matricula do aluno que deseja remover:");
            scanf("%d", &matriculaAluno);

            for(int j = 0; j < disciplinas[i].qtdAluno; j++)
            {
                if(disciplinas[i].matriculaAluno[j] == matriculaAluno)
                {
                    for(int k = j; k < disciplinas[i].qtdAluno - 1; k++)
                    {
                        disciplinas[i].matriculaAluno[k] = disciplinas[i].matriculaAluno[k + 1];
                    }
                    disciplinas[i].qtdAluno--;
                    printf("Aluno removido com sucesso!\n");
                    return;
                }
            }
            printf("Aluno não encontrado na disciplina!\n");
            return;
        }
    }
    printf("Disciplina não encontrada!\n");
}




void menuDisciplina(void)
{
    int op;

    do  
    {
        printf("Módulo Disciplina\n");
        printf("0 - Sair\n");
        printf("1 - Cadastrar disciplina\n");
        printf("2 - Atualizar disciplina\n");
        printf("3 - Listar disciplina\n");
        printf("4 - Excluir disciplina\n");
        printf("5 - Adicionar aluno a disciplina\n");
        printf("6 - Remover aluno da disciplina\n");
        scanf(" %d", &op);
        switch (op)
        {

        case 0:
            break;
        case 1:
            cadastrarDisciplinas(disciplinas, professores);
            break;
        case 2:
            atualizarDisciplinas(disciplinas, professores);
            break;
        case 3:
            listarDisciplinas(disciplinas, professores);
            break;
        case 4:
            excluirDisciplinas(disciplinas, professores);
            break;
        case 5:
            adicionarAlunoDisciplina(disciplinas, alunos);
            break;
        case 6:
            removerAlunoDisciplina(disciplinas, alunos);
            break;

        default:
            printf("Opção inválida!\n");
            break;
        }
    } while (op != 0);
}