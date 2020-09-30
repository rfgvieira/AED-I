#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int chave;
    int prox;
} REGISTRO;

typedef struct{
    REGISTRO A[5];
    int dispo;
    int inicio;
} LISTA;

void inicializar(LISTA* l){

    l->inicio = -1;
    l->dispo = 0;
    for(int i = 0;i<4;i++){
        l->A[i].prox=i+1;
    }
    l->A[4].prox = -1;

}
void exibirLL(LISTA* l){
    int i = l->inicio;
    printf("Lista: \"");
    while(i>-1){
        printf("%d", l->A[i].chave);
        i = l->A[i].prox;
    }
    printf(" \"\n");
}

void trocar(LISTA* l){
    if(l->A[l->inicio].prox!=-1)
    {
        int i = l->inicio;
        int aux;
        while(i>-1){
            if(l->A[i].prox==-1){
                l->A[i].prox = l->A[l->inicio].prox;
                l->A[l->inicio].prox = -1;
                l->inicio = i;
            }
            i=l->A[i].prox;
        }
    }
}


void sobrescrever(LISTA* l, int i){
    if(l->A[i].prox!=-1){
        int j = l->inicio;
         l->A[l->A[i].prox].chave = l->A[i].chave;
        while(j>-1){
            if(l->A[j].prox==i){
                    l->A[j].prox = l->A[i].prox;
            }
            j=l->A[j].prox;
        }
       l->dispo=i;
    }
}

int main(){
    LISTA l;
    inicializar(&l);
    l.A[0].chave = 1;
    l.A[1].chave = 2;
    l.A[2].chave = 3;
    l.A[2].prox = -1;
    l.inicio = 0;

    sobrescrever(&l,0);
    exibirLL(&l);

}
