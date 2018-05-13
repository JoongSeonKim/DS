//
//  CLLStack.h
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 4..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#ifndef CLLStack_h
#define CLLStack_h

#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

typedef struct _CLListStack
{
    Node *head;
} CLLStack;

typedef CLLStack Stack;

void StackInit(Stack *pstack);
int SIsEmpty(Stack *pstack);

void SPush(Stack *pstack, LData data);
LData SPop(Stack *pstack);
LData SPeek(Stack *pstack);

#endif /* CLLStack_h */
