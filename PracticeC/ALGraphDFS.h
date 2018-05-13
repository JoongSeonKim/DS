//
//  ALGraphDFS.h
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 13..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#ifndef ALGraphDFS_h
#define ALGraphDFS_h

#include "DLinkedList.h"

enum { A, B, C, D, E, F, G, H, I, J };

typedef struct _ual
{
    int numV;
    int numE;
    List *adjList;
    int *visitInfo;
} ALGraph;

void GraphInit(ALGraph *pg, int nv);

void GraphDestroy(ALGraph *pg);

void AddEdge(ALGraph *pg, int fromV, int toV);

void ShowGraphEdgeInfo(ALGraph *pg);

void DFShowGraphVertex(ALGraph *pg, int startV);

#endif /* ALGraphDFS_h */
