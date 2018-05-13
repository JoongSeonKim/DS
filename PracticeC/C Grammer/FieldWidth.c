//
//  FieldWidth.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 4. 6..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>

int main(void)
{
    printf("%-8s %14s %5s \n", "이름표", "전공학과", "학년" );
    printf("%-8s %14s %5d \n", "김동수", "전자공학", 3);
    printf("%-8s %14s %5d \n", "이을수", "화학공학", 2);
    printf("%-8s %14s %5d \n", "박찬호", "기계공학", 1);
    
    return 0;
}
