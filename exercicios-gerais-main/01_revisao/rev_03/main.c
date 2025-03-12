#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* vet;
    int tam;
    int capacidade;
}ListaDinamica;

ListaDinamica* IniciaLista(int capacidade_inicial){
    ListaDinamica* lista = (ListaDinamica* ) malloc(sizeof(ListaDinamica));
    lista->vet = (int*) malloc(sizeof(int)*capacidade_inicial);
    lista->tam =0;
    lista->capacidade = capacidade_inicial;
}

void AddLista( ListaDinamica* lista, int valor){
    if(lista->tam == lista->capacidade){
        lista->capacidade *=2;
        lista->vet = realloc(lista->vet, sizeof(int)* lista->capacidade);
    }
    lista->vet[lista->tam++] = valor;
}

void DestroiListaDinamica(ListaDinamica* lista){
    if(lista){
        free(lista->vet);
        free(lista);
    }
}



int main(){

    ListaDinamica* lista = IniciaLista(4);
    scanf("%*c%*c");
    int valor;
    while(scanf("%d%*c",&valor) >0){
        AddLista(lista,valor);
    }

    



    return 0;
}