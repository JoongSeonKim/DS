//
//  CLListStack.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 4..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include "CLListStack.h"

void StackInit(Stack *pstack)
{
    pstack->list = (List*)malloc(sizeof(List));
    ListInit(pstack->list);
}

int SIsEmpty(Stack *pstack)
{
    if(LCount(pstack->list) == 0) return TRUE;
    
    else return FALSE;
}

void SPush(Stack *pstack, LData data)
{
    LInsertFront(pstack->list, data);
}

LData SPop(Stack *pstack)
{
    LData rdata;
    LFirst(pstack->list, &rdata);
    LRemove(pstack->list);
    
    return rdata;
}

LData SPeek(Stack *pstack)
{
    return pstack->list->tail->data;
}


