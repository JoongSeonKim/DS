//
//  StringInvert.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 4. 6..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * ReadUserString(void)
{
    int length;
    printf("input maximum length of the string: ");
    scanf("%d", &length);
    getchar();
    
    char * name = (char *)malloc(sizeof(char) * (length+1) );
    printf("Type Input String: ");
    fgets(name, sizeof(char)*(length+1), stdin);
    return name;
}

void InvertUserString(char * str)
{
    int i, len;
    len=strlen(str);
    for(i=len; i>0; i--)
    {
        if(str[i]==' ')
        {
            printf("%s ", &str[i+1]);
            str[i]=0;
        }
    }
    printf("%s\n", &str[0]);
}

int main(void)
{
    char * str1;
    char * str2;
    str1 = ReadUserString();
    printf("name1: %s \n", str1);
    InvertUserString(str1);
    str2 = ReadUserString();
    printf("name2: %s \n", str2);
    InvertUserString(str2);
    
    free(str1);
    free(str2);
    return 0;
}
