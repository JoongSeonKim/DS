//
//  AdjacentListGraph.h
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 13..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#ifndef AdjacentListGraph_h
#define AdjacentListGraph_h

#include "DLinkedList.h"

enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _val
{
    int numV;
    int numE;
    List *adjList;
} ALGraph;

void GraphInit(ALGraph *pg, int nv);

void GraphDestroy(ALGraph *pg);

void AddEdge(ALGraph *pg, int fromV, int toV);

void ShowGraphEdgeInfo(ALGraph *pg);

#endif /* AdjacentListGraph_h */
