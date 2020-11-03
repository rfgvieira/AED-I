#include <stdio.h>
#include <stdlib.h>
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

void push(float ch, NO* *p,int tipo) { //Função para colocar os elementos numa pilha
    NO* novo = (NO*) malloc(sizeof(NO));
    
    if(tipo == 1) {
        novo->simbolo =(char) ch;
        novo->tipo = tipo;
    }
    else if(tipo == 2) {
        ch = ch-48;
        novo->tipo = tipo;
        novo->valor = (float) ch;
    } 
    else{

        novo->tipo = 2;
        novo->valor = (float) ch;
    }

    novo->prox = *p;
    *p = novo;
}

//------------------------------------------
// O EP consiste em implementar esta funcao
// e outras funcoes auxiliares que esta
// necessitar
//------------------------------------------
float calcular(char* expressao, int* codigo) {
    //Variáveis de retorno
    *codigo = 999; 
	float resp = 0.0;

    //Variáveis auxiliares
    float n2 = 0.0;
    char op;
    NO* p = NULL;
	
	for(int i =0; i<strlen(expressao);i++) {
        //Inserção dos elementos na pilha
        if(expressao[i] == '(' || expressao[i] == '*' || expressao[i] == '/' || expressao[i] == '-' || expressao[i] == '+')
            push(expressao[i],&p,1);
        else if( expressao[i] == ')')
            push(expressao[i],&p,1);
        else
            push(expressao[i],&p,2);

        //Realização dos cálculos parciais a partir do primeiro fecha parenteses encontrado
        if(p->simbolo == ')') {
            int flag = 1;

            //Liberação dos nós
            NO* aux = p;
            p = p->prox;
            free(aux);

            while (flag != 5) {

                if(!p){
                    *codigo = -1;
                     return resp = -1;
                }

                if(flag == 1 && p->tipo == 2){
                    NO* aux = p;
                    p = p->prox;
                    n2 = aux->valor;
                    free(aux);
                }
                else if(flag == 2 && p->tipo == 1 && p->simbolo != '('){
                    NO* aux = p;
                    p = p->prox;
                    op =aux->simbolo;
                    free(aux);
                    
                }
                else if(flag == 3 && p ->tipo == 2){
                    NO* aux = p;
                    p = p->prox;
                    resp =aux->valor;
                    free(aux);
                }
                else if(flag == 4 && p->tipo == 1 && p->simbolo == '('){
                    NO* aux = p;
                    p = p->prox;
                    free(aux);
                }
                else{
                    *codigo = -1;
                    return resp = -1;
                }
                flag++;
            }
            switch (op) {
                case '+':
                    resp += n2;
                    *codigo = 1;
                    break;
                case '-':
                    resp -= n2;
                    *codigo = 1;
                    break;
                case '*':
                    resp *= n2;
                    *codigo = 1;
                    break;
                case '/':
                    if(n2 == 0)  {
                        *codigo = 0;
                        return resp = -1;
                    } 
                    else 
                        resp /= n2;
                        *codigo = 1;
                    break;
                default:
                    break;
            }

            push(resp, &p, 3);//Inserção do resultado do cálculo parcial para a pilha
        }
        else{
            resp = -1;
            *codigo = -1;
        }
    }    
	return resp;
}



//----------------------------------------------------------------
// use main() apenas para fazer chamadas de teste ao seu programa
//----------------------------------------------------------------
int main() {


	// o EP sera testado com chamadas deste tipo

	char exp[200];
	strcpy(exp, "(10-((20/0)+4))");//fazer essa verificação

	int codigo;
    float resp = calcular(exp,&codigo);
    printf("Codigo:%d Resp:%f",codigo,resp);

}

// por favor nao inclua nenhum código abaixo da função main()