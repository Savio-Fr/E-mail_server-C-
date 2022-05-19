#ifndef CAIXA_DE_ENTRADA_H_INCLUDED
#define CAIXA_DE_ENTRADA_H_INCLUDED

#include "email.h"

typedef struct caixa_de_entrada* APONTADOR_CAIXA_DE_ENTRADA;

typedef struct caixa_de_entrada {
    EMAIL Email;
    APONTADOR_CAIXA_DE_ENTRADA Caixa_de_Entrada_Anterior, Caixa_de_Entrada_Posterior;
} CAIXA_DE_ENTRADA;

typedef struct descritor_caixa_de_entrada {
    int Contador_Caixa_de_Entrada;
    APONTADOR_CAIXA_DE_ENTRADA Primeira_Caixa_de_Entrada, Ultima_Caixa_de_Entrada;
} DESCRITOR_CAIXA_DE_ENTRADA;

#endif // CAIXA_DE_ENTRADA_H_INCLUDED
