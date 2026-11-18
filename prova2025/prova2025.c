#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>


typedef struct lutador { 
    char *nome; 
    int vitalidade; 
    int dano_maximo; 
}Lutador; 


int randint(int min, int max) {  
 return min + rand()%(max-min+1); 
}  


Lutador *carrega_lutadores(int *n){
    FILE *arq;
    arq = fopen("lutadores.txt", "r");
    fscanf(arq,"%d", n);

    Lutador *lutadores = (Lutador*) malloc(sizeof(Lutador) * *n);

    for(int i = 0; i < *n; i++){
        lutadores[i].nome = (char *) malloc(sizeof(char) * 11);
        fscanf(arq,"%s %d %d", lutadores[i].nome, 
            &lutadores[i]. vitalidade, &lutadores[i].dano_maximo);



    }

    fclose(arq);
    return lutadores;
}

void ataque(Lutador *atacante, Lutador *alvo){

int dano = 0;
dano = randint(1, atacante->dano_maximo);

alvo->vitalidade -= dano;

}

void eliminaLutador(Lutador v[], int ferido, int *n) {

    if(v[ferido].vitalidade <= 0){
        free(v[ferido].nome);
        v[ferido] = v[*n-1];
        (*n)--;
    }

}



void batalha() { 
 
   int n, l1, l2; 
 
   Lutador *lutadores = carrega_lutadores(&n); 
 
   while(n > 1) { //1 
 
      l1 = randint(0, n-1); 
 
      l2 = randint(0, n-1);
      if(l1 != l2) { 

         ataque(&lutadores[l1], &lutadores[l2]); 
 
         eliminaLutador(lutadores, l2, &n); 
 
         if(n == 1){ //1 
 
            printf("\nVencedor:%s", lutadores[0].nome); 
  } 
   } 
}
   free(lutadores[0].nome); 
 
   free(lutadores);
}      






int main() { 
 srand(time(NULL)); 
 char resp; 
 do { 
  batalha(); 
  printf("\nDe novo? (S/N)"); 
  fflush(stdin); 
  resp = getchar(); 
 } while(toupper(resp) == 'S'); 
 return 0; 
}