//
//  PointListMain.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 4. 30..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"
#include "Point.h"

int WhoIsPrecede(LData d1, LData d2)
{
    if(d1->xpos<d2->xpos) return 0;
    
    else if(d1->xpos==d2->xpos)
    {
        if(d1->ypos<d2->ypos) return 0;
        else return 1;
    }
    
    else return 1;
}

int main(void)
{
    List list;
    Point compPos;
    Point *ppos;
    
    ListInit(&list);
    
    
    
    // save 4 data
    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 1);
    LInsert(&list, ppos);
    
    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 2);
    LInsert(&list, ppos);
    
    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 1);
    LInsert(&list, ppos);
    
    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 2);
    LInsert(&list, ppos);
    
    // print saved data
    printf("the number of current data: %d \n", LCount(&list));
    
    if(LFirst(&list, &ppos))
    {
        ShowPointPos(ppos);
        
        while(LNext(&list, &ppos))
        {
            ShowPointPos(ppos);
        }
    }
    
    printf("\n");
    
    // delete all with xpos=2
    
    compPos.xpos=2;
    compPos.ypos=0;

    if(LFirst(&list, &ppos))
    {
        if(PointComp(ppos, &compPos)==1)
        {
            ppos = LRemove(&list);
            free(ppos);
        }
        
        while(LNext(&list, &ppos))
        {
            if(PointComp(ppos, &compPos)==1)
            {
                ppos = LRemove(&list);
                free(ppos);
            }
        }
    }
    
    // print data after deletion
    printf("the number of current data: %d \n", LCount(&list));
    
    if(LFirst(&list, &ppos))
    {
        ShowPointPos(ppos);
        
        while(LNext(&list, &ppos)) ShowPointPos(ppos);
    }
    
    printf("\n");
    
    return 0;
}
