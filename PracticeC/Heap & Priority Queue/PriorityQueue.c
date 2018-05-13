//
//  PriorityQueue.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 8..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include "PriorityQueue.h"
#include "UsefulHeap.h"

void PQueueInit(PQueue *ppq, PriorityComp pc)
{
    HeapInit(ppq, pc);
}

int PQIsEmpty(PQueue *ppq)
{
    return HIsEmpty(ppq);
}

void PEnqueue(PQueue *ppq, PQData data)
{
    HInsert(ppq, data);
}

PQData PDequeue(PQueue *ppq)
{
    return HDelete(ppq);
}
