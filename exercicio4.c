#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct estrutura{
    int chave;
    struct estrutura* prox;
} NO;

typedef struct{
    NO* inicio;
} LISTA;

void exibir(LISTA* l){
    NO* end = l->inicio;

    while(end){
        printf("%i ", end->chave);
        end = end->prox;
    }
}

void inserir(int ch, LISTA* l){
    NO* ant = (NO*) malloc(sizeof(NO));
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->chave = ch;
    if(l->inicio==NULL){
        l->inicio = novo;
        novo->prox = NULL;
    }
    else{
        novo->prox = l->inicio;
        l->inicio = novo;
    }
}

int ocorrencias(LISTA* l, int x){
    NO* end = l->inicio;
    int cont = 0;
    while(end){
        if(end->chave == x) cont++;
        end = end->prox;
    }
    return cont;
}

int tam(LISTA* l){
   int cont =0;
   NO* end = l->inicio;
   while(end){
        cont++;
        end = end->prox;
    }
    return cont;
}

bool identicas(LISTA* l1, LISTA *l2) {

    if(tam(l1) != tam(l2)) return false;
    else{
        NO* end1 = l1->inicio;
        NO* end2 = l2->inicio;
        while(end1){
            if(end1->chave!=end2->chave) return false;
            end1 = end1->prox;
            end2 = end2->prox;
        }
        return true;
    }
}

int main(){
    LISTA l1;
    LISTA l2;
    l1.inicio = NULL;
    l2.inicio = NULL;

    inserir(1,&l1);
    inserir(2,&l1);
    inserir(2,&l1);
    inserir(2,&l1);
    inserir(22,&l1);
    inserir(3,&l1);
    //printf("Lista 1: ");
    //exibir(&l1);


    inserir(1,&l2);
    inserir(2,&l2);
    inserir(2,&l2);
    inserir(2,&l2);
    inserir(22,&l2);
    inserir(3,&l2);
    //printf("\nLista 2: ");
    //exibir(&l2);

    if(identicas(&l1,&l2)) printf("As listas sao iguais");
    else printf("As listas sao diferentes");



    //int x = 2;
    //printf("\n A chave %i aparece %i vezes na lista",x,ocorrencias(&l,x));
}
