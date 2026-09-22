#include "relatorios.h"
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void listarDisciplinasSemAlunos(Disciplina *disciplinas, Professor *professores) //testar funçãos
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
        }
    }
}

void listarAlunosPorSexo(Aluno *alunos)
{
    char sexo;

    printf("Digite o sexo que deseja listar (M/F): ");
    scanf(" %c", &sexo);
    if (sexo == 'm')
    {
        sexo = 'M';
    }
    else if (sexo == 'f')
    {
        sexo = 'F';
    }

   
    if(sexo == 'M')
    {
        printf("Listagem de Alunos do sexo Masculino\n\n");
    }
    else if(sexo == 'F')
    {
        printf("Listagem de Alunos do sexo Feminino\n\n");
    }
    else
    {
        printf("Sexo inválido. Digite M ou F.\n");
        return;
    }
    

    for (int i = 0; i < TAM_ALUNO; i++)
    {
        if (alunos[i].deletado == 0 && alunos[i].sexo == sexo)
        {
            printf("Matricula: %d\nNome: %s\nSexo: %c\nData de Nascimento: %s\nCPF: %s\n\n",
                   alunos[i].matricula, alunos[i].nome, alunos[i].sexo, alunos[i].dataNascimento, alunos[i].cpf);
        }
    }
}  

void listarAlunosPorNome(Aluno *alunos)
{
    Aluno copia[99];
    Aluno temp;
    int i, j;

    for(i = 0; i < TAM_ALUNO; i++)
    {
        copia[i] = alunos[i];
    }

    printf("Lista Alfabética de Alunos:\n\n");
    
    for (i = 0; i < qtdAluno - 1; i++)
    {
        for(int j = 0; j < qtdAluno - 1; j++)
        {
            if(strcmp(copia[j].nome, copia[j+1].nome) > 0)
            {
                temp = copia[j];
                copia[j] = copia[j+1];
                copia[j+1] = temp;
            }
        }
    }

    for(i = 0; i < qtdAluno; i++)
    {
        printf("%s\n", copia[i].nome);
    }
}

int transformarData(char dataNascimento[]) //função para transformar a data em DDMMAAAA
{
    int dia = (dataNascimento[0] - '0') * 10 + (dataNascimento[1] - '0');

    int mes = (dataNascimento[2] - '0') * 10 + (dataNascimento[3] - '0');

    int ano = (dataNascimento[4] - '0') * 1000 + (dataNascimento[5] - '0') * 100 + (dataNascimento[6] - '0') * 10 + (dataNascimento[7] - '0');

    return ano * 10000 + mes * 100 + dia;
}

void listarAlunosPorData(Aluno *alunos)
{
    Aluno copia[99];
    Aluno temp;
    int i, j;

    for (i = 0; i < qtdAluno; i++)
    {
        copia[i] = alunos[i];
    }

    printf("Lista de Alunos por Data de Nascimento:\n\n");

    for (i = 0; i < qtdAluno - 1; i++)
    {
        for (j = 0; j < qtdAluno - 1 - i; j++)
        {
            if (transformarData(copia[j].dataNascimento) >
                transformarData(copia[j + 1].dataNascimento))
            {
                temp = copia[j];
                copia[j] = copia[j + 1];
                copia[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < qtdAluno; i++)
    {
        printf("Nome: %s", copia[i].nome);
        printf("Data de Nascimento: %s\n\n", copia[i].dataNascimento);
    }
}

void menuRelatorios(void)
{
    int op;

    do
    {
        printf("Módulo Relatorios\n");
        printf("0 - Sair\n");
        printf("1 - Listar Alunos\n");
        printf("2 - Listar Professores\n");
        printf("3 - Listar Disciplinas sem alunos\n");
        printf("4 - Listar Disciplinas com alunos\n");
        printf("5 - Listar Alunos por Sexo\n");
        printf("6 - Listar Alunos por Nome\n");
        printf("7 - Listar Alunos por Data de Nascimento");
        scanf(" %d", &op);
        switch (op)
        {

        case 0:
            break;
        case 1:
            listarAlunos(alunos);
            break;
        case 2:
            listarProfessores(professores);
            break;
        case 3:
            listarDisciplinasSemAlunos(disciplinas, professores);
            break;
        case 4:
            listarDisciplinasComAlunos(disciplinas, professores, alunos);
            break;
        case 5:
            listarAlunosPorSexo(alunos);    
            break;
        case 6:
            listarAlunosPorNome(alunos);
            break;
        case 7:
            listarAlunosPorData(alunos);
            break;

        default:
            printf("Opção inválida!\n");
            break;
        }
    } while (op != 0);
}