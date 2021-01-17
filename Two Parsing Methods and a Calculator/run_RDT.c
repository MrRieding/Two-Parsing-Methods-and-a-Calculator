//
//  run_RDT.c
//
//  Created by Oliver Otcasek on 1/2/19.
//  Copyright © 2019 Oliver Otcasek. All rights reserved.
//
// Recursive functions based on provided grammar from Foundations of Computer Science by Aho and Ullman.

/* <E> → <T> <TT> <TT> → +- <T> <TT>|ε
 <T> → <F> <FT> <FT> →  <F> <FT>|ε
<F > → <N > | ( <E > ) <N> → <D> <NT>
<NT> →<N>|ε <D> → 0|1|···|9
*/

#include "run_RDT.h"
#include <string.h>
#include <stdlib.h>

char* next;

char lookahead(Parse_Tree pt){
    //look without consuming next terminal.
    if(pt->current < pt->length){
        return *next;
    }
    return '\0'; //null char.
}

Parse_Tree new_Parse_Tree(char* input, int length){
    Parse_Tree pt = (Parse_Tree)malloc(sizeof(struct Parse_Tree));
    next = input;
    pt->current = 0;
    pt->length = length;
    pt->tree = E(pt);
    
    
    if(is_next_Terminal(0)){
        return pt;
    }
    else{
        perror("Parse error: probably inproper parentheses");
        exit(EXIT_FAILURE);
    }
    
}

void free_Parser(Parse_Tree pt){
    if(pt != NULL){
        free_Tree(pt->tree->root);
        free(pt);
    }
}



bool is_Digit(char c){
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
            return true;
            break;
    }
    return false;
}



bool is_next_Terminal(char c){
    if(*next == c){ // if it is next, consume it.
        next++;
        return true;
    }
    else return false;
}

//Now for the recursion...

Tree NT(Parse_Tree pt){ // N or epsilon.
    Tree tree = new_Tree(new_Node('n', false));
    if(is_Digit(lookahead(pt))){
        Tree t = N(pt);
        if(t == NULL) return NULL;
        tree->root->left = t->root;
    }
    else{
        tree->root->left = new_Node('e', true); // epsilon
    }
    return tree;
}

Tree N(Parse_Tree pt){ // D or NT
    Tree tree = new_Tree(new_Node('N', false));
    Tree t = D(pt);
    if(t == NULL) return NULL;
    Tree t2 = NT(pt);
    if(t2 == NULL) return NULL;
    tree->root->left = t->root;
    tree->root->left->right = t2->root;
    return tree;
}



Tree F(Parse_Tree pt){ // N or (E)
    Tree tree = new_Tree(new_Node('F', false));
    if(is_next_Terminal('(')){ // A number or an expression in parentheses.
        Tree t1 = E(pt);
        
        if((t1 == NULL) || !(is_next_Terminal(')'))){
            perror("Invalid input. Stranded parentheses");
            exit(EXIT_FAILURE);
            
        }
        
        tree->root->left = new_Node('(', true);
        tree->root->left->right = t1->root;
        tree->root->left->right->right = new_Node(')', true);
    }
    else {
        Tree t2 = N(pt);
        if(t2 == NULL) return NULL;
        tree->root->left = t2->root;
    }
    return tree;
    
}

Tree T(Parse_Tree pt){ //F or FT
    Tree tree = new_Tree(new_Node('T', false));
    Tree t = F(pt);
    if(t == NULL) return NULL;
    Tree t1 = FT(pt);
    if(t1 == NULL) return NULL;
    tree->root->left = t->root;
    tree->root->left->right = t1->root;
    return tree;
}

Tree E(Parse_Tree pt){ // T or TT
    /* These productions are taken from the project pdf.
    They are just literally copied in code here.
    */
    Tree tree = new_Tree(new_Node('E', false));
    
    Tree t = T(pt);
    if(t == NULL) return NULL;
    
    Tree t1 = TT(pt);
    if(t1 == NULL) return NULL;
    
    tree->root->left = t->root;
    tree->root->left->right = t1->root;
    return tree;
    
}

Tree TT(Parse_Tree pt){
    Tree tree = new_Tree(new_Node('T', false));
    char c = lookahead(pt);
    if(is_next_Terminal('+') || is_next_Terminal('-')){
        Tree t = T(pt);
        if(t == NULL) return NULL;
        Tree t2 = TT(pt);
        if(t2 == NULL) return NULL;
        tree->root->left = new_Node(c, true);
        tree->root->right = t->root;
        tree->root->right->right = t2->root;
    }
    else tree->root->left = new_Node('e', true);
    return tree; //oops. Don't return "t"!
}

Tree FT(Parse_Tree pt){
    Tree tree = new_Tree(new_Node('f', false));
    char c = lookahead(pt);
    if(is_next_Terminal('*') || is_next_Terminal('/')){
        Tree t1 = F(pt);
        if(t1 == NULL) return NULL;
        Tree t2 = FT(pt);
        if(t2 == NULL) return NULL;
         
        tree->root->left = new_Node(c, true);
        tree->root->left->right = t1->root;
        tree->root->left->right->right = t2->root;
        return tree;
    }
    else {
        
        tree->root->left = new_Node('e', true);
        return tree;
        }
    
}

Tree D(Parse_Tree pt){
    Tree tree = new_Tree(new_Node('D', false));
    char c = lookahead(pt);
    if(!is_terminal(c)){
        perror("Invalid input. Cannot be parsed");
        exit(EXIT_FAILURE);
    }
    switch(c){
        case '0':
            is_next_Terminal('0');
            tree->root->left = new_Node(c, true);
            break;
        case '1':
            is_next_Terminal('1');
            tree->root->left = new_Node(c, true);
            break;
        case '2':
            is_next_Terminal('2');
            tree->root->left = new_Node(c, true);
            break;
        case '3':
            is_next_Terminal('3');
            tree->root->left = new_Node(c, true);
            break;
        case '4':
            is_next_Terminal('4');
            tree->root->left = new_Node(c, true);
            break;
        case '5':
            is_next_Terminal('5');
            tree->root->left = new_Node(c, true);
            break;
        case '6':
            is_next_Terminal('6');
            tree->root->left = new_Node(c, true);
            break;
        case '7':
            is_next_Terminal('7');
            tree->root->left = new_Node(c, true);
            break;
        case '8':
            is_next_Terminal('8');
            tree->root->left = new_Node(c, true);
            break;
        case '9':
            is_next_Terminal('9');
            tree->root->left = new_Node(c, true);
            break;
        default:
            return NULL;
            break;
    }
    return tree;
}
