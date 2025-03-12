#include <stdio.h>
#include <math.h>


struct ponto{
    float x,y,r;
};

typedef struct ponto tPonto;

void DetectaColisao(tPonto alvo, tPonto disparo){
    float dist, dist_max;
    dist_max = alvo.r + disparo.r;
    dist = sqrt(pow((alvo.x- disparo.x),2) + pow((alvo.y - disparo.y),2));
    if(dist > dist_max){    
        printf("ERROU\n");
    }else {
        printf("ACERTOU\n");
    }
}


int main(int argc , char* argv[]){

    tPonto alvo;

    tPonto disparo;

    scanf("%f %f %f%*c", &alvo.x, &alvo.y, &alvo.r);
    scanf("%f %f %f%*c", &disparo.x, &disparo.y, &disparo.r);

    DetectaColisao(alvo, disparo);
    




    return 0;
}