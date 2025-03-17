#ifndef ARVORE_H
#define ARVORE_H
#include <stdio.h>
#include <stdlib.h>
typedef struct node NODE;
NODE* create_node(int fr, char chara);

NODE* insert_node(NODE* root, int fr, int chara);
 
void free_tree(NODE* root);

NODE* search_tree(NODE* root, int fr);
// Inorder traversal (Left, Root, Right)
void inorder(NODE* root);
  
// Function to find the minimum node
NODE* findMin(NODE* root);


// Function to delete a node
NODE* deleteNode(NODE* root, int fr);

void print_tree(NODE* root,int niv);

#endif