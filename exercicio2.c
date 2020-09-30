#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

 typedef struct {
        int chave;
    } REGISTRO;

    typedef struct {
        REGISTRO A[10];
        int nelem;
    } LISTA;

void inicl(LISTA* l){
    l->nelem = 0;
}
void exibirL(LISTA l){

    for(int i = 0; i<l.nelem;i++){
        printf("%i \n", l.A[i].chave);
    }
}




int ocorrencias(LISTA* l,int x){
    int cont = 0;
    for(int i = 0; i<l->nelem;i++){
        if(l->A[i].chave == x){
            cont++;
        }
    }
    return cont;
}
bool identicas(LISTA* l1, LISTA *l2) {
   if(l1->nelem != l2->nelem){
       return false;
    }
   for(int i=0; i<l1->nelem;i++){

       if(l1->A[i].chave != l2->A[i].chave){
            return false;
       }
   }
}


int main(){

    LISTA l1;
    LISTA l2;
    inicl(&l1);
    inicl(&l2);

    l1.A[0].chave = 1;
    l1.A[1].chave = 2;
    l1.A[2].chave = 3;
    l1.A[3].chave = 1;
    l1.A[4].chave = 1;
    l1.nelem =5;

    l2.A[0].chave = 1;
    l2.A[1].chave = 2;
    l2.A[2].chave = 1;
    l2.A[3].chave = 3;
    l2.A[4].chave = 1;
    l2.nelem =5;



    if(identicas(&l1,&l2)){
        printf("As listas sao identicas");
    }
    else{
        printf("As listas sao diferentes");
    }
    //int valor = 1;
    //printf("O numero de vezes que %i aparece na lista e: %i",valor, ocorrencias(&l1,valor));
}
