#ifndef QUEUE_H
#define QUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

typedef struct priority_queue PRIORITY_QUEUE;



PRIORITY_QUEUE* create_priority_queue();

void enqueue_min(PRIORITY_QUEUE* pq, NODE* n);

NODE* dequeue_min(PRIORITY_QUEUE* pq);

void print_priority_queue(PRIORITY_QUEUE* pq);
#endif