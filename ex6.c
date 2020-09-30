#include <stdio.h>
#include <malloc.h>

typedef struct estrutura{
    int chave;
    struct estrutura* prox;
} NO;

typedef struct{
    NO* topo;
} PILHA;

typedef struct{
    NO* inicio;
} LISTA;



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

void anexar (int ch,LISTA* l){
    NO* novo = (NO*) malloc(sizeof(NO));
    NO* ult = ultimo(&*l);
    novo->chave = ch;
    novo->prox = NULL;
    if(!ult) l->inicio = novo;
    else ult->prox = novo;
}

void push(int ch, PILHA* p){
    NO* novo= (NO*) malloc(sizeof(NO));
    novo->chave=ch;
    novo->prox = p->topo;
    p->topo = novo;
}


NO* copiaInvertida(NO* p) {PILHA p1;//Cria uma pilha
    p1.topo = NULL;
    while(p){//Enquanto o ponteiro n�o for nulo percorre a lista
        push(p->chave,&p1);//Inclui um elemento no topo da pilha
        p = p->prox;
    }
    NO* top = p1.topo;
    return top;//Retorna o topo da pilha
}

void exibir(NO* p){
    while(p){
        printf("%i ", p->chave);
        p = p->prox;
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

    NO* p = l1.inicio;

    exibir(copiaInvertida(p));
}
