//
//  charStack.c
//
//  Created by Oliver Otcasek on 1/2/19.
//  Copyright © 2019 Oliver Otcasek. All rights reserved.
//  A specialized stack for a table driven parser.

#include "charstack.h"
#include <stdlib.h>


struct Stack_Node* top;


void push(char data){
    struct Stack_Node* temp = (struct Stack_Node*)malloc(sizeof(struct Stack_Node));
    if(!temp){
        printf("Stack error!");
        exit(1);
    }
    temp->data = data;
    temp->next = top;
    top = temp;
}

bool is_empty(){
    return top==NULL;
}

char look(){
    if(!is_empty()){
        return top->data;
    }
    else exit(1);
}

void pop(){
    struct Stack_Node* temp;
    if(top==NULL){
        printf("Stack error.");
        exit(1);
    }
    else {
        temp = top;
        top = top->next;
        temp->next = NULL;
        free(temp);
    }
    
}
    




