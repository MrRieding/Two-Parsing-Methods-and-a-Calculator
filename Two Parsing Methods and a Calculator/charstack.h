//
//  charStack.h
//  Project 2
//
//  Created by Oliver Otcasek on 1/2/19.
//  Copyright © 2019 Oliver Otcasek. All rights reserved.
//

#ifndef charstack_h
#define charstack_h
#include <stdbool.h>
#include <stdio.h>




struct Stack_Node{
    char data;
    bool is_terminal;
    struct Stack_Node* next;
};

extern void push(char data);
extern bool is_empty();
extern char look();
extern void pop();



#endif /* charstack_h */
