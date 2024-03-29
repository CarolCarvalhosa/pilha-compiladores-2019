#include <stdio.h>
#include <stdlib.h>
#define MAXPILHA 50
#define MAXUNIDPILHA 12

int inicioPilha,fimPilha, inicioUnidPilha, fimUnidPilha;

enum SimbG {
    S,C,B,L,E,T,F,M,N,v,i,a,f,p,e,w,d,o,c,m,t,n,s,q
};

typedef union {
   char asciiDoFonte[21];
   int end;
} TipAtributo;

typedef struct {
    enum SimbG simb;
    TipAtributo atributo;
    int estado;
}Pilha;

Pilha pilha[MAXPILHA];   // pilha com 50 andares
Pilha unidPilhaDePop[MAXUNIDPILHA]; // de 1 a n (pops lado direito) e 0 push lado esquerdo

int pilhaCheia() {
	return fimPilha == MAXPILHA;
}

int pilhaVazia() {
	return fimPilha == inicioPilha;
}

void push(Pilha * stk){
	if(!pilhaCheia()){
        pilha[fimPilha].simb = stk->simb;
		pilha[fimPilha].atributo = stk->atributo;
		pilha[fimPilha].estado = stk->estado;
		fimPilha++;
	}else{
        printf("\nPilha cheia\n");
	}
}

Pilha pop(){
	if(!pilhaVazia()){
        //unidPilhaDePop[fimUnidPilha++] = 
        return pilha[--fimPilha];
	}else{
		printf("Pilha vazia \n");
	}
     
}

void exibe(Pilha * stk, int inicio, int fim){
	int k;
    for(k = fim-1; k >= inicio; k--) {
        printf("{");
        printf("%u, ", stk[k].simb);
        printf("%d, ", stk[k].atributo.end);
        printf("%d", stk[k].estado);
        printf("}");	//exibe o vetor;

        if (k == fim-1) {
            printf(" <- Topo");
        }
        printf("\n");
    }
    printf("\n");
}

//retorna o elemento que está no topo da pilha
Pilha top(){
    return pilha[fimPilha-1];
}

// Isso mais a frente nao sera necessario
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
    inicioPilha = 0;
    fimPilha = 0;
    inicioUnidPilha = 0;
    fimUnidPilha = 0;

	do {
        if (!pilhaVazia()) { // se a pilha não está vazia
            printf("\n ------> Elemento(s) da pilha <------ \n");
            exibe(pilha, inicioPilha, fimPilha); // aqui usa a função exibe para mostrar os elementos
            printf("\n ------> Elemento(s) da pilha de pops <------ \n");
            exibe(unidPilhaDePop, inicioUnidPilha, fimUnidPilha);
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
        printf("\n## Informe os dados da Estrutura da Pilha ##\n\n!! Lembre-se: {Simbolo, Atributo, Estado}]\n");
        Pilha * nova = (Pilha *) malloc(sizeof(Pilha));

        printf("\nDigite o Simbolo (inteiro): ");
        scanf("%u", &nova->simb);
        printf("\nDigite o atributo: ");
        scanf("%d", &nova->atributo.end);
        printf("Digite o estado: ");
        scanf("%d", &nova->estado);
        push(nova);
        limpaTela();
        break;
    case 2:

        if (!pilhaVazia()) {
            unidPilhaDePop[fimUnidPilha++] = pop();
            //printf("\nElemento removido: %c\n", pop(1));
        } else {
            printf("\nA pilha esta vazia!\n");
        }
        limpaTela();
        break;
    case 3:
        limpaTela();
        if(!pilhaVazia()){
            Pilha topo = top();
            printf("\n==== Topo da Pilha ==== \n\n");
            printf("{");
            printf("%u, ", topo.simb);
            printf("%d, ", topo.atributo.end);
            printf("%d", topo.estado);
            printf("}");	//exibe o vetor;
        }else{
            printf("\nA pilha esta vazia!\n");
            }
    default:
        break;
    }

} while( escolha != 4);

    return 0;
}
