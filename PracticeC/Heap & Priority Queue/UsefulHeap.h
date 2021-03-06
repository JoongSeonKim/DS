//
//  UsefulHeap.h
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 8..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#ifndef UsefulHeap_h
#define UsefulHeap_h

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef int HData;
typedef int PriorityComp(HData d1, HData d2);

typedef struct _heap
{
    PriorityComp* comp;
    int numOfData;
    HData heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap *ph, PriorityComp pc);
int HIsEmpty(Heap *ph);

void HInsert(Heap *ph, HData data);
HData HDelete(Heap *ph);

#endif /* UsefulHeap_h */
