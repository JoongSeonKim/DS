//
//  DFSMain.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 13..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include "ALGraphDFS.h"

int main(void)
{
    ALGraph graph;
    GraphInit(&graph, 7);
    
    AddEdge(&graph, A, B);
    AddEdge(&graph, A, D);
    AddEdge(&graph, B, C);
    AddEdge(&graph, D, C);
    AddEdge(&graph, D, E);
    AddEdge(&graph, E, F);
    AddEdge(&graph, E, G);
    
    ShowGraphEdgeInfo(&graph);
    
    DFShowGraphVertex(&graph, A); printf("\n");
    DFShowGraphVertex(&graph, C); printf("\n");
    DFShowGraphVertex(&graph, E); printf("\n");
    DFShowGraphVertex(&graph, G); printf("\n");

    GraphDestroy(&graph);
    
    return 0;
}
