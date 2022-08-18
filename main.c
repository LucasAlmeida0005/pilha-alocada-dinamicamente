#include <stdio.h>
#include <stdlib.h>


// três primeiros passos: cria a struct no, cria a pilha q tera o topo e a inicialização
typedef struct No{

    int dado;
    struct No *prox;
}No;

typedef struct Pilha{ // struct para apontar o topo
     No *topo;

}pilha;

void inicializaPilha(pilha *p){ // inicialização da pilha

    p->topo = NULL;
}

void empilha(int valor, pilha *p){

    No *ptr = (No*) malloc(sizeof(No));

    if(ptr == NULL){
        printf("\nErro de alocação de no.\n"); // alocando memória para ptr
        return;
    }
    else{
        ptr->dado= valor; // pasasando um valor para ptr de dado
        ptr->prox= p->topo; // o topo vai ser a nova struct criada pelo prox
        p->topo= ptr; // topo recebe uma struct ptr sem valores

    }
}
int desempilha(pilha *p){

     No *ptr = p->topo; // ptr recebe o valor que esta no topo
     int dado;
     if(ptr == NULL){

         printf("Pilha vazia\n");
         return 0;
     }
     else{
         // inicialmente nosso topo é 30, após receber ptr->prox passa a ter o valor
         // da pilha de baixo == 20 neste caso.

         p->topo = ptr->prox;
        // printf("x %d \n",p->topo->dado); funcionalidade para ver a sequencia de retirada dos valores
        // printf("z %d\n",ptr->prox->dado); visualizar o dado da próxima pilha
         ptr->prox = NULL; // limpa a struct
         dado = ptr->dado;
         free(ptr);
         return dado;
     }
}

void imprimepilha(pilha *p){

    No *ptr = p->topo;

    if(ptr==NULL){
        printf("Pilha vazia\n");
        return;
    }
    else{

        while(ptr!=NULL){

            printf("%d ",ptr->dado);

            ptr= ptr->prox; // aponta para a variável de baixo
        }
        printf("\n");
    }
}
int main() {

    pilha *p1 = (pilha*)malloc(sizeof (pilha)); // cria uma struct para ser passada nas funções

    if(p1==NULL){

        printf("\n Erro de alocação da pilha");
        exit(0);
    }
    else{

        inicializaPilha(p1);

        empilha(10, p1);
        empilha(20, p1);
        empilha(30, p1);

        imprimepilha(p1);

        printf("\nDesempilhando: %d\n", desempilha(p1));
        imprimepilha(p1);
        printf("\nDesempilhando: %d\n", desempilha(p1));
        imprimepilha(p1);
        printf("\nDesempilhando: %d\n", desempilha(p1));
        imprimepilha(p1);
    }
}
