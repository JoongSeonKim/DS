//
//  CLinkedListPointListSortMain(174).c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 3..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

/*
int WhoIsPrecede(LData d1, LData d2)
{
    if(d1->xpos < d2->xpos) return 0;
    
    else if(d1->xpos == d2->xpos)
    {
        if(d1->ypos<d2->ypos) return 0;
        else return 1;
    }
    
    else return 1;
}*/ // Point.h comparison function

int main(void)
{
    List list;
    int i, data, nodeNum;
    ListInit(&list);
    
    // save 5 data
    LInsert(&list, 3);
    LInsert(&list, 4);
    LInsert(&list, 5);
    LInsertFront(&list, 2);
    LInsertFront(&list, 1);
    
    // print saved data
    printf("the number of current data: %d \n", LCount(&list));
    
    if(LFirst(&list, &data))
    {
        printf("%d ", data);
        
        for(i=0; i<LCount(&list)-1; i++)
        {
            if(LNext(&list, &data)) printf("%d ", data);
        }
    }
    
    printf("\n");
    
    // delete all with 2n
    
    nodeNum = LCount(&list);
    
    if(nodeNum != 0)
    {
        LFirst(&list, &data);
        if(data%2 == 0)
        {
            LRemove(&list);
        }
        
        for(i=0; i<nodeNum-1; i++)
        {
            LNext(&list, &data);
            if(data%2 == 0)
            {
                LRemove(&list);
            }
        }
    }
    
    // print data after deletion
    printf("the number of current data: %d \n", LCount(&list));
    
    if(LFirst(&list, &data))
    {
        printf("%d ", data);
        for(i=0; i<LCount(&list)-1; i++)
        {
            if(LNext(&list, &data)) printf("%d ", data);
        }
    }
    
    printf("\n");
    
    return 0;
}
