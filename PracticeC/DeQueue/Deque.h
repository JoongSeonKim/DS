//
//  Deque.h
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 7..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#ifndef Deque_h
#define Deque_h

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
    Data data;
    struct _node *next;
    struct _node *prev;
} Node;

typedef struct _dlDeque
{
    Node *head;
    Node *tail;
} DLDeque;

typedef DLDeque Deque;

void DequeInit(Deque *pdeq);
int DQIsEmpty(Deque *pdeq);

void DQAddFirst(Deque *pdeq, Data data);
void DQAddLast(Deque *pdeq, Data data);

Data DQRemoveFirst(Deque *pdeq);
Data DQRemoveLast(Deque *pdeq);

Data DQGetFirst(Deque *pdeq);
Data DQGetLast(Deque *pdeq);

#endif /* Deque_h */
