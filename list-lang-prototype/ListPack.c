//
//  ListPack.c
//  list-lang-prototype
//
//  Created by Joshua Weinstein on 3/7/18.
//  Copyright © 2018 Joshua Weinstein. All rights reserved.
//

#include "ListPack.h"

void ListPack_bool(List* lst, int b)
{
    lst->data[0] = ListType_Bool;
    lst->data[1] = b;
}