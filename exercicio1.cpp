#include <stdio.h>
#include <stdlib.h>

int verificarOrdem(int vetor[], int n){
    int cres = 0;
    int decr = 0;
    for(int i = 0; i<n-1;i++){
        if(vetor[i]<= vetor[i+1]){
            cres++;
        }
        if(vetor[i]>= vetor[i+1]){
            decr++;
        }
    }

   if((decr == n-1 && cres == n-1) ){
        return 0;
    }
    if(cres == n-1){
         return 1;
    }
    if(decr == n-1){
        return -1;
    }

    if((decr < n-1 && cres<n-1 ) ){
        return  99;
    }

}
int main(){

    int n = 10;
    int v[n] = {} ;
    int w[n] = {8,7,6,5,4,3,2,10,1,0};
    int x[n] = {1,1,1,1,1,1,1,1,1,1};
    int y[n] = {0,1,2,3,3,4,5,6,7,8};
    int z[n] = {8,7,6,5,4,3,2,1,1,0};

    printf("%i",verificarOrdem(w,n));


}

