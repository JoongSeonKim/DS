//
//  ReadStringRight.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 4. 6..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

char * ReadUserName(void)
{
    char * name = (char *)malloc(sizeof(char)*30);
    printf("What's your name? ");
    fgets(name, sizeof(char)*30, stdin);
    return name;
}

int main(void)
{
    char * name1;
    char * name2;
    name1 = ReadUserName();
    printf("name1: %s \n", name1);
    name2 = ReadUserName();
    printf("name2: %s \n", name2);
    
    free(name1);
    free(name2);
    return 0;
}
