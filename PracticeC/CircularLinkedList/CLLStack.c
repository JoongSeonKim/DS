//
//  CLLStack.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 4..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include "ListBaseStack.h"

void StackInit(Stack *pstack)
{
    pstack->head = NULL;
}

int SIsEmpty(Stack *pstack)
{
    if(pstack->head == NULL) return TRUE;
    
    else return FALSE;
}

void SPush(Stack *pstack, LData data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    newNode->next = pstack->head;
    pstack->head = newNode;
}

LData SPop(Stack *pstack)
{
    if(SIsEmpty(pstack))
    {
        printf("Stack Memory Error!");
        exit(-1);
    }
    
    LData pdata;
    Node *rNode;
    
    pdata = pstack->head->data;
    rNode = pstack->head;
    
    pstack->head = pstack->head->next;
    free(rNode);
    
    return pdata;
}

LData SPeek(Stack *pstack)
{
    if(!SIsEmpty(pstack))
    {
        printf("Stack Memory Error!");
        exit(-1);
    }
    
    return pstack->head->data;
}
