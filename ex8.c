#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct estrutura{
    int chave;
    struct estrutura* prox;
    struct estrutura* ant;
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

NO* ultimo(LISTA* l){
    NO* e = l->inicio;
    while(e)
    {
        if(e->prox == NULL){
            return e;
        }
        e = e->prox;
    }
    return NULL;
}

NO* ultimoN(NO* l){
    NO* e = l;
    while(e)
    {
        if(e->prox == NULL){
            return e;
        }
        e = e->prox;
    }
    return NULL;
}

void anexar(int ch, LISTA *l){
    NO* ult = ultimo(l);
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->chave = ch;
    novo->prox = NULL;
    if(!ult){
        l->inicio = novo;
        novo->ant = NULL;
    } 
    else{
        novo->ant = ult;
        ult->prox = novo;
    } 
}


NO* listaNumerada(int n){
    NO* resp = NULL;
    if( n > 0){
        for(int i = 1; i <= n; i++){
            NO* ult = ultimoN(resp);
            NO* novo = (NO*) malloc(sizeof(NO));
            novo->prox = NULL;
            novo->chave = i;
            if(!ult){
                resp = novo;
                novo->ant = NULL;
            } 
            else{
                novo->ant = ult;
                ult->prox = novo;
            }
        }
        return resp;
    }
    return NULL;
}

void moverParaFim(LISTA* l, NO* p){
    NO* ult = ultimo(l);
    if(p != ult){
        if(p == l->inicio){
            l->inicio =  p->prox;
            p->prox->ant = NULL;
        }
        else
        {
            p->prox->ant = p->ant;
            p->ant->prox = p->prox;
        }
        
        ult->prox = p;
        p->ant = ult;
        p->prox = NULL;
       
    }
}

int main(){
    LISTA l1;
    l1.inicio = NULL;

    anexar(1,&l1);
    anexar(2,&l1);
    anexar(4,&l1);
    anexar(7,&l1);
    anexar(22,&l1);
    anexar(3,&l1);
    printf("Antes:");
    exibir(&l1);

    //exibir(listaNumerada(12));
    printf("\nDepois:");
    moverParaFim(&l1,l1.inicio);
    exibir(&l1);
    
   



}