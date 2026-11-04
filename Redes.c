/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM_PESSOAS 25


void inicializar_rede(int M[][NUM_PESSOAS]){
    
    int i = 0;
    for(i = 0; i < NUM_PESSOAS; i++){
        for(int j = 0; j < NUM_PESSOAS; j++){
            M[i][j] = 0;
        }
    }
}

void adicionar_amizade(int i, int j, int M[][NUM_PESSOAS]){
    if(i != j){
    M[i][j] = 1;
    M[j][i] = 1;
    }
}

float random_float(){
    return (float)rand()/(float)RAND_MAX;
}

void popularRedeSocialAleatoriamente(float P, int M[][NUM_PESSOAS]){
    
    int num[NUM_PESSOAS];
    int a = 0;
    int A[NUM_PESSOAS] = {0};
    
    for(int i = 0; i < NUM_PESSOAS; i++){
        for(int j = 0; j < NUM_PESSOAS; j++){
            int validacao = 1;
            for(a = 0;a < i; a++){
                if(j == A[a]){
                    validacao = 0;
                }
            }
            if(i != j && validacao){
                float r = random_float();
                if(r < P){
                    M[i][j] = 1;
                    M[j][i] = 1;
                }
            }
        }
        
        A[a] = i;
    }
}

void imprimirRedeSocial(int M[][NUM_PESSOAS]){
    for(int i = 0; i < NUM_PESSOAS; i++){
        for(int j = 0; j < NUM_PESSOAS; j++){
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

int numAmigosEmComum(int v, int u, int M[NUM_PESSOAS][NUM_PESSOAS] ){
    int contagem = 0;
    printf("\nAmigos em comum: ");
    for(int i = 0; i < NUM_PESSOAS; i++){
        
          if(M[v][i] == 1 && M[u][i] == 1){
              contagem++;
              printf("\nn%d", i);
          }  
    }
    
    return contagem;
}


int main()
{
    srand(time(NULL));
    
    int M[NUM_PESSOAS][NUM_PESSOAS];
    inicializar_rede(M);
    adicionar_amizade(1, 2, M);
    popularRedeSocialAleatoriamente(0.5, M);
    imprimirRedeSocial(M);
    int num = numAmigosEmComum(3, 6, M);
    printf("\nQuantidade total: %d", num);
    

    return 0;
}
