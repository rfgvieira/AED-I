#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct estrutura{
    int valor;
    int col;
    int linha;
    struct estrutura* prox;
}NO;

typedef struct{
    NO* inicio;
    int maxc;
    int maxl;
} MATRIZ;

NO* ultimo(MATRIZ* m){
    NO* e = m->inicio;
    while(e)
    {
        if(e->prox == NULL){
            return e;
        }
        e = e->prox;
    }
    return NULL;
}

void exibir(MATRIZ* m){
    NO* end = m->inicio;
    while(end){
        printf("%i ", end->valor);
        end = end->prox;
    }
}

void inserir(MATRIZ* m, int val, int l, int c){
    NO* ult = ultimo(m);
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->valor = val;
    novo->linha = l;
    novo->col = c;
    novo->prox = NULL;
    if(!ult) m->inicio = novo;
    else ult->prox = novo;
}

int valor(MATRIZ* m, int i, int j){
    NO* p= m->inicio;
    for (int l = 1; l <= i ; l++)
    {
        for (int c = 1; c<= j; c++)
        {
            if(l==i && c==j){
                while(p){
                    if(p->col == c && p->linha == l){
                        return p->valor;
                    }
                    p = p->prox;
                }
            }
        }
    }
    return 0;
}

bool pesquisar(MATRIZ* m, int i,int j, NO* *e, NO* *ant){
        NO* p= m->inicio; 
        while (p)
        {
            if(p->col == j && p->linha == i){
                *e=p;
                return true;
            }
            *ant = p;
            p = p->prox;
        }
        return false;    
}

void exibirLinha(MATRIZ* m, int i){
    NO* p = NULL;
    NO* ant = NULL;
    int j = 1;
    while(j != m->maxc+1){
        bool existe= pesquisar(m,i,j,&p,&ant);
            if(existe){
                printf("%d ",p->valor);
            }
            else
                printf("0 ");
        j++;
    }
}

void zerarDiagonal(MATRIZ* m){
    NO* p= NULL;
    NO* ant = NULL;
    for (int i = 1; i <= m->maxl; i++)
    {
        for (int j = 1; j <= m->maxc; j++)
        {
            if(i==j){
                bool existe = pesquisar(m,i,j,&p,&ant);
                if(existe){
                    ant->prox= p->prox;
                    free(p);
                }
            }
        }
    }  
}

int main(){
    MATRIZ m;
    m.inicio = NULL;
    m.maxc= 4;
    m.maxl= 4 ;
    inserir(&m,8,1,3);
    inserir(&m,5,1,4);
    inserir(&m,4,2,2);
    inserir(&m,7,3,1);
    inserir(&m,2,3,3);
    inserir(&m,12,4,2);
    
    exibir(&m);
    
    printf("\n");
    exibirLinha(&m,1);
    printf("\n");
    exibirLinha(&m,2);
    printf("\n");
    exibirLinha(&m,3);
    printf("\n");
    exibirLinha(&m,4);

    zerarDiagonal(&m);

    printf("\n\n");
    exibirLinha(&m,1);
    printf("\n");
    exibirLinha(&m,2);
    printf("\n");
    exibirLinha(&m,3);
    printf("\n");
    exibirLinha(&m,4);
    printf("\n");

    exibir(&m);
    //printf("Valor:%d", valor(&m,4,2));
}