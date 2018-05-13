//
//  ArrayBaseStack.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 4..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

void StackInit(Stack * pstack)
{
    pstack->topIndex = -1;
}

int SIsEmpty(Stack * pstack)
{
    if(pstack->topIndex == -1) return TRUE;
    
    else return FALSE;
}

void SPush(Stack *pstack, Data data) // push data on top
{
    pstack->topIndex += 1;
    pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack *pstack) // Pop data on top
{
    int ridx;
    
    if(SIsEmpty(pstack))
    {
        printf("Stack Memory Error!");
        exit(-1);
    }
    
    ridx = pstack->topIndex;
    pstack->topIndex -=1;
    
    return pstack->stackArr[ridx];
}

Data SPeek(Stack *pstack) // Show data on top
{
    if(SIsEmpty(pstack))
    {
        printf("Stack Memory Error!");
        exit(-1);
    }
    
    return pstack->stackArr[pstack->topIndex];
}
