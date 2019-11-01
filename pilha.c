#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int pilha[MAX];
int inicio,fim;

int pilhaCheia(){
	return (fim == MAX); 	// caso o final for igual a 10 esta cheia
}
int pilhaVazia(){
	return (inicio == fim); 	// verifica se esta vazio e retorna;
}
void push(char x){
	if( !pilhaCheia() ){
		pilha[fim++] = x;	//adiciona o valor e soma +1 posiçao
	}else{
	printf("Pilha cheia \n");
	}
}
int pop(){
	int aux;
	if( !pilhaVazia() ){
		aux=pilha[fim - 1];		//volta uma posiçao e passa o numero e entao decrementa
		fim--;
		return aux;

		}else{
			printf("Pilha vazia \n");
		return -1;
		}
	}


void exibe(int pilha[MAX]){
	 int x;
    for( x = inicio; x < fim; x++) {
        printf("%c ", pilha[x]);	//exibe o vetor;
    }
    printf("\n");
}

//retorna o elemento que está no topo da pilha
char top(){
    return pilha[--fim];
}

int main(){

	inicio = 0;
	fim = 0;
	int escolha;
    char valor;
	do {
    printf("\n1 EMPILHA:\n");
    printf("\n2 DESEMPILHA:\n");
    printf("\n3 Mostra elementos da pilha:\n");
    printf("\n4 Mostra Top:\n");
    printf("\n5 Sair:\n");
    scanf("%d",&escolha);

    switch(escolha) {

    case 1:
        printf("Escolha o valor: ");
        scanf(" %c", &valor);
        push(valor);
        break;
    case 2:
        if (!pilhaVazia()) {
            printf("Elemento removido: %c\n", pop());
        } else {
            printf("\nA pilha esta vazia!\n");
        }
        break;
    case 3:
        if (!pilhaVazia()) { // se a pilha não está vazia
            printf("Elementos: ");
            exibe(pilha); // aqui usa a função exibe para mostrar os elementos
        } else {
            printf("\nA pilha esta vazia!\n");
        }
        break;
    case 4:
        if(!pilhaVazia()){
            printf("\n%c",top());
        }else{
            printf("\nA pilha esta vazia!\n");
            }
    default:
        break;
    }
} while( escolha != 5);

    return 0;
}
