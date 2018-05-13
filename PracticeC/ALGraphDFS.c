//
//  ALGraphDFS.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 13..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "ALGraphDFS.h"
#include "ArrayBaseStack.h"

int WhoIsPrecede(int num1, int num2)
{
    if (num1 < num2) return 0;
    
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
    
    pg->visitInfo = (int*)malloc(sizeof(int)*pg->numV);
    
    memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
}

void GraphDestroy(ALGraph *pg)
{
    if(pg->adjList != NULL) free(pg->adjList);
    
    if(pg->visitInfo != NULL) free(pg->visitInfo);
}

void AddEdge(ALGraph *pg, int fromV, int toV)
{
    LInsert(&(pg->adjList[fromV]), toV);
    LInsert(&(pg->adjList[toV]), fromV);
    
    (pg->numE)+=1;
}

void ShowGraphEdgeInfo(ALGraph *pg)
{
    int i;
    int vx;
    
    for(i=0; i<pg->numV; i++) // vertex select first (Depth-First)
    {
        printf("Vertex linked to %c : ", i+65);
        
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

int VisitVertex(ALGraph *pg, int visitV)
{
    if(pg->visitInfo[visitV] == 0) // visitInfo is Empty -> TRUE
    {
        pg->visitInfo[visitV] = 1; // check as visited.
        printf("%c ", visitV + 65);
        return TRUE;
    }
    return FALSE;
}

void DFShowGraphVertex(ALGraph *pg, int startV)
{
    Stack stack;
    int visitV = startV;
    int nextV;
    
    StackInit(&stack);  // Initiate stack
    VisitVertex(pg, visitV);    // visit "Start Vertex"
    SPush(&stack, visitV);  // Push "Start Vertex" to stack.
    
    // Try "Visit" visitV vertex -> to other linked
    while(LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
    {
        // nextV has vertex adjacent to visitV by LFirst
        int visitFlag = FALSE; // Initailly, consider flag as not visited
        
        if(VisitVertex(pg, nextV) == TRUE) // if nextV is Vertex that can be visited,
        {
            SPush(&stack, visitV); // Push it to stack.
            visitV = nextV; // for next route
            visitFlag = TRUE;
        }
        
        else // if nextV is Vertex that cannot be visited.
        {
            while(LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
            {
                if(VisitVertex(pg, nextV) == TRUE)
                {
                    SPush(&stack, visitV);
                    visitV = nextV;
                    visitFlag = TRUE;
                    break;
                }
            }
        }
        
        if(visitFlag == FALSE)
        {
            if(SIsEmpty(&stack) == TRUE) break;
            
            else visitV = SPop(&stack);
        }
    }
    
    memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
}
