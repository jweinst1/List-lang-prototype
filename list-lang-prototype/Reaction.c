//
//  Reaction.c
//  list-lang-prototype
//
//  Created by Joshua Weinstein on 3/9/18.
//  Copyright © 2018 Joshua Weinstein. All rights reserved.
//

#include "Reaction.h"

RxList* RxList_new(int n)
{
    RxList* rxl = malloc(sizeof(RxList) + n);
    rxl->size = n;
    rxl->elems[0] = 0;
    return rxl;
}

// Function responsible for reacting two lists.
void Rx_React(RxList* target, RxList* reactor)
{
    
}