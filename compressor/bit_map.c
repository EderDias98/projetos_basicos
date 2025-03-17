#include "bit_map.h"

struct bit_map{
    int size; // quatidade de bytes
    char* vet;
    int cur_idx;
};

void update_curr_idx_bitmap(BIT_MAP* bm, int idx){
    bm->cur_idx = idx;
}

char* get_vet_bitmap(BIT_MAP* bm){
    return bm->vet;
}

int get_curr_idx_bitmap(BIT_MAP* bm){
    return bm->cur_idx;
}

BIT_MAP* create_bit_map(int size){
    BIT_MAP* bm = (BIT_MAP*) malloc(sizeof(BIT_MAP));
    bm->size = size;
    bm->vet= (char*) malloc(sizeof(char)*(size));
    bm->cur_idx = 0;
    memset(bm->vet,0,size);
    return bm;
}

void set_idx_bit(BIT_MAP* bm, int value){
    int byte_idx = bm->cur_idx/8;
    int bit_indx = 7-(bm->cur_idx%8);

    if(value == 1){
        bm->vet[byte_idx] |= 1<< bit_indx;
    }else if(value == 0){
        bm->vet[byte_idx] &= ~(1 << bit_indx);
    }
}

void write_bitmap(BIT_MAP* bm, int value){

    if(bm->cur_idx /8 == bm->size){
        bm->size = 2*bm->size;
        bm->vet = realloc(bm->vet,(bm->size)*sizeof(char));
        memset(bm->vet + (bm->size),0, bm->size/2);
        
    }
    
    set_idx_bit(bm, value);
    bm->cur_idx++;
}

int read_bit(char b, int idx){
    int ans = 0;
    ans = b & (1<< (7-idx));
    return ans!=0;
}
int read_bitmap(BIT_MAP*bm){
    int byte_idx = bm->cur_idx/8;
    int bit_idx = (bm->cur_idx%8);
    if(byte_idx+1 > bm->size){
        return -1;
    }
    bm->cur_idx++;
    return read_bit(bm->vet[byte_idx], bit_idx);
} 

void write_byte(BIT_MAP* bm, char b){

    for(int i=0; i<8; i++){
        write_bitmap(bm, read_bit(b,i));
    }
}
void print_bitmap(BIT_MAP* bm){
    for(int i=0; i< (bm->size*8); i++){
        printf("%d ", read_bitmap(bm));
    }
    printf("\n");
}