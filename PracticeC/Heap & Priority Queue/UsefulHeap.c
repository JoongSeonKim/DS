//
//  UsefulHeap.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 8..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "UsefulHeap.h"


void HeapInit(Heap *ph, PriorityComp pc)
{
    ph->numOfData = 0;
    ph->comp = pc;
}

int HIsEmpty(Heap *ph)
{
    if(ph->numOfData == 0) return TRUE;
    
    else return FALSE;
}

int GetParentIDX(int idx)
{
    return idx/2;
}

int GetLChildIDX(int idx)
{
    return idx*2;
}

int GetRChildIDX(int idx)
{
    return GetLChildIDX(idx) + 1;
}

int GetHiPriChildIDX(Heap *ph, int idx)
{
    // there is now child for current idx
    if (GetLChildIDX(idx) > ph->numOfData) return 0;
    
    // left child only exist & last node of heap
    else if (GetLChildIDX(idx) == ph->numOfData) return GetLChildIDX(idx);
    
    // two child exists!
    else
    {
        if(ph->comp(ph->heapArr[GetLChildIDX(idx)], ph->heapArr[GetRChildIDX(idx)]) < 0)
            return GetRChildIDX(idx);
        
        else return GetLChildIDX(idx);
    }
}

void HInsert(Heap *ph, HData data)
{
    int idx = ph->numOfData+1;
    
    while(idx != 1)
    {
        // compare new node / parent position of the new node
        if(ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0 )
        {
            // actual node change
            ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
            
            // renew idx to parent idx
            idx = GetParentIDX(idx);
        }
        
        else break;
    }
    
    ph->heapArr[idx] = data;
    ph->numOfData += 1;
}

HData HDelete(Heap *ph)
{
    HData retData = ph->heapArr[1];
    HData lastData = ph->heapArr[ph->numOfData];
    
    int parentIdx = 1;
    int childIdx;
    
    while(childIdx = GetHiPriChildIDX(ph, parentIdx) )
    {
        if(ph->comp(lastData, ph->heapArr[childIdx]) >=0 ) break;
        
        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;
    }
    
    ph->heapArr[parentIdx] = lastData;
    ph->numOfData -= 1;
    
    return retData;
}
