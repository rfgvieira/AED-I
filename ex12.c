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

int menorChave(NO* p){
    if(!p){
        return -1;
    }
    if(p->esq)
        menorChave(p->esq);
    else
        return p->chave;
}

int altura(NO* p){
    if(!p)
        return 0;
    if(altura(p->esq) > altura(p->dir))
        return altura(p->esq)+1;
    else
        return altura(p->dir)+1;
}

int main(){
    NO* raiz = NULL;

    inserir(&raiz,NULL,25,1);
    inserir(&raiz,raiz,20,1);
    inserir(&raiz,raiz,30,2);
    inserir(&raiz,raiz->esq,18,1);
    inserir(&raiz,raiz->esq,22,2);
    inserir(&raiz,raiz->dir,28,1);
    inserir(&raiz,raiz->dir,32,2);
    inserir(&raiz,raiz->esq->esq,15,1);
    inserir(&raiz,raiz->esq->esq,19,2);
    inserir(&raiz,raiz->esq->dir,21,1);
    inserir(&raiz,raiz->esq->dir,23,2);

    printf("Menor: %d", menorChave(raiz));
    printf(" Altura: %d", altura(raiz));
    
 }