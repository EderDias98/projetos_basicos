#ifndef TABELA_HASH_H
#define TABELA_HASH_H
#include <stdio.h>
#include <stdlib.h>

typedef struct node NODE;
typedef struct hash_table HASH_TABLE;



HASH_TABLE* create_table(int size);


void insert(HASH_TABLE* t, int key , int data );
    

int search(HASH_TABLE* t , int key);

void print_table(HASH_TABLE* t);


#endif