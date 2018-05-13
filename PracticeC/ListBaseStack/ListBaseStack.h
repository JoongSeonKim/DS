//
//  ListBaseStack.h
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 4..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#ifndef ListBaseStack_h
#define ListBaseStack_h

//#include "DB.h"
#include "Position.h"

#define TRUE 1
#define FALSE 0

//typedef BTreeNode* Data;
typedef Pos * Data;

typedef struct _node
{
    Data data;
    struct _node *next;
} Node;

typedef struct _listStack
{
    Node *head;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack *pstack);
int SIsEmpty(Stack *pstack);

void SPush(Stack *pstack, Data data);
Data SPop(Stack *pstack);
Data SPeek(Stack *pstack);

#endif /* ListBaseStack_h */



