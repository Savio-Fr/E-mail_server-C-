#ifndef EMAIL_H_INCLUDED
#define EMAIL_H_INCLUDED

typedef char* MENSAGEM;

typedef struct email {
    int Prioridade;
    MENSAGEM Mensagem;
} EMAIL;

#include "caixa_de_entrada.h"

#endif // EMAIL_H_INCLUDED
