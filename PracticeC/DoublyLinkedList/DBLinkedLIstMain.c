//
//  DBLinkedLIstMain.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 4..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include "DBLinkedListDummy.h"

int main(void)
{
    List list;
    int data;
    ListInit(&list);
    
    LInsert(&list, 1); LInsert(&list, 2);
    LInsert(&list, 3); LInsert(&list, 4);
    LInsert(&list, 5); LInsert(&list, 6);
    LInsert(&list, 7); LInsert(&list, 8);
    
    if(LFirst(&list, &data))
    {
        printf("%d ", data);
        
        while(LNext(&list, &data))
        {
            printf("%d ", data);
        }
        
        printf("\n\n ");
    }
    
    return 0;
}


