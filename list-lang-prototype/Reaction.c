//
//  Reaction.c
//  list-lang-prototype
//
//  Created by Joshua Weinstein on 3/9/18.
//  Copyright © 2018 Joshua Weinstein. All rights reserved.
//

#include "Reaction.h"

RxList* RxList_new(void)
{
    RxList* rxl = malloc(Rx_DEFSIZE);
    rxl->size = 0;
    rxl->cap = Rx_DEFSIZE;
    rxl->elems[0] = 0;
    return rxl;
}

void RxList_write(RxList* rx, unsigned char* items, int size)
{
    if((rx->cap - rx->size) < size) Rx_expand(rx, size);
    memcpy(rx->elems, items, size);
    rx->size += size;
}

const unsigned char*
Rx_get(RxList* rxl, int index)
{
    const unsigned char* reader = rxl->elems;
    while(index--) reader++;
    return reader;
}

// Function responsible for reacting two lists.
void Rx_React(RxList* rx1, RxList* rx2)
{
    
    unsigned char* reactionReader = rx2->elems;
    while (*reactionReader != RxElem_stop)
    {
        switch(*reactionReader)
        {
            case RxElem_bool:
                break;
            case RxElem_print:
                break;
            case RxElem_not:
                break;
            case RxElem_ith:
                break;
            case RxElem_stop:
                return;
        }
    }
}