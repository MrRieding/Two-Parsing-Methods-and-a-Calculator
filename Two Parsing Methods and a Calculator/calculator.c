//
//  calculator.c
//
//  Created by Oliver Otcasek on 1/4/19.
//  Copyright © 2019 Oliver Otcasek. All rights reserved.
//  Calculates the value of a given parse tree.

#include "calculator.h"
#include <string.h>
#include "TDP.h"


bool ops(char c){
    switch(c){
        case '+':
        case '-':
        case '*':
        case '/':
            return true;
    }
    return false;
}


int divide(Node n, int result){
    /* A recursive function that divides by passing the result. */

    if(n->right->left->data == '/'){ //base case
                if(n->right->left->right->right->left->data != '/'){
                    if (n->right->left->right->left->data == '('){ 
                        //if '(' is found, traverse the tree and evaluate the inner expression.
                        result = result/calculate(n->right->left->right->left->right, result);
                        return result;
                    }
                    result = result/calculate(n->right->left->right, result);
                    return result;
                }

                else {

                    if (n->right->left->right->left->data == '('){
                        result = result/calculate(n->right->left->right->left->right, result);
                        result = divide(n->right->left->right, result);
                        return result;
                    }
                 
                    result = result/calculate(n->right->left->right->left, result);
                    result = divide(n->right->left->right, result);
                    return result;
                }

            } 

}

int multiply(Node n, int result){
    /* A recursive function that multiplies by passing the result (like the divide function). */

    if(n->right->left->data == '*'){ //base case
                if(n->right->left->right->right->left->data != '*'){
                    if (n->right->left->right->left->data == '('){
                        result = result*calculate(n->right->left->right->left->right, result);
                        return result;
                    }
                    result = result*calculate(n->right->left->right, result);
                    return result;
                }

                else {

                    if (n->right->left->right->left->data == '('){
                        result = result*calculate(n->right->left->right->left->right, result);
                        result = multiply(n->right->left->right, result);
                        return result;
                    }
                 
                    result = result*calculate(n->right->left->right->left, result);
                    result = multiply(n->right->left->right, result);
                    return result;
                }

            } 
    

}

int calculate(Node n, int result){
    /* The main recursive function that traverses the parse tree created by either of the parsers
    and returns the result of the calculation.*/

    char hold[128];
    switch(n->data){
            
        case 'E':
            return calculate(n->left, result);
            
            
        case 'T':
            if(!ops(n->right->left->data)) return calculate(n->left, result);

            if(n->right->left->data == '+'){
                return calculate(n->left, result) + calculate(n->right->left->right, result);
            }
            else if(n->right->left->data == '-'){
                return calculate(n->left, result) - calculate(n->right->left->right, result);
            }
            
            
        case 't':
            return calculate(n->left, result);
            
            
        case 'F': ;
        int num;
 
            if(n->left->data == '('){
                num = calculate(n->left->right, result);
            }

            else num = calculate(n->left, result);

            if(n->right->left->data == '*'){
                return multiply(n, num);
            }

            else if(n->right->left->data == '/'){
                return divide(n, num);
            }

            else return num;
 
        case 'f':
            return calculate(n->left, result);
            
        
        case 'n':
            return calculate(n->left, result);
            
        case 'N':
            return calculate(n->left, result);
            
        case 'D':
            if(n->right->left->data == 'e') return calculate(n->left, result);
            sprintf(hold, "%d%d", calculate(n->left, result), calculate(n->right, result)); //convert to number.
            return atoi(hold); 
            
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
            return atoi(&n->data); //atoi() takes a pointer as a parameter.
            
        default:
            break;
    }
    return result;
}
