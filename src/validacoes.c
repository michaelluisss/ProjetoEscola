#include "validacoes.h"
#include <stdio.h>
#include <string.h>






int verificarCpf(char *cpf)
{
    int resultado = 0;
    if (strlen(cpf) != 11)
    {
        return resultado;
    }
    int todosIguais = 1;
    for (int i = 1; i < 11; i++)
    {
        if (cpf[i] != cpf[0])
        {
            todosIguais = 0;
            break;
        }
    }
    if (todosIguais)
    {
        return resultado;
    }

    int somatorio = 0;
    int digito = 0;

    for (int i = 10; i >= 2; i--)
    {
        somatorio += (cpf[digito] - '0') * i;
        digito++;
    }

    int digVerificador = 11 - (somatorio % 11);
    if (((digVerificador >= 10) && (cpf[9] == '0')) ||
        (digVerificador + '0') == cpf[9])
    {
        somatorio = 0;
        digito = 0;
        for (int i = 11; i >= 2; i--)
        {
            somatorio += (cpf[digito] - '0') * i;
            digito++;
        }

        digVerificador = 11 - (somatorio % 11);
        if (((digVerificador >= 10) && (cpf[10] == '0')) ||
            (digVerificador + '0') == cpf[10])
        {
            resultado = 1;
        }
    }
    else
    {
        resultado = 0;
    }
    return resultado;
}

int verificarDataNascimento(char dataNascimento[])
{

    if (strlen(dataNascimento) != 8)
    {
        printf("\n\nData de nascimento inválida. O formato correto é DDMMAAAA.\n");
        return 0;
    }
    int dia = (dataNascimento[0] - '0') * 10 + (dataNascimento[1] - '0');
    int mes = (dataNascimento[2] - '0') * 10 + (dataNascimento[3] - '0');
    int ano = (dataNascimento[4] - '0') * 1000 + (dataNascimento[5] - '0') * 100 +
              (dataNascimento[6] - '0') * 10 + (dataNascimento[7] - '0');

    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 1900 || ano > 2026)
    {
        printf("\n\nData de nascimento inválida!\n");
        return 0;
    }
    if (mes == 2 || mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        if (dia > 30)
        {
            printf("\n\nData de nascimento inválida!\n");
            return 0;
        }
    }
    return 1;
}