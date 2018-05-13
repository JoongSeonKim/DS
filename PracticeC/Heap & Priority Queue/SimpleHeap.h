//
//  SimpleHeap.h
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 8..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#ifndef SimpleHeap_h
#define SimpleHeap_h

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef char HData;
typedef int Priority;

typedef struct _heapElem
{
    Priority pr; // small pr has high priority
    HData data;
} HeapElem;

typedef struct _heap
{
    int numOfData;
    HeapElem heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap *ph);
int HIsEmpty(Heap *ph);

void HInsert(Heap *ph, HData data, Priority pr);
HData HDelete(Heap *ph);

#endif /* SimpleHeap_h */
