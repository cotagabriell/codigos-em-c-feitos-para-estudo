#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_Y 400
#define TAM_X 800
#define LINHAS 8
#define COLUNAS 20
int largura_tile = TAM_X / COLUNAS;
int altura_tile = TAM_Y / LINHAS;


typedef struct Tile {
  int investigado;
  int premio;
} Tile;

typedef struct Jogador {
  int vidas;
  int pontuacao;
} Jogador;

typedef struct Coord {
    int x;
    int y;

} Coord;


void geraTile(Tile *t,int min, int max){

    t->investigado = 0;
    t->premio = min + rand()%(max+1 - min);

}

void geraGrid(Tile t[LINHAS][COLUNAS]){
    for(int i = 0; i < LINHAS; i++){
        for(int j = 0; j < COLUNAS; j++){
                geraTile(&t[i][j], 0, 10);
        }
    }
}

void geraJogador(Jogador *p){
    p->vidas = 3;
    p->pontuacao = 0;
}

int existePremio(Tile t[LINHAS][COLUNAS]){
    for(int i = 0; i < LINHAS; i++){
        for(int j = 0; j < COLUNAS; j++){
            if(!(t[i][j].investigado) && t[i][j].premio > 0){
                return 1;
            }
        }
    }

    return 0;

}

void tentivapx(Jogador *p, Coord *d, Tile g[LINHAS][COLUNAS]){
    d->x = 0;
    d->y = 0;
        printf("\nDiga a coordenada que voce deseja cavar: ");
        scanf("%d %d", &d->x, &d->y);

    if(d->x >= 0 && d->x < TAM_X && d->y >= 0 && d->y < TAM_Y)    {
    
        if(!g[d->y/altura_tile][d->x/largura_tile].investigado){

            g[d->y/altura_tile][d->x/largura_tile].investigado = 1;
            p->pontuacao += g[d->y/altura_tile][d->x/largura_tile].premio;


                if(g[d->y/altura_tile][d->x/largura_tile].premio > 0){
                          printf("\nEureca!!! Premio encontrado: %d || Saldo do jogador: %d\n",  
             g[d->y/altura_tile][d->x/largura_tile].premio, p->pontuacao); }
                else {
                        printf("\nVoce cavou, mas infelizmente nao havia nada la... Premio encontrado: %d || Saldo do jogador: %d\n",  
                     g[d->y/altura_tile][d->x/largura_tile].premio, p->pontuacao);
                    } 

    }
    
        else {
             p->vidas--;
             printf("\nTesouro ja encontrado, -1 vida. Vida total: %d\n", p->vidas);
    }
    }
    else{
        p->vidas--;
        printf("\nCoordenadas invalidas, -1 vida. Vida total: %d\n", p->vidas);
    }



}


int main(){
    srand(time(NULL));
    Tile grid[LINHAS][COLUNAS];
    Jogador p1;
    Jogador p2;
    geraGrid(grid);
    geraJogador(&p1);
    geraJogador(&p2);
    Coord c;

    

    while((p1.vidas && p2.vidas) && (existePremio(grid))){
        printf("\nP1 TURN\n\n");
        tentivapx(&p1, &c, grid);

        if(!p1.vidas || !existePremio(grid)) break;

        printf("\nP2 TURN\n\n");
        tentivapx(&p2, &c, grid);

    }
    getchar();
    if(!existePremio(grid)){
        printf("\nParabens!!!! Voces encontraram todos os tesouros!");
    }
    else{
        if(!p1.vidas){
            printf("\nGame over. O Jogador 1 perdeu todas as suas vidas");
        }
        else {
            printf("\nGame over. O Jogador 2 perdeu todas as suas vidas");
        }
    }

    getchar();

    return 0;
}