#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

const char* nroUSP() {
    return("11796548");
}

// no da arvore
typedef struct estr {
    int chave;
    struct estr *esq;
    struct estr *dir;
} NO;

typedef struct estr2 {
    NO* node;
    struct estr2 *prox;
} NO2;

typedef struct PILHA {
    struct estr2 *top;
} PILHA;

void exibir(NO* p){
    if(p){
        exibir(p->esq);
        printf("%d ",p->chave);
        exibir(p->dir);
    }
}

void empilhaArv(NO* p, PILHA* pilha, int j) {
    if (p) {
        empilhaArv(p->dir, pilha, j+1);
        push(p, pilha);
        empilhaArv(p->esq, pilha, j+1);
    }
}

NO* verifica(PILHA* pilha) {
    NO2* atual = pilha->top;
    NO2* prox = pilha->top->prox;
    NO2* posAtual = NULL;
    NO2* posProx = NULL;
    NO2* comp = NULL;
    bool erro = false;

    do {
        if (!atual || (!prox && !erro)) 
            break;
        if (prox == NULL && erro) {
            comp = pilha->top;
            do {
                if (comp == posAtual) 
                    return posAtual->node;
                if ((comp->prox == posAtual) && (posProx->node->chave <= comp->node->chave))
                    return posProx->node;
                comp = comp->prox;
            } while (true);
        }
        if (atual->node->chave >= prox->node->chave) {
            if (erro)
                return posAtual->node;
            posAtual = atual;
            posProx = prox;
            prox = prox->prox;
            erro = true;
        }
        else {
            if (erro) return posProx->node;
            atual = prox;
            prox = prox->prox;
        }
    } 
    while (true);
    return NULL;
}

NO* remove(NO* p) {
    NO* rem = p;
    NO* pai = NULL;

    if(p->esq) {
        pai = p;
        p = p->esq;
    }
    do {
        if(!p->dir)
            break;
        pai = p;
        p = p->dir;
    } 
    while (true);
    if (!pai) {
        p = NULL;
        free(p);
        return NULL;
    }
    if (pai->esq == p) {
        if (!p->esq) 
            pai->esq = NULL;
        else 
            pai->esq = p->esq;
    }
    else if (pai->dir == p) {
        if (!p->esq) 
            pai->dir = NULL;
        else
            pai->dir = p->esq;
    }
    p->esq = rem->esq;
    p->dir = rem->dir;
    free(rem);
    return p;
}

NO* arranja( NO* i, NO* p,int j, NO* resp) { 
    if (p) {
        if (resp) 
            return resp;
        resp = arranja( i, p->dir, j+1, resp);
        if (p->esq && p->esq == i)
            return p;
        if (p->dir && p->dir == i)
            return p;
        resp = arranja( i, p->esq, j+1, resp);
    }
    return resp;
}

void organizar(NO* *raiz) {
    PILHA* pilha = (PILHA*) malloc(sizeof (PILHA));
    pilha->top = NULL;
    NO* p = *raiz;
    empilhaArv(p, pilha, 1);
    NO* erro = verifica(pilha);

    if (erro) {
        if (arranja(erro, p, 1, NULL)) {
            if (arranja(erro, p, 1, NULL)->dir == erro)
                arranja(erro, p, 1, NULL)->dir = remove(erro);
            if (arranja(erro, p, 1, NULL)->esq == erro)
                arranja(erro, p, 1, NULL)->esq = remove(erro);
        } 
        else
            *raiz = remove(erro);
    }
}

int main() {
    NO *arv = NULL;
    organizar(&arv);
}
