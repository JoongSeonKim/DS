//
//  ArrayString.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 4. 7..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>

int main(void)
{
    char str[]="Good Morning!";
    
    printf("배열 str의 크기: %d \n", sizeof(str));
    printf("널 문자 문자형 출력: %c \n", str[13]);
    printf("널 문자 정수형 출력: %d \n", str[13]);
    
    return 0;
}
