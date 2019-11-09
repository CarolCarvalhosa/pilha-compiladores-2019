#include <stdio.h>
#include <stdlib.h>
#define MAX 10

//char pilha[MAX];
//char aux[MAX];
//int inicio,fim;

struct Pilha {
    char elem[MAX];
    int N;
    //Numero corrente de elementos da pilha
};

//criando a variavel P da struct
struct Pilha P,D;

int pilhaCheia() {
	return (sizeof(P.elem)/sizeof(P.elem[0]) == P.N);
}
int pilhaVazia() {
    //printf("\n\n... Testando a pilha ==> ......%d \n\n", P.N);
    //printf("\n\n");
	return (P.N == 0);
}
void push(char x){
	if( !pilhaCheia() ){
		P.elem[P.N] = x;
        P.N++;
	}else{
	printf("\nPilha cheia\n");
	}
}
int pop(int numPop){
	int aux;
	if( !pilhaVazia() ){
        int i;
        for(i=0;i<numPop;i++){
            aux = P.elem[P.N - 1];		//volta uma posiçao e passa o numero e entao decrementa
		    P.N = P.N - 1;
	D.elem[D.N] = aux;
	D.N++;
        }
        return aux;
	}else{
		printf("Pilha vazia \n");
		return -1;
	}
}


void exibe(struct Pilha P){
	int x;
    for( x= (P.N -1); x >= 0 ; x-- ) {
        printf("\n%c ", P.elem[x]);	//exibe o vetor;

        if (x == (P.N -1)) {
            printf(" <- Topo");
        }
    }
    printf("\n");
}

//retorna o elemento que está no topo da pilha
char top(){
    return P.elem[P.N - 1];
}

void limpaTela() {
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}


int main(){
	int escolha;
    char valor;

	do {
        if (!pilhaVazia()) { // se a pilha não está vazia
            printf("\n ------> Elemento(s) da pilha <------ \n");
            exibe(P); // aqui usa a função exibe para mostrar os elementos
        } else {
            printf("\nA pilha esta vazia!\n");
        }
        
    printf("\n ======= MENU ======= \n");
    printf("\n(1) EMPILHA");
    printf("\n(2) DESEMPILHA");
    //printf("\n3 Mostra elementos da pilha:\n");
    printf("\n(3) MOSTRA ELEMENTO NO TOPO DA PILHA");
    printf("\n(4) SAIR\n\n");
    printf("Escolha uma opcao ==> ");
    scanf("%d",&escolha);

    switch(escolha) {

    case 1:
        printf("\nEscolha o valor para empilha: ");
        scanf(" %c", &valor);
        push(valor);
        limpaTela();
        break;
    case 2:
        limpaTela();
        if (!pilhaVazia()) {
            printf("\nElemento removido: %c\n", pop(1));
        } else {
            printf("\nA pilha esta vazia!\n");
        }
        break;
    /*case 3:
        if (!pilhaVazia()) { // se a pilha não está vazia
            printf("\n ------> Elemento(s) <------ \n");
            exibe(P); // aqui usa a função exibe para mostrar os elementos
        } else {
            printf("\nA pilha esta vazia!\n");
        }
        break;
    */
    case 3:
        limpaTela();
        if(!pilhaVazia()){
            printf("\nTopo da Pilha: %c\n",top());
        }else{
            printf("\nA pilha esta vazia!\n");
            }
    default:
        break;
    }

} while( escolha != 4);

    return 0;
}
