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
       
        if(elemento->tipo == 1) printf("%c",elemento->simbolo);
        else printf("%f", elemento->valor);
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

void push(char ch, NO* p,int tipo) {
    NO* novo = (NO*) malloc(sizeof(NO));
    
    if(tipo == 1){
        novo->simbolo = ch;
        novo->tipo = tipo;
    }
    else{
        ch=ch-48;
        novo->tipo = tipo;
        novo->valor = (float) ch;
    } 
    novo->prox = p;
    p = novo;
    exibir(p);
}

int pop(NO* p) {
    NO* aux;
    if(!p) return(-1);
    int tipo = p->tipo;
    aux = p;
    char ch = tipo == 1 ? p->simbolo : p-> valor;
    p = p->prox;
    free(aux);
    return(ch);
}



//------------------------------------------
// O EP consiste em implementar esta funcao
// e outras funcoes auxiliares que esta
// necessitar
//------------------------------------------
void calcular(char* expressao, int* codigo){

	float resp = 0.0;
	*codigo = 999; 

    NO* p = NULL;
	for(int i =0; i<strlen(expressao);i++)
    {
        if( expressao[i] == '(' || expressao[i] == ')' || expressao[i] == '*' || expressao[i] == '/' || expressao[i] == '-' || expressao[i] == '+'){  
            
            push(expressao[i],p,1);
        }
        else{
            
            push(expressao[i],p,2);
        }
    }
    
   
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