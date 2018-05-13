//
//  CLinkedList.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 3..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List *plist)
{
    plist->tail = NULL;
    plist->cur = NULL;
    plist->before = NULL;
    plist->numofData = 0;
}

void LInsertFront(List *plist, LData data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    if(plist->tail == NULL)
    {
        plist->tail = newNode;
        newNode->next = newNode;
    }
    
    else
    {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
    }
    
    (plist->numofData)++;
}

void LInsert(List *plist, LData data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    if(plist->tail == NULL)
    {
        plist->tail = newNode;
        newNode->next = newNode;
    }
    
    else
    {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
        plist->tail = newNode; // newly added
    }
    
    (plist->numofData)++;
}

int LFirst(List *plist, LData *pdata)
{
    if(plist->tail->next == NULL) return FALSE;
    
    plist->before = plist->tail;
    plist->cur = plist->tail->next;
    
    *pdata = plist->cur->data;
    return TRUE;
}

int LNext(List *plist, LData *pdata)
{
    if(plist->tail == NULL) return FALSE;
    
    plist->before = plist->cur;
    plist->cur = plist->cur->next;
    
    *pdata = plist->cur->data;
    return TRUE;
}

LData LRemove(List *plist) // delete the data called just before
{
    Node *rpos = plist->cur;
    LData rdata = rpos->data;
    
    if(rpos == plist->tail)
    {
        if(plist->tail == plist->tail->next)
            plist->tail = NULL;
        
        else plist->tail = plist->before;
    }
    
    plist->before->next = plist->cur->next;
    plist->cur = plist->before;
    
    free(rpos);
    (plist->numofData)--;
    return rdata;
}

int LCount(List *plist)
{
    return plist->numofData;
}

