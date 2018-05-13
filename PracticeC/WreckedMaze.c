//
//  WreckedMaze.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 12..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"
#include "Position.h"

#define MAZE_SIZE 5

void MazeSolve(Stack *s, Pos *start, Pos *end, char maze[MAZE_SIZE][MAZE_SIZE])
{
    SPush(s, start);
    
    Data cData = (Pos*)malloc(sizeof(Pos));
    cData->x = start->x;
    cData->y = start->y;
    
    
    while(1)
    {
        if( cData->x == end->x && cData->y == end->y )
        {
            break;
        }
        
        else if( (cData->y)+1 < 5 && ( maze[cData->x][(cData->y)+1] == '0' || maze[cData->x][(cData->y)+1] == 'x') )
        {
            (cData->y) += 1;
            SPush(s, cData);
        }
        
        else if( (cData->x)+1 < 5 && ( maze[(cData->x)+1][cData->y] == '0' || maze[(cData->x)+1][cData->y] == 'x') )
        {
            (cData->x) += 1;
            SPush(s, cData);
        }
        
        else if( (cData->x)-1 > -1  && ( maze[(cData->x)-1][cData->y] == '0' || maze[(cData->x)-1][cData->y] == 'x') )
        {
            (cData->x) -= 1;
            SPush(s, cData);
        }
        
        else if( (cData->y)-1 > -1 && ( maze[cData->x][(cData->y)-1] == '0' || maze[cData->x][(cData->y)-1] == 'x') )
        {
            (cData->y) -= 1;
            SPush(s, cData);
        }
        
        else
        {
            SPop(s);
            cData->x = SPeek(s)->x;
            cData->y = SPeek(s)->y;
        }
    }
    
}


int main(void)
{
    char maze[MAZE_SIZE][MAZE_SIZE] = {
        {'1','1','1','1','1'},
        {'e','0','1','0','1'},
        {'1','0','0','0','1'},
        {'1','1','1','0','x'},
        {'1','1','1','1','1'}
    };
    int i, j;
    
    Stack stack;
    StackInit(&stack);
    
    Pos * enterData = (Pos*)malloc(sizeof(Pos));
    Pos * exitData = (Pos*)malloc(sizeof(Pos));
    
    for(i=0; i<MAZE_SIZE; i++)
    {
        for(j=0; j<MAZE_SIZE; j++)
        {
            if(maze[i][j] == 'e')
            {
                PSet(enterData, i, j);
            }
            
            else if(maze[i][j] == 'x')
            {
                PSet(exitData, i, j);
            }
        }
    }
    
    MazeSolve(&stack, enterData, exitData, maze);
    
    printf("%d %d %d %d \n", enterData->x, enterData->y, exitData->x, exitData->y);
    i=0;
    
    while(!SIsEmpty(&stack))
    {
        Data rm = SPop(&stack);
        i++;
        printf("route(reverse) %d : ( %d, %d ) \n", i, rm->x, rm->y);
    }
    
    printf("%d %d %d %d \n", enterData->x, enterData->y, exitData->x, exitData->y);
    
    free(enterData);
    free(exitData);
 
    return 0;
}
