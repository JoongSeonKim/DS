//
//  DBLinkedListDummy.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 4..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedListDummy.h"

void ListInit(List *plist)
{
    plist->head = (Node*)malloc(sizeof(Node));
    plist->tail = (Node*)malloc(sizeof(Node));
    
    plist->head->next = NULL;
    plist->tail->prev = NULL;
    plist->head->next = plist->tail;
    plist->tail->prev = plist->head;
    
    plist->numOfData = 0;
}

void LInsert(List *plist, Data data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    newNode->next = plist->tail;
    newNode->prev = plist->tail->prev; // plist->head on first
    plist->tail->prev->next = newNode;
    plist->tail->prev = newNode;
    
    (plist->numOfData)++;
}

int LFirst(List *plist, Data *pdata)
{
    if(plist->head->next == plist->tail) return FALSE; // if list is empty, return FALSE
    
    plist->cur = plist->head->next;
    *pdata = plist->cur->data;
    
    return TRUE;
}

int LNext(List *plist, Data *pdata)
{
    if(plist->cur->next == plist->tail) return FALSE;
    
    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;
 
    return TRUE;
}

Data LRemove(List *plist)
{
    Node *rpos = plist->cur;
    Data ret = rpos->data;
    
    
    plist->cur->next->prev = plist->cur->prev; 
    plist->cur->prev->next = plist->cur->next;
    
    free(rpos);
    (plist->numOfData)--;
    
    return ret;
}

int LCount(List *plist)
{
    return plist->numOfData;
}
