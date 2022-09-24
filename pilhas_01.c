#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	
	int valor;
	struct no* prox;
} no;

typedef no pilha;

void push(pilha** p, int num) {

	pilha* novo = (pilha*)malloc(sizeof(pilha));

	if (*p == NULL) {
        
		*p = novo;
		(*p)->valor = num;
		(*p)->prox = NULL;
	}
	else {
	
	    pilha* temp;

	    temp = *p;

		while (temp->prox != NULL ) {

			temp = temp -> prox;
		}

	    temp -> prox = novo;
	    novo -> valor = num;
	    novo -> prox = NULL;
	}
}

void pop(pilha** p) {

	pilha* temp;
	temp = *p;
	
	if (*p == NULL) {

        printf("A Pilha está vazia\n");
    }
	else {
		
		if (temp->prox == NULL) {

            *p = NULL;
        } 
		else {

			while (temp->prox->prox != NULL) {

				temp = temp->prox;
			}

			temp->prox = NULL;
		}
	}
}

void imprimir(pilha* p) {

	pilha* temp;

	temp = p;

	if (p == NULL) {

        printf("A Pilha se encontra vazia!\n");
    }
	else {

		while (temp != NULL) {
			
			printf("Elemento: %d \n", temp->valor);

			temp = temp-> prox;
		}
	}
}

void esvaziarpilha(pilha **p) {
	
	pilha* aux;
	aux = *p;

	while (aux != NULL) {

		*p = aux->prox;
		free(aux);
		aux = *p;
	}
}

int main() {

    pilha* p = NULL;

	int elemento;
    int opcao = 99;

	while (opcao != 0) {

	 //   system("clear");

		printf("################### PILHA ####################\n");

		printf("\n");
		printf("0 - Sair\n");
		printf("1 - Empilhar\n");
		printf("2 - Desempilhar\n");
		printf("3 - Esvaziar Pilha\n");
		printf("4 - Imprimir\n");
		printf(".:");

		scanf("%d", &opcao);

		switch (opcao) {

			case 1:

				printf("Qual elemento você deseja empilhar?\n");
					scanf("%d", &elemento);

				push(&p, elemento);

				printf("Vamos imprimir agora após ter empilhado\n");

				imprimir(p);

				getchar();
				getchar();

			break;

			case 2: 
				
				printf("Vamos desempilhar\n");

				pop(&p);

				printf("\n");

				printf("Imprimindo agora após desempilhar\n");
				imprimir(p);

				getchar();
				getchar();

			break;

			case 3: 
				
				printf("Esvaziando a pilha\n");

				esvaziarpilha(&p);

				printf("Imprimindo após ter esvaziado\n");

				imprimir(p);

				getchar();
				getchar();

			break;

			case 4:
				
				printf("Imprimindo...\n");
				imprimir(p);

				getchar();
				getchar();

			break;

		}
    }

    return 0;
}