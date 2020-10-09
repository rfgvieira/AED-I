#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>


// ######### ESCREVA O NROUSP AQUI
const char* nroUSP() {
    return("11796548");
}


// ######### ESCREVA SEU NOME AQUI
const char* nome() {
    return("Rodrigo Fernandes Gomes Vieira");
}

// elemento da pilha
typedef struct estrutura {
	struct estrutura *prox;
       	int tipo; // 1=char e 2=float
       	union {
              	char simbolo;
              	float valor;
       	};
} NO;


void exibir(NO* p) {
    NO* elemento = p;
    while(elemento) {
        printf("%i ", elemento->valor);
        elemento = elemento->prox;
    }
}

NO* ultimo(NO* p){
    NO* elemento = p;

    while(elemento) {
        if(elemento->prox == NULL){
            return elemento;
        }
        elemento = elemento->prox;
    }
    return NULL;
}


void inserir(char ch, NO* p, int tipo) {
    NO* novo;
    NO* ant;
    
    ant = ultimo(p);
    novo = (NO*) malloc(sizeof(NO));
    novo->prox = NULL;
    if(tipo == 1){
        //printf("char");
        novo->simbolo = ch;
        novo->tipo = tipo;
    }
    else{
        //printf("float");
        ch=ch-48;
        novo->tipo = tipo;
        novo->valor = ch;
    } 
    

    if(!ant) 
        p = novo;
    else 
        ant->prox = novo;
}



//------------------------------------------
// O EP consiste em implementar esta funcao
// e outras funcoes auxiliares que esta
// necessitar
//------------------------------------------
void calcular(char* expressao, int* codigo){

	float resp = 0.0;
	*codigo = 999; 

    NO* p;
	for(int i =0; i<strlen(expressao);i++)
    {
        if( expressao[i] == '(' || expressao[i] == ')' || expressao[i] == '*' || expressao[i] == '/' || expressao[i] == '-' || expressao[i] == '+'){  
            inserir(expressao[i],p,1);
        }
        else{
            inserir(expressao[i],p,2);
        }
    }

   printf("%c",p);
	//return resp;
}



//----------------------------------------------------------------
// use main() apenas para fazer chamadas de teste ao seu programa
//----------------------------------------------------------------
int main() {


	// o EP sera testado com chamadas deste tipo

	char exp[200];
	strcpy(exp, "(7*5)");

    for(int i =0; i<strlen(exp);i++)
    {
        printf("%c",exp[i]);
    }
    
       
   
	int codigo;
    calcular(exp,&codigo);
	//float resp = calcular(exp,&codigo);


}

// por favor nao inclua nenhum código abaixo da função main()