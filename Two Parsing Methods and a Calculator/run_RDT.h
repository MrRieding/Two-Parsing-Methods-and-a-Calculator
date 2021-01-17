//
//  run_RDT.h
//
//  Created by Oliver Otcasek on 1/2/19.
//  Copyright © 2019 Oliver Otcasek. All rights reserved.
//

#ifndef run_RDT_h
#define run_RDT_h
#include <string.h>
#include "tree.h"

typedef struct Parse_Tree* Parse_Tree;

struct Parse_Tree{
    int length;
    int current;
    Tree tree;
};





#endif /* run_RDT_h */
extern char* next_char;
extern char lookahead(Parse_Tree);
extern bool is_next_Terminal(char c);
extern bool is_Digit(char c);
extern int pemdas(char c);
extern Parse_Tree new_Parse_Tree(char* input, int length);
extern Tree E(Parse_Tree pt);
extern void free_Parser(Parse_Tree tr);
extern Tree N(Parse_Tree pt);
extern Tree T(Parse_Tree pt);
extern Tree NT(Parse_Tree pt);
extern Tree TT(Parse_Tree pt);
extern Tree F(Parse_Tree pt);
extern Tree FT(Parse_Tree pt);
extern Tree D(Parse_Tree pt);
