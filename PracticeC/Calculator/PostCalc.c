//
//  PostCalc.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 7..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <ctype.h>
#include <string.h>
#include "PostCalc.h"
#include "ListBaseStack.h"

int EvalRPNExp(char exp[])
{
    Stack stack;
    int expLen = strlen(exp);
    int i;
    char tok, op1, op2;
    
    StackInit(&stack);
    
    for(i=0; i<expLen; i++)
    {
        tok = exp[i];
        
        if(isdigit(tok))
        {
            SPush(&stack, tok - '0');
        }
        
        else
        {
            op2 = SPop(&stack);
            op1 = SPop(&stack);
            
            switch(tok)
            {
                case '+':
                    SPush(&stack, op1+op2);
                    break;
                case '-':
                    SPush(&stack, op1-op2);
                    break;
                case '*':
                    SPush(&stack, op1*op2);
                    break;
                case '/':
                    SPush(&stack, op1/op2);
                    break;
            }
        }
    }
    return SPop(&stack);
}
