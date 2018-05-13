//
//  DBLinkedListDummy.h
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 4..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#ifndef DBLinkedListDummy_h
#define DBLinkedListDummy_h

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
    Data data;
    struct _node * prev; //right side
    struct _node * next;
} Node;

typedef struct _dbDLinkedList
{
    Node * head;
    Node * tail;
    Node * cur;
    int numOfData;
} DBLinkedList;

typedef DBLinkedList List;

void ListInit(List *plist);
void LInsert(List *plist, Data data);

int LFirst(List *plist, Data *pdata);
int LNext(List *plist, Data *pdata);

Data LRemove(List *plist);
int LCount(List *plist);

#endif /* DBLinkedList_h */
