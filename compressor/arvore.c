#include "arvore.h"

struct node{
    int fr;
    char chara;
    NODE* left_child;
    NODE* right_child;
};

NODE* create_node(int fr, char chara){
    NODE* n = (NODE*) malloc(sizeof(NODE));
    n->chara = chara;
    n->fr = fr;
    n->left_child = NULL;
    n->right_child = NULL;
    return n;
}

NODE* insert_node(NODE* root, int fr, int chara){
    if(root == NULL) return create_node(fr,chara);

    if(root->fr > fr){
        root ->left_child = insert_node(root->left_child,fr, chara);
    }
    if(root->fr < fr){
        root->right_child = insert_node(root->right_child,fr,chara);
    }

    return root;
}

void free_tree(NODE* root){
    if(root == NULL) return;
    free_tree(root->left_child);
    free_tree(root->right_child);
    free(root);
}
NODE* search_tree(NODE* root, int fr) {
    if (root == NULL || root->fr == fr) return root;
    if (fr < root->fr) return search_tree(root->left_child, fr);
    return search_tree(root->right_child, fr);
}

// Inorder traversal (Left, Root, Right)
void inorder(NODE* root) {
    if (root != NULL) {
        inorder(root->left_child);
        printf("%d ", root->fr);
        inorder(root->right_child);
    }
}

// Function to find the minimum node
NODE* findMin(NODE* root) {
    while (root->left_child != NULL) root = root->left_child;
    return root;
}

// Function to delete a node
NODE* deleteNode(NODE* root, int fr) {
    if (root == NULL) return root;

    if (fr < root->fr)
        root->left_child = deleteNode(root->left_child, fr);
    else if (fr > root->fr)
        root->right_child = deleteNode(root->right_child, fr);
    else {
        // NODE with only one child or no child
        if (root->left_child == NULL) {
            NODE* temp = root->right_child;
            free(root);
            return temp;
        } else if (root->right_child == NULL) {
            NODE* temp = root->left_child;
            free(root);
            return temp;
        }

        // NODE with two children: Get inorder successor (smallest in right_child subtree)
        NODE* temp = findMin(root->right_child);
        root->fr = temp->fr;
        root->right_child = deleteNode(root->right_child, temp->fr);
    }
    return root;
}

void print_tree(NODE* root,int niv){
    if(root == NULL) return;
    print_tree(root->left_child, niv+1);
    for(int i=0; i< niv;i++){
        printf(" ");
    }
    printf("%d\n", root->fr);
    print_tree(root->right_child, niv+1);
    return;
}