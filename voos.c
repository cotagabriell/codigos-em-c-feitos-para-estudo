
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUM_DIAS 30
#define NUM_VOOS 200
#define TAM_TRECHO 4

typedef struct Voo {
    
    float p[NUM_DIAS];
    char ori[TAM_TRECHO];
    char des[TAM_TRECHO];
    int pico;
    
    
}Voo;

float randf(float min, float max){
    return  ((float)rand()/(float)RAND_MAX) * (max - min) + min;
}


int indiceMaior(float x[], int n){
    int maior = 0;
    
    for(int i = 0; i < n-1; i++){
        if(x[maior] < x[i + 1]){
            maior = i+1;
        }
    }
    return maior;
}


void geraTrecho(char s[], int n){
    
    for(int i = 0; i < n-1; i++){
        s[i] = 65 + rand()%(91 - 65);
    }
    s[n-1] = '\0';
}

void preencheSeriePrecos(float y[], int n){

 y[n-1] = 100 + rand()%(401 - 100);    
    
 for(int i = n-2; i >= 0; i--){
     y[i] = y[i+1] * randf(0.8, 1.2);
 }   

}


void preencheVoo(Voo *v){
    preencheSeriePrecos(v -> p, NUM_DIAS);
    geraTrecho(v -> ori, TAM_TRECHO);
    geraTrecho(v -> des, TAM_TRECHO);
    v -> pico = indiceMaior(v -> p, NUM_DIAS) + 1;
}


int diaMaisCaro(Voo voos[], int n){
    
    int i = 0;
    int maior = 0;
    int base[NUM_DIAS] = {0};
    
    for(i = 0; i < n; i++){
        base[voos[i].pico-1]++;
    }
    
    for(i = 0; i < NUM_DIAS-1; i++){
        if(base[maior] < base[i+1]){
            maior = i+1;
        } 
    }
    
    return maior;
}




int main()
{
    srand(time(NULL));
    Voo voos[150];
    
    for(int i = 0; i < 70; i++){
        preencheVoo(&voos[i]);
    }
    
    
    printf("O dia mais caro foi: %d\n", diaMaisCaro(voos, 70));
    for(int i = 0; i < 70; i++){
    printf("Voo %d: pico = %d\n", i, voos[i].pico);
}
    
    
    
  
    
}
