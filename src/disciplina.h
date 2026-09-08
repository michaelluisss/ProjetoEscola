#ifndef DISCIPLINA_H
#define DISCIPLINA_H

typedef struct 
{
    char nome[99];
    char codigo[7];
    int semestre;
    char professor[];
    
};




#endif