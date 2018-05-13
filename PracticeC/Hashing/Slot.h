//
//  Slot.h
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 13..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#ifndef Slot_h
#define Slot_h

#include "Person.h"

typedef int Key;
typedef Person * Value;

enum SlotStatus { EMPTY, DELETED, INUSE };

typedef struct _slot
{
    Key key;
    Value val;
    enum SlotStatus status;
} Slot;

#endif /* Slot_h */
