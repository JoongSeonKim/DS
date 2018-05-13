//
//  PriorityQueueMain.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 8..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include "PriorityQueue.h"

int DataPriorityComp(char ch1, char ch2)
{
    return ch2 - ch1;
}

int main(void)
{
    PQueue pq;
    PQueueInit(&pq, DataPriorityComp);
    
    PEnqueue(&pq, 'A');
    PEnqueue(&pq, 'B');
    PEnqueue(&pq, 'C');
    printf("dequeue : %c \n", PDequeue(&pq));
    
    PEnqueue(&pq, 'A');
    PEnqueue(&pq, 'B');
    PEnqueue(&pq, 'C');
    printf("dequeue : %c \n", PDequeue(&pq));
    
    while(!PQIsEmpty(&pq)) printf("%c \n", PDequeue(&pq));
    
    return 0;
}
