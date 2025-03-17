#ifndef BIT_MAP_H
#define BIT_MAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bit_map BIT_MAP;


char* get_vet_bitmap(BIT_MAP* bm);


int get_curr_idx_bitmap(BIT_MAP* bm);

BIT_MAP* create_bit_map(int size);
  

void set_idx_bit(BIT_MAP* bm, int value);

void write_bitmap(BIT_MAP* bm, int value);
int read_bit(char b, int idx);

void print_bitmap(BIT_MAP* bm);

void update_curr_idx_bitmap(BIT_MAP* bm, int idx);
#endif






