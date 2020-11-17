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
        printf("%d ",p->chave);
        exibir(p->esq);
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


void pai(NO* p, int ch, NO* *resp){
    if (p && *resp == NULL)
    {
        if((p->esq && p->esq->chave == ch) || (p->dir && p->dir->chave == ch)){
            *resp =p;
            return;
        }
        pai(p->esq,ch, resp);
        if(*resp) return;
        pai(p->dir,ch, resp);
    }
    
}

void excluirFolha(NO* *p, int ch) {
    NO* paizao = NULL;
    pai(*p,ch,&paizao);

    if(!paizao){
        free(*p);
        *p = NULL;
        return;
    }
    NO* aux;
    if(paizao->esq && paizao->esq->chave==ch){
        aux = paizao->esq;
        paizao->esq = NULL;
    }
    else{
        aux = paizao->dir;
        paizao->dir = NULL;
    }
    free(aux);
}

int main(){
    NO* raiz = NULL;

    inserir(&raiz,NULL,18,1);
    inserir(&raiz,raiz,17,1);
    inserir(&raiz,raiz,16,2);
    inserir(&raiz,raiz->esq,12,1);
    inserir(&raiz,raiz->esq,15,2);
    inserir(&raiz,raiz->dir,6,1);
    inserir(&raiz,raiz->dir,5,2);
    inserir(&raiz,raiz->esq->esq,3,1);
    inserir(&raiz,raiz->esq->esq,9,2);
    inserir(&raiz,raiz->esq->dir,2,1);
    inserir(&raiz,raiz->esq->dir,13,2);
    printf("Antes: ");
    exibir(raiz);
    excluirFolha(&raiz,3);
    printf("Depois: ");
    exibir(raiz);

    
 }