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

void anexar(int ch, LISTA *l){

    NO* novo;
    NO* ant;
    ant = ultimo(&*l);
    novo = (NO*) malloc(sizeof(NO));
    novo->chave = ch;
    novo->prox = NULL;
    if(!ant) l->inicio = novo;
    else ant->prox = novo;
}


NO* copia(NO* p) {
    LISTA copia;
    NO* elem;
    NO* novo;
    copia.inicio = p;
    while(p)
    {
        novo = (NO*) malloc(sizeof(NO));
        novo->chave = p->chave;
        novo->prox = p->prox;
        p = p->prox;
    }

    elem = copia.inicio;
    return elem;
}

void ExcluirOcorrencias(LISTA* l, int x){
    NO* ant;
    NO* e;
    NO* aux;
    e = l->inicio;
    while(e){
        if(x == e->chave){
            if(e == l->inicio) l->inicio = e->prox;
            else ant->prox = e->prox;
            aux = e;
            e = e->prox;
            free(aux);
        }
        else{
            ant = e;
            e = e->prox;
        }

    }
}

int main(){
    LISTA l1;

    l1.inicio = NULL;


    anexar(1,&l1);
    anexar(2,&l1);
    anexar(2,&l1);
    anexar(2,&l1);
    anexar(22,&l1);
    anexar(3,&l1);
    printf("Original: ");
    exibir(&l1);

    NO* p = l1.inicio;

    NO* elem = copia(p);
    printf("\nCopia: ");

    while(elem){
        printf("%i ", elem->chave);
        elem = elem->prox;
    }

   // ExcluirOcorrencias(&l1,2);

   // printf("\nDepois: ");
   // exibir(&l1);


}
