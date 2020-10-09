#include <stdio.h>
#include <malloc.h>

typedef struct estrutura{
    int chave;
    struct estrutura* ant;
    struct estrutura* prox;
} NO;

typedef struct{
    NO* cabeca;
} LISTA;

void inicializar(LISTA* l1){
    l1->cabeca = (NO*) malloc(sizeof(NO));
    l1->cabeca->prox = l1->cabeca;
    l1->cabeca->ant = l1->cabeca;
}

void exibir(LISTA l) {
    NO* p = l.cabeca->prox;
    while (p!=l.cabeca) {
        printf("%d ",p->chave); 
        p = p->prox;
    }
}

NO* ultimo(LISTA* l1){
    NO* p = l1->cabeca->ant;
    if(p == l1->cabeca) return NULL;
    else return p;
}

void inserir(LISTA* l1, int ch){
    NO* novo= (NO*) malloc(sizeof(NO));
    NO* ult= ultimo(l1);
    novo->chave = ch;
   
    if(!ult){
          l1->cabeca->prox = novo;
          l1->cabeca->ant = novo;
          novo->prox = l1->cabeca;
          novo->ant = l1->cabeca;
    }
    else{
        novo->ant = ult;
        novo->prox = ult->prox;
        ult->prox = novo;
        novo->prox->ant = novo;
    }
}

NO* exibirInvertida(LISTA l1){
    NO* p = l1.cabeca->ant;
    while (p!=l1.cabeca){
        printf("%d ",p->chave);
        p = p->ant;
    }
}

void inserirAntes(LISTA* l, int ch, NO* atual){
    NO* novo= (NO*) malloc(sizeof(NO));
    novo->chave = ch;
    novo->ant = atual->ant;
    atual->ant = novo;
    novo->ant->prox = novo;
    novo->prox = atual;
}

int main(){
    LISTA l1;
    inicializar(&l1);
    
    inserir(&l1,2);
    inserir(&l1,3);
    inserir(&l1,6);
    inserir(&l1,4);

    inserirAntes(&l1,5,l1.cabeca->prox->prox->prox);
     inserirAntes(&l1,22,l1.cabeca->prox->prox->prox);

    printf("Normal: ");
    exibir(l1);

    printf("\nInvertida: ");
    exibirInvertida(l1);
}