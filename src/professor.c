
#include "professor.h"
#include "validacoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Professor professores[TAM_PROFESSOR];

int qtdProfessores = 0;

void cadastrarProfessores(Professor *professores)
{
    int indiceLivre = -1;

    for (int i = 0; i < TAM_PROFESSOR; i++)
    {
        if (professores[i].deletado == 1 || professores[i].matricula == 0)
        {
            indiceLivre = i;
            break;
        }
    }

    if (indiceLivre == -1)
    {
        printf("Limite de professores excedido!\n");
        return;
    }

    for (int i = indiceLivre; i < TAM_PROFESSOR; i++)
    {

        getchar();
        printf("Formulario\n");
        printf("\nNUMERO DA MATRICULA: %d", indiceLivre + 1);
        professores[i].matricula = i + 1;
        professores[i].deletado = 0;

        printf("\nNOME: ");
        fgets(professores[i].nome, sizeof(professores[i].nome), stdin);

        printf("DATA DE NASCIMENTO(DDMMAAAA): ");
        scanf(" %s", professores[i].dataNascimento);
        if (!verificarDataNascimento(professores[i].dataNascimento))
        {
            i--;
            continue;
        }

        printf("SEXO: ");
        scanf(" %c", &professores[i].sexo);

        char cpf[12];
        printf("CPF: ");
        scanf(" %s", cpf);
        if (!verificarCpf(cpf))
        {
            printf("CPF inválido!\n");
            i--;
            continue;
        }
        strcpy(professores[i].cpf, cpf);

        qtdProfessores++;

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
    for (int i = 0; i < qtdProfessores; i++)
    {
        printf("%d\n%s\n%s\n%c\n%s\n\n", professores[i].matricula, professores[i].nome,
               professores[i].dataNascimento, professores[i].sexo, professores[i].cpf);
    }
}

void atualizarProfessores(Professor *professores)
{
    int matricula;
    int opcao;

    printf("Digite a matricula do professor que deseja atualizar: ");
    scanf("%d", &matricula);

    for (int i = 0; i < TAM_PROFESSOR; i++)
    {
        if (professores[i].deletado == 0 && professores[i].matricula == matricula)
        {

            printf("\nDados atuais:\n");
            printf("Matricula: %d\n", professores[i].matricula);
            printf("Nome: %s", professores[i].nome);
            printf("Data de nascimento: %s\n", professores[i].dataNascimento);
            printf("Sexo: %c\n", professores[i].sexo);
            printf("CPF: %s\n\n", professores[i].cpf);

            printf("Qual informação deseja atualizar?\n");
            printf("1 - Nome\n");
            printf("2 - Sexo\n");
            printf("3 - Data de nascimento\n");
            printf("4 - CPF\n");

            scanf("%d", &opcao);

            switch (opcao)
            {

            case 1:
                printf("Digite o novo nome: ");
                getchar();
                fgets(professores[i].nome, sizeof(professores[i].nome), stdin);
                break;
            case 2:
                printf("Digite o novo sexo: ");
                scanf(" %c", &professores[i].sexo);
                break;
            case 3:
                printf("Digite a nova data de nascimento: ");
                scanf(" %s", professores[i].dataNascimento);
                break;
            case 4:
                printf("Digite o novo CPF: ");
                scanf(" %s", professores[i].cpf);
                break;
            default:
                printf("Opção inválida\n");
            }
            return;
        }
    }
    printf("Professor não encontrado\n");
}

void listarProfessores(Professor *professores)
{
    printf("Listagem de professores\n\n");
    for (int i = 0; i < TAM_PROFESSOR; i++)
    {
        if (professores[i].matricula != 0 && professores[i].deletado == 0)
        {
            printf("Matricula: %d\nNome: %s\nData de nascimento: %s\nSexo: %c\nCpf: "
                   "%s\n\n",
                   professores[i].matricula, professores[i].nome, professores[i].dataNascimento,
                   professores[i].sexo, professores[i].cpf);
        }
    }
}

void excluirProfessores(Professor *professores)
{
    int matricula;
    printf("Digite a matricula do professor que deseja excluir: ");
    scanf("%d", &matricula);

    for (int i = 0; i < TAM_PROFESSOR; i++)
    {
        if (professores[i].matricula == matricula && professores[i].deletado == 0)
        {
            professores[i].deletado = 1;
            if (qtdProfessores > 0)
                qtdProfessores--;
            printf("Professor excluido com sucesso\n");
            return;
        }
    }
    printf("Professor não encontrado\n");
}

void menuProfessor(void)
{
    int op;

    do
    {
        printf("Módulo Professor\n");
        printf("0 - Sair\n");
        printf("1 - Cadastrar professor\n");
        printf("2 - Atualizar professor\n");
        printf("3 - Listar professores\n");
        printf("4 - Excluir professor\n");
        scanf(" %d", &op);
        switch (op)
        {

        case 0:
            break;
        case 1:
            cadastrarProfessores(professores);
            break;
        case 2:
            atualizarProfessores(professores);
            break;
        case 3:
            listarProfessores(professores);
            break;
        case 4:
            excluirProfessores(professores);
            break;

        default:
            printf("Opção inválida!\n");
            break;
        }
    } while (op != 0);
}
