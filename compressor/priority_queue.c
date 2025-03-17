#include "priority_queue.h"
#define TAM_MAX 256
struct priority_queue
{
    NODE** vet;
    int size;
};



PRIORITY_QUEUE* create_priority_queue(){
    PRIORITY_QUEUE* pq = (PRIORITY_QUEUE*) malloc(sizeof(PRIORITY_QUEUE));
    pq->vet = (NODE**) malloc(sizeof(NODE*)* TAM_MAX);
    pq->size = 0;
    return pq;
}
void enqueue_min(PRIORITY_QUEUE* pq, NODE* n){
    
    int i = pq->size;
    pq->vet[i] = n;
    pq->size++;

    //manter propiedades da heap
    int parent = (i-1)/2;
    
    while(i >0 && pq->vet[i]< pq->vet[parent]){
        
        NODE* temp = pq->vet[parent];
        pq->vet[parent] = pq->vet[i];
        pq->vet[i] = temp;

        i = parent;
        parent = (i-1)/2;
    }

}
NODE* dequeue_min(PRIORITY_QUEUE* pq){
    
    NODE* n = pq->vet[0];
    pq->vet[0] = pq->vet[pq->size-1];
    pq->size--;
    
    int i=0;
    int smaller_idx = i;
    while(1){
        int left_child = 2*i +1;
        int right_child = 2*i +2;

        if(left_child< pq->size && pq->vet[smaller_idx] > pq->vet[left_child]){
            smaller_idx = left_child;
        }

        if(right_child< pq->size && pq->vet[smaller_idx]> pq->vet[right_child]){
            smaller_idx = right_child;
        }
        if(i== smaller_idx ){
            break;
        }

        NODE* temp = pq->vet[i];
        pq->vet[i] = pq->vet[smaller_idx];
        pq->vet[smaller_idx] = temp;
        
        i = smaller_idx;


    }

    return n;
}

void print_priority_queue(PRIORITY_QUEUE* pq){
    for(int i=0; i< pq->size; i++){
        print_tree(pq->vet[i],0);
        printf("#\n\n");
    }
    printf("$\n\n\n");
}