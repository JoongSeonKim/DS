//
//  SimpleHeap.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 8..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "SimpleHeap.h"

void HeapInit(Heap *ph)
{
    ph->numOfData = 0;
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
        if(ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr)
            return GetRChildIDX(idx);
        
        else return GetLChildIDX(idx);
    }
}

void HInsert(Heap *ph, HData data, Priority pr)
{
    int idx = ph->numOfData+1;
    HeapElem nelem = {pr, data};
    
    while(idx != 1)
    {
        // compare new node / parent position of the new node
        if(pr < (ph->heapArr[GetParentIDX(idx)].pr))
        {
            // actual node change
            ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
            
            // renew idx to parent idx
            idx = GetParentIDX(idx);
        }
        
        else break;
    }
    
    ph->heapArr[idx] = nelem;
    ph->numOfData += 1;
}

HData HDelete(Heap *ph) // delete root of a Heap ph
{
    HData retData = (ph->heapArr[1]).data;
    HeapElem lastElem = ph->heapArr[ph->numOfData];
    
    int parentIdx = 1;
    int childIdx;
    
    while(childIdx = GetHiPriChildIDX(ph, parentIdx) )
    {
        if(lastElem.pr <= ph->heapArr[childIdx].pr) break;
        
        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;
    }
    
    ph->heapArr[parentIdx] = lastElem;
    ph->numOfData -= 1;
    
    return retData;
}
