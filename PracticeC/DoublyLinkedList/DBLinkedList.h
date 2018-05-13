//
//  DBLinkedList.h
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 4..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#ifndef DBLinkedList_h
#define DBLinkedList_h

#include "Slot2.h"

#define TRUE 1
#define FALSE 0

typedef Slot LData;

typedef struct _node
{
    LData data;
    struct _node * prev; //right side
    struct _node * next;
} Node;

typedef struct _DLinkedList
{
    Node * head;
    Node * cur;
    int numOfData;
} DBLinkedList;

typedef DBLinkedList List;

void ListInit(List *plist);
void LInsert(List *plist, LData data);

int LFirst(List *plist, LData *pdata);
int LNext(List *plist, LData *pdata);
int LPrevious(List *plist, LData *pdata);

int LCount(List *plist);

#endif /* DBLinkedList_h */
