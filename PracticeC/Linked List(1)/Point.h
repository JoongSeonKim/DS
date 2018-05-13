//
//  Point.h
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 4. 30..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#ifndef Point_h
#define Point_h

typedef struct _point
{
    int xpos;
    int ypos;
} Point;

// xpos, ypos value set
void SetPointPos(Point *ppos, int xpos, int ypos);

// print xpos, ypos
void ShowPointPos(Point *ppos);

// compare two Point
int PointComp(Point *pos1, Point *pos2);


#endif /* Point_h */
