//
//  RDT.h
//
//  Created by Oliver Otcasek on 1/2/19.
//  Copyright © 2019 Oliver Otcasek. All rights reserved.
//

#ifndef tree_h
#define tree_h

#include <stdio.h>
#include <stdbool.h>

typedef struct Tree* Tree;
typedef struct Node* Node;

struct Node{
    char data;
    bool is_terminal;
    Node left;
    Node right;
};

struct Tree{
    Node root;
};
 

extern Node new_Node(char c, bool is_terminal);

extern void print_tree(Tree tree, int count);
extern void print_Tree_indent(Node root, int count);
extern void free_Node(Node node);
extern Tree new_Tree(Node root);
extern void free_Tree(Node root);
extern void free_Parse_Tree(Tree tree);
extern Node get_Leaf(Node root);
extern bool is_terminal(char c);



#endif /* Tree_h */
