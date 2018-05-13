//
//  Slot2.h
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 13..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#ifndef Slot2_h
#define Slot2_h

#include "Person.h"

typedef int Key;
typedef Person * Value;

typedef struct _slot
{
    Key key;
    Value val;
} Slot;

#endif /* Slot2_h */
