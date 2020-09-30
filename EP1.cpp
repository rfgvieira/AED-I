// Nome: Rodrigo Fernandes Gomes Vieira
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>


// ######### ESCREVA O NROUSP AQUI
char* nroUSP() {
    return("11796548");
}


// ######### ESCREVA SEU NOME AQUI
char* nome() {
    return("Rodrigo Fernandes Gomes Vieira");
}

// elemento da lista
typedef struct estr {
        int valor;
        struct estr* prox;
} NO;

// funcao principal
//NO* uniao(NO* p1, NO* p2);


//------------------------------------------
// O EP consiste em implementar esta funcao
// e outras funcoes auxiliares que esta
// necessitar
//------------------------------------------

NO* ultimo(NO* p){//Função para retornar o último elemento da lista
    NO* e = p;
    while(e){
        if(e->prox == NULL){
            return e ;
        }
        e = e->prox;
    }
    return NULL;
}

NO* uniao(NO* p1, NO* p2){
	NO* resp;
	resp = NULL;

	NO* pc1= p1;//ponteiro auxiliar 1
	NO* pc2= p2;//ponteiro auxiliar 2

    while(pc1||pc2){//Iteração nas duas listas
      NO* ult = ultimo(resp);//Ponteiro pegando o ultimo elemendo da lista resultante
      if(pc1 && pc2)//Caso exista elementos nas duas listas
      {
          if(pc1->valor <= pc2->valor){//Caso o valor da lista 1 seja menos que a da 2
              NO* novo = (NO*) malloc(sizeof(NO));
              novo->valor = pc1->valor;
              novo->prox = NULL;
              if(!ult) resp = novo; //Caso não exista elementos na lista resultante, então põe o novo elemento nela
              else if(pc1->valor > ult->valor){ //Caso  o valor da lista 1 e maior que o da resultante
                  ult->prox = novo;//Atribui um novo elemento a lista resultante
              }
              else free(novo);//Caso o valor da lista 1 seja menor que o da lista resultante, entao liberará o espaço alocado para o possivel novo elemento
              pc1 = pc1->prox;
          }
          else{// Caso o valor da lista 2 seja menor que o da 1, fará a mesma coisa, porém com a lista 2 invés da 1
              NO* novo = (NO*) malloc(sizeof(NO));
              novo->valor = pc2->valor;
              novo->prox = NULL;
              if(!ult) resp = novo;
              else if(pc2->valor > ult->valor){
                  ult->prox = novo;
              }
              else free(novo);
              pc2 = pc2->prox;
          }
      }
      else if(pc1){// Caso só exista elementos na lista 1
        NO* novo = (NO*) malloc(sizeof(NO));
        novo->valor = pc1->valor;
        novo->prox = NULL;
        if(!ult) resp = novo;
        else if(pc1->valor > ult->valor){
        ult->prox = novo;
        }
        else free(novo);
        pc1 = pc1->prox;
      }
      else{ // Caso só exista elementos na lista 2
        NO* novo = (NO*) malloc(sizeof(NO));
        novo->valor = pc2->valor;
        novo->prox = NULL;
        if(!ult) resp = novo;
        else if(pc2->valor > ult->valor){
        ult->prox = novo;
        }
        else free(novo);
        pc2 = pc2->prox;
      }
    }
	return resp;
}

//----------------------------------------------------------------
// use main() apenas para fazer chamadas de teste ao seu programa
//----------------------------------------------------------------
int main() {
	NO* p1 = NULL;
	NO* p2 = NULL;

    NO* teste = NULL;
	teste = uniao(p1,p2);
}

// por favor nao inclua nenhum código abaixo da função main()
