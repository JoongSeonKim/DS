//
//  ListBaseStack.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 4..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"
#include "Position.h"

void StackInit(Stack *pstack)
{
    pstack->head = NULL;
}

int SIsEmpty(Stack *pstack)
{
    if(pstack->head == NULL) return TRUE;
    
    else return FALSE;
}


void SPush(Stack *pstack, Data data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    
    newNode->data = data; // save new data
    newNode->next = pstack->head; // newNode points previous head
    
    pstack->head = newNode; // now head is newNode.
}

Data SPop(Stack *pstack)
{
    Node *dNode;
    Data pdata;
    
    if(SIsEmpty(pstack))
    {
        printf("Stack Memory Error!");
        exit(-1);
    }
    
    dNode = pstack->head;
    pdata = pstack->head->data;
    
    pstack->head = pstack->head->next;
    free(dNode);
    
    return pdata;
}

Data SPeek(Stack *pstack)
{
    if(SIsEmpty(pstack))
    {
        printf("Stack Memory Error!");
        exit(-1);
    }

    return pstack->head->data;
}

