#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
#include "caixa_de_entrada.h"

void cadastra_usuario(DESCRITOR_LISTA_DE_USUARIOS *Descritor_Lista_de_Usuarios, int Id){

    DESCRITOR_CAIXA_DE_ENTRADA descritor_caixaDeEntrada;

    if(Descritor_Lista_de_Usuarios-> Contador_Lista_de_Usuarios == 0){

        Descritor_Lista_de_Usuarios-> Primeiro_Usuario = (LISTA_DE_USUARIOS*) malloc(sizeof(LISTA_DE_USUARIOS));
        Descritor_Lista_de_Usuarios-> Ultimo_Usuario = Descritor_Lista_de_Usuarios-> Primeiro_Usuario;
        Descritor_Lista_de_Usuarios-> Ultimo_Usuario-> Usuario.Id = Id; // Insere Id do Usuário
        // Descritor_Lista_de_Usuarios->Ultimo_Usuario->Usuario->Id = id_aux;
        
        //Chamada para a criação da caixa de entrada do novo usuário cadastrado
        //cadastra_caixaDeEntrada(&descritor_caixaDeEntrada);
        // Descritor_Lista_de_Usuarios->Ultimo_Usuario->Usuario.Descritor_Caixa_de_Entrada.Primeira_Caixa_de_Entrada = (CAIXA_DE_ENTRADA*) malloc(sizeof(CAIXA_DE_ENTRADA));
        Descritor_Lista_de_Usuarios->Primeiro_Usuario->Usuario_Anterior = NULL;
        Descritor_Lista_de_Usuarios->Primeiro_Usuario->Usuario_Posterior = NULL;
        Descritor_Lista_de_Usuarios->Contador_Lista_de_Usuarios++;

    } else {
        Descritor_Lista_de_Usuarios->Ultimo_Usuario->Usuario_Posterior = (LISTA_DE_USUARIOS*) malloc(sizeof(LISTA_DE_USUARIOS));
        Descritor_Lista_de_Usuarios->Ultimo_Usuario->Usuario_Posterior->Usuario_Anterior = Descritor_Lista_de_Usuarios->Ultimo_Usuario;
        Descritor_Lista_de_Usuarios->Ultimo_Usuario = Descritor_Lista_de_Usuarios->Ultimo_Usuario->Usuario_Posterior;
        
        //cadastra_caixaDeEntrada(descritor_caixaDeEntrada);

        Descritor_Lista_de_Usuarios->Ultimo_Usuario->Usuario.Id = Id; 
        Descritor_Lista_de_Usuarios->Ultimo_Usuario->Usuario_Posterior = NULL;
        Descritor_Lista_de_Usuarios->Contador_Lista_de_Usuarios++;
    }
}

void imprime_lista(APONTADOR_LISTA_DE_USUARIOS *li){
    if(li == NULL){
        return;
    }
     LISTA_DE_USUARIOS *no = *li;
    while(no != NULL){
        printf("Usuario: %d\n",no-> Usuario.Id);
        printf("-------------------------------\n");

        no = no-> Usuario_Posterior;
    }
}

// NULL < Usuario 1 > NULL - Caso onde s� foi cadastrado 1 usu�rio
// NULL < Usuario 1 <> Usuario 2 > NULL - Caso onde foram cadastrados 2 usu�rios
