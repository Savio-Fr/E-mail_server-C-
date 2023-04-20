#include "lista.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int aux = -1;

	provedor * p = criar_provedor();
	
	while (aux) { 
		printf("\n ###########################################");
		printf("\n Escolha uma das opcoes\n");
		printf(" DIGITE 1 PARA CADASTRAR NOVO USUÁRIO \n");
		printf(" DIGITE 2 PARA REMOVER UM USUÁRIO \n");
		printf(" DIGITE 3 PARA ENVIAR UM E-MAIL \n");
		printf(" DIGITE 4 PARA CONSULTAR UM E-MAIL \n");
		printf(" 0 - Sair\n");
		printf("###########################################\n");
		scanf("%d", &aux);
    
		msg *mensagem = NULL;
		int id = 0;
		switch (aux) {
			case 1:
				id = ler_idUsuario();
				insere_usuario(p, id);
			break;
				
			case 2: 
				id = ler_idUsuario();
				remove_usuario(p, id);
			break;
				
			case 3:
				escrever_mensagem(p);
			break;
				
			case 4: 
				id = ler_idUsuario();
				imprime_caixa(p, id);
			break;
			
			case 0:
			
			printf("\n ###########################################\n");
            printf("\n Você escolheu a opção SAIR, Obrigado!\n");
            printf("\n ###########################################\n");
			break;
			 
			default:
				printf("Opcao nao reconhecida.\n");
			break;
		}
    }
    
	free_provedor(p);

    return 0;
}


