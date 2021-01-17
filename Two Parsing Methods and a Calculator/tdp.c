//
//  tdp.c
//
//  Created by Oliver Otcasek on 1/2/19.
//  Copyright © 2019 Oliver Otcasek. All rights reserved.
//
#include "charstack.h"
#include "tdp.h"
#include "tree.h"
#include "run_rdt.h"

char* next_terminal;




int** make_table(){
    //This table was created using the method of "first" and "follow."
    int table[8][17] =
        {{-1,-1,-1,-1,1,-1,1,1,1,1,1,1,1,1,1,1,-1},
            {2,19,-1,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0},
            {-1,-1,-1,-1,3,3,3,3,3,3,3,3,3,3,3,3,-1},
            {0,0,4,20,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0},
            {-1,-1,-1,-1,5,-1,7,7,7,7,7,7,7,7,7,7,-1},
            {-1,-1,-1-1,-1,-1,8,8,8,8,8,8,8,8,8,8,8,-1},
            {0,0,0,0,-1,0,7,7,7,7,7,7,7,7,7,7,0},
            {-1,-1,-1,-1,-1,-1,9,10,11,12,13,14,15,16,17,18,-1}};
            
            int** t = (int**)malloc(8*sizeof(int*));
            for(int i = 0; i < 8; i++){
                t[i] = (int*)malloc(17*sizeof(int));
                for(int j = 0; j < 17; j++){
                    t[i][j] = table[i][j];
                    
                }
            }
            
            return t;
}

void free_table(int** table){
    for(int j = 0; j < 8; j++){
        free(table[j]);
    }
    free(table);
}



int pos = 0;
td_parse_tree new_TD_tree(char* input, int length){
    td_parse_tree pt = (td_parse_tree)malloc(sizeof(struct TD_tree));
    next_terminal = input;
    pt->current = 0;
    pt->length = length;
    pt->tree = new_Tree(new_Node('E', false));
    //evaluate here.
    return pt;
}

bool match_terminal_tdp(char c){
    if(*next_terminal == c){
        next_terminal++;
        return true;
    }
    else return false;
}

char lookahead_tdp(td_parse_tree pt){
    if(pt->current < pt->length){
        return *next_terminal;
    }
    return '\0';
}

int pnum(char c){ // get column number.
    if(c == 0){ // $
        return 16;
    }
    switch(c){
        case '+':
            return 0;
            break;
        case '-':
            return 1;
            break;
        case '*':
            return 2;
            break;
        case '/':
            return 3;
            break;
        case '(':
            return 4;
            break;
        case ')':
            return 5;
            break;
        case '0':
            return 6;
            break;
        case '1':
            return 7;
            break;
        case '2':
            return 8;
            break;
        case '3':
            return 9;
            break;
        case '4':
            return 10;
            break;
        case '5':
            return 11;
            break;
        case '6':
            return 12;
            break;
        case '7':
            return 13;
            break;
        case '8':
            return 14;
            break;
        case '9':
            return 15;
            break;
        default:
            perror("Parse error: a terminal which cannot be parsed has been found, or you forgot to close open parentheses.");
            exit(EXIT_FAILURE);
            return -1;
            
    }
    
}

void prod(int i, td_parse_tree pt) {
    // A function that builds the actual structure of a parse tree.

    Node n = get_Leaf(pt->tree->root);

    switch(i){

        case 0: // epsilon production
            n->left = new_Node('e', true);
            break;
            

        case 1:
            n->left = new_Node('T', false);
            n->left->right = new_Node('t', false);
            push('T');
            push('t');
            break;
           

        case 2:
            n->left = new_Node('+', true);
            n->left->right = new_Node('T', true);
            n->left->right->right = new_Node('t', true);
            push('T');
            push('t');
            push('+');
            break;
            

        case 3:
            n->left = new_Node('F', false);
            n->left->right = new_Node('f', false);
            push('F');
            push('f');
            break;
            

        case 4:
            n->left = new_Node('*', true);
            n->left->right = new_Node('F', false);
            n->left->right->right = new_Node('f', true);
            push('F');
            push('f');
            push('*');
            break;
           

        case 5:
            n->left = new_Node('(', true);
            n->left->right = new_Node('E', false);
            n->left->right->right = new_Node(')', true);
            push(')');
            push('E');
            push('(');
            break;
            

        case 6:
            n->left = new_Node('e', true);
            break;
            

        case 7:
            n->left = new_Node('N', false);
            push('n');
            break;
            

        case 8:
            n->left = new_Node('D', false);
            n->left->right = new_Node('n', false);
            push('N');
            push('D');
            break;
            

        case 9:
            n->left = new_Node('0', true);
            push('0');
            break;
           

        case 10:
            n->left = new_Node('1', true);
            push('1');
            break;
            

        case 11:
            n->left = new_Node('2', true);
            push('2');
            break;
            

        case 12:
            n->left = new_Node('3', true);
            push('3');
            break;
            

        case 13:
            n->left = new_Node('4', true);
            push('4');
            break;
            

        case 14:
            n->left = new_Node('5', true);
            push('5');
            break;
            

        case 15:
            n->left = new_Node('6', true);
            push('6');
            break;
            

        case 16:
            n->left = new_Node('7', true);
            push('7');
            break;
            

        case 17:
            n->left = new_Node('8', true);
            push('8');
            break;
            

        case 18:
            n->left = new_Node('9', true);
            push('9');
            break;
            

        case 19:
            n->left = new_Node('-', true);
            n->left->right = new_Node('T', false);
            n->left->right->right = new_Node('t', false);
            push('T');
            push('t');
            push('-');
            break;
            
            
        case 20:
            n->left = new_Node('/', true);
            n->left->right = new_Node('F', false);
            n->left->right->right = new_Node('f', false);
            push('F');
            push('f');
            push('/');
            break;
            
            
        default:
            perror("Error: unparsable input symbol found.");
            exit(EXIT_FAILURE);
            break;
            
            
            
    }
}






Tree tdp(char* input){
    /*A function that creates the table-driven parser table and begins
    executing the parser. */

    int** table = make_table();
    td_parse_tree pt = new_TD_tree(input, (int)strlen(input));
    push('E');
   
    
    
    while(!is_empty()){
        char c = *next_terminal;
        int production = 1;
        char state = look(); // stack node
        pop();
        
       
        
        if(is_terminal(state)) {
            if(*next_terminal != state){
                perror("Parentheses error");
                exit(EXIT_FAILURE);
            }
        }
        
        
        
        if(!match_terminal_tdp(state)){
        switch(state){
            case 'E':
                production = table[0][pnum(c)]; // row 0, column pnum(c).
                prod(production, pt);
                break;
            case 'T':
                production = table[1][pnum(c)];
                prod(production, pt);
                break;
                
            case 't':
                production = table[2][pnum(c)];
                prod(production, pt);
                break;
                
            case 'F':
                production = table[3][pnum(c)];
                prod(production, pt);
                break;
                
            case 'f':
                production = table[4][pnum(c)];
                prod(production, pt);
                break;
                
            case 'n':
                production = table[5][pnum(c)];
                prod(production, pt);
                break;
                
            case 'N':
                production = table[6][pnum(c)];
                prod(production, pt);
                break;
                
            case 'D':
                production = table[7][pnum(c)];
                prod(production, pt);
                break;
                
            }
            //print_stack(st);
            //printf("\n");
        }
        
        
        
        
    }
    
    if(*next_terminal != 0){
        perror("Parse error");
        exit(EXIT_FAILURE);
        
    }
    
    free_table(table);
    return pt->tree;
}



