//
//  Table.h
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 13..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#ifndef Table_h
#define Table_h

#include "Slot.h"

#define MAX_TBL 100

typedef int HashFunc(Key k);

typedef struct _table
{
    Slot tbl[MAX_TBL];
    HashFunc *hf;
} Table;

void TBLInit(Table *pt, HashFunc *f);

void TBLInsert(Table *pt, Key k, Value v);

Value TBLDelete(Table *pt, Key k);

Value TBLSearch(Table *pt, Key k);

#endif /* Table_h */
