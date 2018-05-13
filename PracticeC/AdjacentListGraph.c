//
//  AdjacentListGraph.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 13..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "AdjacentListGraph.h"

int WhoIsPrecede(int data1, int data2)
{
    if(data1 < data2) return 0;
    
    else return 1;
}

void GraphInit(ALGraph *pg, int nv)
{
    int i;
    
    pg->adjList = (List*)malloc(sizeof(List)*nv);
    
    pg->numV = nv;
    pg->numE = 0;
    
    for(i=0; i<nv; i++)
    {
        ListInit(&(pg->adjList[i]));
        SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
    }
}

void GraphDestroy(ALGraph *pg)
{
    if(pg->adjList != NULL)
        free(pg->adjList);
}

void AddEdge(ALGraph *pg, int fromV, int toV)
{
    LInsert(&(pg->adjList[fromV]), toV);
    
    LInsert(&(pg->adjList[toV]), fromV);
    pg->numE += 1;
}

void ShowGraphEdgeInfo(ALGraph *pg)
{
    int i;
    int vx;
    
    for(i=0; i<pg->numV; i++)
    {
        printf("vertex linked to %c: ", i+65);
        
        if(LFirst(&(pg->adjList[i]), &vx))
        {
            printf("%c ", vx+65);
            
            while(LNext(&(pg->adjList[i]), &vx))
            {
                printf("%c ", vx+65);
            }
        }
        printf("\n");
    }
    
}

