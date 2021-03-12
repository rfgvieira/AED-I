#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct estrutura{
    int chave;
    struct estrutura* esq;
    struct estrutura* dir;
} NO;

void exibir(NO* p){
    if(p){
        exibir(p->esq);
        printf("%d ",p->chave);
        exibir(p->dir);
    }
}

void inserir(NO* *raiz, NO* pai, int ch, int pos){
    if(pai){
        if((pos == 1 && pai->esq !=NULL) || (pos == 2 && pai->dir !=NULL)){
            return;
        }
    }
    NO* novo = (NO *) malloc(sizeof(NO));
    novo->chave = ch;
    novo->esq = NULL;
    novo->dir = NULL;
    if(!pai) *raiz = novo;
    else{
        if(pos==1)
            pai->esq = novo;
        else
            pai->dir = novo;
    }
}

void precedente(NO* p, int ch, int x){//x =-999, um valor menor que o menor valor da arvore
    if(p){
        precedente(p->esq,ch,x);
        precedente(p->dir,ch,x);
        if(p->chave == ch){
            x = ch-1;
            return;
        }
        if(p->chave <= x){
            printf("%d", p->chave);
        }
    }
}


int main(){
    NO* raiz = NULL;

    inserir(&raiz,NULL,7,1);
    inserir(&raiz,raiz,3,1);
    inserir(&raiz,raiz,11,2);
    inserir(&raiz,raiz->esq,1,1);
    inserir(&raiz,raiz->esq,5,2);
    inserir(&raiz,raiz->dir,9,1);
    inserir(&raiz,raiz->dir,13,2);
    inserir(&raiz,raiz->esq->esq,0,1);
    inserir(&raiz,raiz->esq->esq,2,2);
    inserir(&raiz,raiz->esq->dir,4,1);
    inserir(&raiz,raiz->esq->dir,6,2); 
    inserir(&raiz,raiz->dir->esq,8,1);
    inserir(&raiz,raiz->dir->esq,10,2);
    inserir(&raiz,raiz->dir->dir,12,1);
    inserir(&raiz,raiz->dir->dir,14,2); 

    precedente(raiz,9,-999);
 }