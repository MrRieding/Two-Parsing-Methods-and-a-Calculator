//
//  RDT.c
//
//  Created by Oliver Otcasek on 1/2/19.
//  Copyright © 2019 Oliver Otcasek. All rights reserved.
//
// Parse Tree

#include <stdlib.h>
#include "tree.h"

bool isLeaf(Node n){ // Is this node a leaf? Important for recursion.
    if(n->left == NULL && n->right==NULL) return true;
    else return false;
}

Node new_Node(char c, bool is_terminal){ // Allocating node.
    Node new = (Node)malloc(sizeof(struct Node)); // must be size of struct. Otherwise, there will be a bad access.
    new->data = c;
    new->is_terminal = is_terminal;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void free_Node(Node n){
    free(n);
}

Tree new_Tree(Node root){
    Tree new = (Tree)malloc(sizeof(struct Tree)); // struct needed.
    new->root = root;
    return new;
}

void free_Tree(Node root){ // recursively free the tree.
    if(root->left != NULL){
        free_Tree(root->left);
    }
    if(root->right != NULL){
        free_Tree(root->right);
    }
    free_Node(root);
}

void free_Parse_Tree(Tree tree){
    //free the tree and the helper structure.
    free_Tree(tree->root);
    free(tree);
}

bool is_terminal(char c){ // Check if a given char is an acceptable terminal. If not, return false for an error.
    switch(c){
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '+':
        case '-':
        case '/':
        case '*':
        case 'e':
        case '(':
        case ')':
            return true;
            break;
            
    }
    return false;
}



void print_Tree_indent(Node root, int count){
    if(root==NULL) return;
    else{
        for(int i = 1; i < count; i++){
            printf(" ");
        }
        
        printf("%c\n", root->data); //% or %i?
        
        
    }
    print_Tree_indent(root->left, count+1);
    print_Tree_indent(root->right, count);
}

void print_tree(Tree pt, int count){
    print_Tree_indent(pt->root, 0);
    printf("\n");
}

Node get_Leaf(Node root){
    if(root->left!=NULL){
        Node n = get_Leaf(root->left);
        if(n != NULL) return n;
    }
    else if(!is_terminal(root->data) && root->data != 'e'){
        return root;
    }
    if(root->right != NULL){
        Node n1 = get_Leaf(root->right);
        if (n1 != NULL) return n1;
    }
    
    return NULL;
}

