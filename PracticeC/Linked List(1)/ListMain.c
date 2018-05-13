//
//  ListMain.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 4. 30..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
    // initialize arraylist
    List list;
    int data;
    ListInit(&list);
    
    // save 5 data
    LInsert(&list, 11); LInsert(&list, 11);
    LInsert(&list, 22); LInsert(&list, 22);
    LInsert(&list, 33);
    
    // print output of all saved data
    printf("the number of current data : %d \n", LCount(&list));
    
    if(LFirst(&list, &data))
    {
        printf("%d ", data);
        
        while(LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");

    // find all number 22 & delete all
    if(LFirst(&list, &data))
    {
        if(data==22) LRemove(&list);
        
        while(LNext(&list, &data))
        {
            if(data==22) LRemove(&list);
        }
    }
    
    // print output of all saved data (after deletion)
    printf("the number of current data : %d \n", LCount(&list));
    
    if(LFirst(&list, &data))
    {
        printf("%d ", data);
        
        while(LNext(&list, &data)) printf("%d ", data);
    }
    printf("\n\n");
    
    return 0;
}
