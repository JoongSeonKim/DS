//
//  304 PointerArray.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 4. 7..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>

int main(void)
{
    int num1=10, num2=20, num3=30;
    int* arr[3] = {&num1, &num2, &num3};
    
    printf("%d \n", *arr[0]);
    printf("%d \n", *arr[1]);
    printf("%d \n", *arr[2]);
    
    return 0;
}
