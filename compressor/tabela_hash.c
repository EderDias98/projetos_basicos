#include "tabela_hash.h"


struct node{
    int data;
    int key;
    NODE* next;
};

struct hash_table{
    NODE** vet;
    int size;
};

void start_hash_table(HASH_TABLE* t){
    for( int i=0; i< t->size; i++){
        t->vet[i] = NULL;
    }
}

HASH_TABLE* create_table(int size){
    HASH_TABLE* t = (HASH_TABLE*) malloc( sizeof( HASH_TABLE));
    t->vet = (NODE**) malloc(sizeof(NODE*)*size);
    t->size = size;
    start_hash_table(t);
    return t;
}
int get_size(HASH_TABLE* t){
    return t->size;
}
int hash(int key, HASH_TABLE* t){
    return key % t->size;
   
}
void insert(HASH_TABLE* t, int key , int data ){
    
    NODE* n =(NODE*) malloc(sizeof( NODE));
    n->data = data;
    n->key = key;
    n->next = NULL;
    int i = hash(n->key,t);
    // insere no inicio da lista
    n->next = t->vet[i];
    t->vet[i]= n;
}

int search(HASH_TABLE* t , int key){
    int i = hash(key, t);
    NODE* curr = t->vet[i];
    while(curr!=NULL){
        if(curr->key == key)
            return curr->data;
        curr = curr->next;
    }
    return -1;
}
void print_table(HASH_TABLE* t){
    for( int i=0; i< t->size; i++){
        NODE* cur = t->vet[i];
        while(cur !=NULL){
            printf("%d ", cur->data);
            cur =  cur->next;
        }
    }
    printf("\n");
}