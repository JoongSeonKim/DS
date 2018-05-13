//
//  Average.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 4. 6..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>

int main(void)
{
    int i=0, cnt, tmp;
    int sum=0;
    //int aver;
    float average;
    
    printf("입력할 총 숫자의 개수: ");
    scanf("%d", &cnt);
    
    while(i<cnt)
    {
        printf("숫자를 입력하시오: ");
        scanf("%d", &tmp);
        sum+=tmp;
        i++;
    }
    
    //aver = sum/cnt;
    //printf("평균: %d", aver);

    average = (double)sum / cnt;
    printf("평균: %f", average);
}
