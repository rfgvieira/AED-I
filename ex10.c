#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct estrutura{
    int chave;
    struct estrutura* esq;
    struct estrutura* dir;
} NO;

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

void novoEsquerdo(NO* p){
    if(!p->esq){
        NO* novo = (NO *) malloc(sizeof(NO));
        novo->esq = NULL;
        novo->dir = NULL;
        if(!p->dir)
            novo->chave = p->chave;
        else
            novo->chave = p->chave + p->dir->chave;
        p->esq = novo;
    }
}

int main(){
    NO* raiz = NULL;

    inserir(&raiz,NULL,1,1);
    inserir(&raiz,raiz,2,1);
    inserir(&raiz,raiz,3,2);
    inserir(&raiz,raiz->esq,4,1);
    inserir(&raiz,raiz->esq,5,2);
    inserir(&raiz,raiz->dir,6,1);
    inserir(&raiz,raiz->dir,7,2);

    novoEsquerdo(raiz->esq->esq);

 }
