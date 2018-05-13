//
//  CircularQueueMain.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 7..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include "ListBaseQueue.h"

int main(void)
{
    Queue q;
    QueueInit(&q);
    
    Enqueue(&q, 1); Enqueue(&q, 2);
    Enqueue(&q, 3); Enqueue(&q, 4);
    Enqueue(&q, 5);
    
    while(!QIsEmpty(&q)) printf("%d ", Dequeue(&q));
    
    return 0;
}
