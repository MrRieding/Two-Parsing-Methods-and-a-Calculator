//
//  expr.c
//
//  Created by Oliver Otcasek on 1/2/19.
//  Copyright © 2019 Oliver Otcasek. All rights reserved.
//  The main file.

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "tdp.h"
#include "calculator.h"

int main(int argc, const char * argv[]) {
    /* The main function and the driver of the program. Allows the user to select
    what to do with an arithmetic expression. */


    printf("\n Input \"1\" to generate and print a recursive descent parser.\
    \n Input \"2\" to generate and print a table-driven parser.\
    \n Input \"3\" to use a calculator that uses the table-driven parser. \n" );
    int choice;
    scanf("%i", &choice);
    fflush(stdin);
    Tree tr2;

    printf("\nNow, please input an arithmetic expression, such as (2+2)/1 or 5*5, etc.\n");

    char input[100];
    fgets(input, 100, stdin);
    strtok(input, "\n");

    switch(choice){
        case 1: ;
            Parse_Tree pt = new_Parse_Tree(input, strlen(input));
            if(pt != NULL){
                print_Tree_indent(pt->tree->root, 0);
            }
            else perror("invalid expression.");
            free_Parser(pt);

            break;

        case 2: ;
            tr2 = tdp(input);
            print_tree(tr2, 0);
            free_Tree(tr2->root);
            break;

        case 3: ;

            tr2 = tdp(input);
            printf("\nresult: %i\n", calculate(tr2->root, 0));
            free_Tree(tr2->root);
            break;


            

            

    }
    return 0;
}
