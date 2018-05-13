//
//  ALGraphMain.c
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
    GraphInit(&graph, 5);
    
    AddEdge(&graph, A, B);
    AddEdge(&graph, A, D);
    AddEdge(&graph, B, C);
    AddEdge(&graph, C, D);
    AddEdge(&graph, D, E);
    AddEdge(&graph, E, A);
    
    ShowGraphEdgeInfo(&graph);
    GraphDestroy(&graph);
    
    return 0;
}
