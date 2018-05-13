//
//  CLinkedList.h
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 3..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#ifndef CLinkedList_h
#define CLinkedList_h
// #include "Point.h"

#define TRUE 1
#define FALSE 0

typedef int LData;
//typedef Point* LData;

typedef struct _node
{
    LData data;
    struct _node *next;
} Node;

typedef struct _CLL
{
    Node *tail;
    Node *cur;
    Node *before;
    int numofData;
} CList;

typedef CList List;

void ListInit(List *plist);
void LInsert(List *plist, LData data);
void LInsertFront(List *plist, LData data);

int LFirst(List *plist, LData *pdata);
int LNext(List *plist, LData *pdata);

LData LRemove(List *plist);
int LCount(List *plist);



#endif /* CLinkedList_h */

