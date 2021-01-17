//
//  tdp.h
//
//  Created by Oliver Otcasek on 1/2/19.
//  Copyright © 2019 Oliver Otcasek. All rights reserved.
//

#ifndef tdp_h
#define tdp_h

#include <stdlib.h>
#include "run_rdt.h"


typedef struct Tree* tree;

struct TD_tree{
    int current;
    int length;
    Tree tree;
};
typedef struct TD_tree* td_parse_tree;

extern td_parse_tree new_TD_tree(char* input, int length);
extern int get_table(void);
extern void print_Tree(tree pt);
extern Tree tdp(char* input);

#endif /* tdp_h */
