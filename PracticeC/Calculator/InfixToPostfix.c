//
//  InfixToPostfix.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 6..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ListBaseStack.h"

#include "InfixToPostfix.h"

int GetOpPrec(int op)
{
    switch(op)
    {
        case '*':
        case '/':
            return 5; // highest
            
        case '+':
        case '-':
            return 3;
            
        case '(':
            return 1; // lowest
    }
    
    return -1; // if operator is not on the calc
}

int WhoPrecOp(char op1, char op2)
{
    int op1Prec = GetOpPrec(op1);
    int op2Prec = GetOpPrec(op2);
    
    if(op1Prec>op2Prec) return 1;
    
    else if(op1Prec<op2Prec) return -1;
    
    else return 0;
}

void ConvToRPNExp(char exp[])
{
    Stack stack;
    int expLen = strlen(exp);
    char * convExp = (char*)malloc(expLen+1);
    
    int i, idx = 0;
    char tok, popOp;
    
    memset(convExp, 0, sizeof(char)*expLen+1);
    StackInit(&stack);
    
    for(i=0; i<expLen; i++)
    {
        tok = exp[i];
        
        if(isdigit(tok))
        {
            convExp[idx++] = tok; // if tok = number -> save it directly
        }
        
        else
        {
            switch(tok)
            {
                case '(' :
                    SPush(&stack, tok);
                    break;
                    
                case ')' :
                    while(1)
                    {
                        popOp = SPop(&stack);
                        
                        if(popOp == '(') break; // break while(1)
                        convExp[idx++] = popOp;
                    }
                    break;
                    
                case '+': case '-':
                case '*': case '/':
                    while(!SIsEmpty(&stack) &&
                          (WhoPrecOp(SPeek(&stack), tok) >= 0) )
                    {
                        convExp[idx++] = SPop(&stack);
                    }
                    
                    SPush(&stack, tok);
                    break;
            }
        }
    }
    
    while(!SIsEmpty(&stack))
    {
        convExp[idx++] = SPop(&stack);
    }
        strcpy(exp, convExp);
        free(convExp);
    
}


