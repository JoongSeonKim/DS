//
//  ReadStringFault.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 4. 6..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>

char name[30];

char * ReadUserName(void)
{
    char name[30];
    printf("What's your name?");
    fgets(name, sizeof(name), stdin);
    return name;
}

int main(void)
{
    char * name1;
    char * name2;
    name1 = ReadUserName();
    printf("name1: %s \n", name1);
    name2 = ReadUserName();
    printf("name2: %s \n", name1);
    return 0;
}
 
/*
int main(void)
{
    char name[30];
    printf("What's your name?");
    fgets(name, sizeof(name), stdin);
    
    printf("name: %s \n", name);
    
    return 0;
}
*/
