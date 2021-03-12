#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>


// ######### ESCREVA O NROUSP AQUI
const char* nroUSP() {
    return("11796548");
}


// ######### ESCREVA SEU NOME AQUI
const char* nome() {
    return("Rodrigo Fernandes Gomes Vieira");
}

// elemento da matriz
typedef struct estr {
    int valor;
	int lin;
	int col;
    struct estr* prox;
} NO;

NO* ultimo(NO* p){//verifica o ultimo elemento da lista
    while(p){
        if(p->prox == NULL){
            return p ;
        }
        p = p->prox;
    }
    return NULL;
}

void inserir(NO* *m, int val, int l, int c){//insere um valor na matriz
    NO* ult = ultimo(*m);
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->valor = val;
    novo->lin = l;
    novo->col = c;
    novo->prox = NULL;
    if(!ult)
        *m = novo;
    else 
        ult->prox = novo;
}

NO* busca(NO* m, int index){//busca o nó naquele indice
    NO* p = m;
    if (index >= 0){
        for (int i = 0; i < index; i++)
            p = p->prox;
        return p;
    }
    return NULL;
}

int nelementos(NO* p){//conta quantos elementos a matriz possui
    int n = 0;
    while (p){
        n++;
        p = p->prox;
    }
    return n;
}

int indexOf(NO* p, int val){//busca o índice de um nó
    int i = 0;
    while (p){
        if(p->valor == val)
            return i;
        i++;
        p = p->prox;
    }
    return -1;
}

NO* minimo(NO* p, int index){//verifica qual nó tem q vir primeiro na matriz
    NO* aux = busca(p,index);
    if (aux){
        NO* min = aux;
        while (aux){
            if (aux->lin < min->lin){
                min = aux;
            }
            else if (aux->lin == min->lin){
                if (aux->col < min->col){
                    min = aux;
                }
            }
            aux = aux->prox;
        }
        return min;
    }
    return NULL;
}

NO* copiaTransposta(NO* p){//Função pra fazer uma copia da matriz, porém de forma transposta
	//Faz a cópia da matriz de forma transposta
    NO* resp;
	resp = NULL;
    while (p){
        inserir(&resp,p->valor,p->col,p->lin);
        p = p->prox;
    }
    //Organiza a matriz copiada
    int numelem = nelementos(resp);
    int i;
    for (i = 0; i < numelem-1; i++){
        NO* min = minimo(resp,i);
        NO* atual = busca(resp, i);
        if (atual != min){
            NO* temp = atual->prox;
            NO* ant = busca(resp,i-1);
            NO* antmin = busca(resp,indexOf(resp,min->valor)-1);
            
            atual->prox = min->prox;
            if(temp != min){
                
                min->prox = temp;
                antmin->prox = atual;
            }
            else{
                min->prox = atual;
            }
            if(!ant)
                resp = min;
            else
                ant->prox = min;    
        }
    }
	return resp;
}

void exibirl(NO* end){
    while(end){
        printf("%i ", end->valor);
        end = end->prox;
    }
}

int main() {
	NO* p = NULL;
    inserir(&p,1,2,1);
    inserir(&p,4,2,5);
    inserir(&p,5,3,5);
    inserir(&p,3,4,3);
    inserir(&p,2,5,1);

    NO* teste = NULL;
	teste = copiaTransposta(p);
    exibirl(teste);
}
