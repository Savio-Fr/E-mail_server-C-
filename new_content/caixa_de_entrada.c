#include <stdio.h>
#include <stdlib.h>

#include "usuario.h"
#include "caixa_de_entrada.h"

void cadastra_caixaDeEntrada(DESCRITOR_CAIXA_DE_ENTRADA *descritor_caixaDeEntrada){

     if(descritor_caixaDeEntrada-> Contador_Caixa_de_Entrada == 0){

        descritor_caixaDeEntrada-> Primeira_Caixa_de_Entrada = (CAIXA_DE_ENTRADA*) malloc(sizeof(CAIXA_DE_ENTRADA));
        descritor_caixaDeEntrada-> Ultima_Caixa_de_Entrada = descritor_caixaDeEntrada-> Primeira_Caixa_de_Entrada;
        // Descritor_Lista_de_Usuarios->Ultimo_Usuario->Usuario.Descritor_Caixa_de_Entrada.Primeira_Caixa_de_Entrada = (CAIXA_DE_ENTRADA*) malloc(sizeof(CAIXA_DE_ENTRADA));
        descritor_caixaDeEntrada-> Primeira_Caixa_de_Entrada-> Caixa_de_Entrada_Anterior = NULL;
        descritor_caixaDeEntrada-> Primeira_Caixa_de_Entrada-> Caixa_de_Entrada_Posterior = NULL;
        descritor_caixaDeEntrada-> Contador_Caixa_de_Entrada++;
    } else {
        descritor_caixaDeEntrada-> Ultima_Caixa_de_Entrada-> Caixa_de_Entrada_Posterior = (CAIXA_DE_ENTRADA*) malloc(sizeof(CAIXA_DE_ENTRADA));
        descritor_caixaDeEntrada-> Ultima_Caixa_de_Entrada-> Caixa_de_Entrada_Posterior-> Caixa_de_Entrada_Anterior = descritor_caixaDeEntrada-> Ultima_Caixa_de_Entrada;
        descritor_caixaDeEntrada-> Ultima_Caixa_de_Entrada = descritor_caixaDeEntrada-> Ultima_Caixa_de_Entrada-> Caixa_de_Entrada_Posterior;
       
        descritor_caixaDeEntrada-> Ultima_Caixa_de_Entrada-> Caixa_de_Entrada_Posterior = NULL;
        descritor_caixaDeEntrada-> Contador_Caixa_de_Entrada++;
    }

}