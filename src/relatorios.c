#include "relatorios.h"
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void listarDisciplinasSemAlunos(Disciplina *disciplinas, Professor *professores)
{
    printf("Listagem de Disciplinas\n\n");
    for (int i = 0; i < qtdDisciplina; i++)
    {
        if (disciplinas[i].nome[0] != '\0' && disciplinas[i].deletado == 0)
        {
            printf("Nome: %s\nCodigo: %s\nSemestre: %d\n",
                   disciplinas[i].nome, disciplinas[i].codigo, disciplinas[i].semestre);

            for (int j = 0; j < qtdProfessores; j++)
            {
                if (professores[j].deletado == 0 && professores[j].matricula == disciplinas[i].matriculaProfessor)
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

    if (sexo == 'M')
    {
        printf("Listagem de Alunos do sexo Masculino\n\n");
    }
    else if (sexo == 'F')
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

    for (i = 0; i < qtdAluno; i++)
    {
        copia[i] = alunos[i];
    }

    printf("Lista Alfabética de Alunos:\n\n");

    for (i = 0; i < qtdAluno - 1; i++)
    {
        for (int j = 0; j < qtdAluno - 1; j++)
        {
            if (strcmp(copia[j].nome, copia[j + 1].nome) > 0)
            {
                temp = copia[j];
                copia[j] = copia[j + 1];
                copia[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < qtdAluno; i++)
    {
        printf("%s\n", copia[i].nome);
    }
}

int transformarData(char dataNascimento[])
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

void listarProfessoresPorSexo(Professor *professores)
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

    if (sexo == 'M')
    {
        printf("Listagem de Professores do sexo Masculino\n\n");
    }
    else if (sexo == 'F')
    {
        printf("Listagem de Professores do sexo Feminino\n\n");
    }
    else
    {
        printf("Sexo inválido. Digite M ou F.\n");
        return;
    }

    for (int i = 0; i < TAM_PROFESSOR; i++)
    {
        if (professores[i].deletado == 0 && professores[i].sexo == sexo)
        {
            printf("Matricula: %d\nNome: %s\nSexo: %c\nData de Nascimento: %s\nCPF: %s\n\n",
                   professores[i].matricula, professores[i].nome, professores[i].sexo, professores[i].dataNascimento, professores[i].cpf);
        }
    }
}

void listarProfessoresPorNome(Professor *professores)
{
    Professor copia[99];
    Professor temp;
    int i, j;

    for (i = 0; i < qtdProfessores; i++)
    {
        copia[i] = professores[i];
    }

    printf("Lista Alfabética de Professores:\n\n");

    for (i = 0; i < qtdProfessores - 1; i++)
    {
        for (int j = 0; j < qtdProfessores - 1; j++)
        {
            if (strcmp(copia[j].nome, copia[j + 1].nome) > 0)
            {
                temp = copia[j];
                copia[j] = copia[j + 1];
                copia[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < qtdProfessores; i++)
    {
        printf("%s\n", copia[i].nome);
    }
}

void listarProfessoresPorData(Professor *professores)
{
    Professor copia[99];
    Professor temp;
    int i, j;

    for (i = 0; i < qtdProfessores; i++)
    {
        copia[i] = professores[i];
    }

    printf("Lista de Professores por Data de Nascimento:\n\n");

    for (i = 0; i < qtdProfessores - 1; i++)
    {
        for (j = 0; j < qtdProfessores - 1 - i; j++)
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

    for (i = 0; i < qtdProfessores; i++)
    {
        printf("Nome: %s", copia[i].nome);
        printf("Data de Nascimento: %s\n\n", copia[i].dataNascimento);
    }
}

void aniversariantesDoMes(Aluno *alunos, Professor *professores)
{
    int mes;

    printf("Voce deseja ver os aniversariantes de qual mes?");
    scanf("%d", &mes);
    if (mes < 1 || mes > 12)
    {
        printf("Mês inválido!\n");
        return;
    }

    printf("Aniversariantes do mes %d:\n\n", mes);

    printf("Alunos aniversariantes:\n\n");
    for (int i = 0; i < qtdAluno; i++)
    {
        if (alunos[i].deletado == 0)
        {
            int mesNascimento = (alunos[i].dataNascimento[2] - '0') * 10 + (alunos[i].dataNascimento[3] - '0');
            if (mesNascimento == mes)
            {
                printf("Nome: %sData de Nascimento: %.2s/%.2s/%.4s\n\n", alunos[i].nome, alunos[i].dataNascimento, alunos[i].dataNascimento + 2, alunos[i].dataNascimento + 4);
            }
        }
    }
    printf("Professores aniversariantes:\n");
    for (int i = 0; i < qtdProfessores; i++)
    {
        if (professores[i].deletado == 0)
        {
            int mesNascimento = (professores[i].dataNascimento[2] - '0') * 10 + (professores[i].dataNascimento[3] - '0');
            if (mesNascimento == mes)
            {
                printf("Nome: %sData de Nascimento: %.2s/%.2s/%.4s\n\n", professores[i].nome, professores[i].dataNascimento, professores[i].dataNascimento + 2, professores[i].dataNascimento + 4);
            }
        }
    }
}

void listarPessoasPorBusca(Aluno *alunos, Professor *professores)
{
    char busca[99];
    char buscaMinuscula[99];
    int encontrou = 0;

    printf("Digite a string de busca (minimo 3 letras): ");
    scanf(" %s", busca);

    if (strlen(busca) < 3)
    {
        printf("Digite pelo menos 3 letras.\n");
        return;
    }

    for (int i = 0; busca[i] != '\0'; i++)
    {
        buscaMinuscula[i] = tolower((unsigned char)busca[i]);
    }
    buscaMinuscula[strlen(busca)] = '\0';

    printf("Pessoas encontradas pela busca '%s':\n\n", busca);

    for (int i = 0; i < TAM_ALUNO; i++)
    {
        if (alunos[i].deletado == 0)
        {
            char nomeMinusculo[99];
            strcpy(nomeMinusculo, alunos[i].nome);
            for (int j = 0; nomeMinusculo[j] != '\0'; j++)
            {
                nomeMinusculo[j] = tolower((unsigned char)nomeMinusculo[j]);
            }

            if (strstr(nomeMinusculo, buscaMinuscula) != NULL)
            {
                printf("Aluno - Matricula: %d | Nome: %s\n", alunos[i].matricula, alunos[i].nome);
                encontrou = 1;
            }
        }
    }

    for (int i = 0; i < TAM_PROFESSOR; i++)
    {
        if (professores[i].deletado == 0)
        {
            char nomeMinusculo[99];
            strcpy(nomeMinusculo, professores[i].nome);
            for (int j = 0; nomeMinusculo[j] != '\0'; j++)
            {
                nomeMinusculo[j] = tolower((unsigned char)nomeMinusculo[j]);
            }

            if (strstr(nomeMinusculo, buscaMinuscula) != NULL)
            {
                printf("Professor - Matricula: %d | Nome: %s\n", professores[i].matricula, professores[i].nome);
                encontrou = 1;
            }
        }
    }

    if (!encontrou)
    {
        printf("Nenhuma pessoa encontrada com a busca informada.\n");
    }
}

void listarAlunosMenosDeTresDisciplinas(Aluno *alunos)
{
    int encontrou = 0;

    printf("Alunos matriculados em menos de 3 disciplinas:\n\n");

    for (int i = 0; i < TAM_ALUNO; i++)
    {
        if (alunos[i].deletado == 0 && alunos[i].qtdDisciplinasMatriculado < 3)
        {
            printf("Matricula: %d\nNome: %s\nDisciplinas matriculadas: %d\n\n",
                   alunos[i].matricula,
                   alunos[i].nome,
                   alunos[i].qtdDisciplinasMatriculado);
            encontrou = 1;
        }
    }

    if (!encontrou)
    {
        printf("Nenhum aluno encontrado com menos de 3 disciplinas.\n");
    }
}

void listarDisciplinasAcimaDe40Vagas(Disciplina *disciplinas, Professor *professores)
{
    int encontrou = 0;

    printf("Disciplinas que excedem 40 vagas:\n\n");

    for (int i = 0; i < qtdDisciplina; i++)
    {
        if (disciplinas[i].deletado == 0 && disciplinas[i].nome[0] != '\0' && disciplinas[i].qtdAlunoDisciplina > 40)
        {
            printf("Nome: %s\nCodigo: %s\nVagas ocupadas: %d\n",
                   disciplinas[i].nome,
                   disciplinas[i].codigo,
                   disciplinas[i].qtdAlunoDisciplina);

            for (int j = 0; j < qtdProfessores; j++)
            {
                if (professores[j].deletado == 0 && professores[j].matricula == disciplinas[i].matriculaProfessor)
                {
                    printf("Professor: %s\n\n", professores[j].nome);
                    break;
                }
            }
            encontrou = 1;
        }
    }

    if (!encontrou)
    {
        printf("Nenhuma disciplina excede 40 vagas.\n");
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
        printf("7 - Listar Alunos por Data de Nascimento\n");
        printf("8 - Listar Professores por Sexo\n");
        printf("9 - Listar Professores por Nome\n");
        printf("10 - Listar Professores por Data de Nascimento\n");
        printf("11 - Listar Aniversariantes do Mes\n");
        printf("12 - Buscar Pessoas por Nome\n");
        printf("13 - Listar Alunos com menos de 3 disciplinas\n");
        printf("14 - Listar Disciplinas acima de 40 vagas\n");
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
        case 8:
            listarProfessoresPorSexo(professores);
            break;
        case 9:
            listarProfessoresPorNome(professores);
            break;
        case 10:
            listarProfessoresPorData(professores);
            break;

        case 11:
            aniversariantesDoMes(alunos, professores);
            break;

        case 12:
            listarPessoasPorBusca(alunos, professores);
            break;

        case 13:
            listarAlunosMenosDeTresDisciplinas(alunos);
            break;

        case 14:
            listarDisciplinasAcimaDe40Vagas(disciplinas, professores);
            break;

        default:
            printf("Opção inválida!\n");
            break;
        }
    } while (op != 0);
}