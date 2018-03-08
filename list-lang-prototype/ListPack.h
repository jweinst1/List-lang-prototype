//
//  ListPack.h
//  list-lang-prototype
//
//  Created by Joshua Weinstein on 3/7/18.
//  Copyright © 2018 Joshua Weinstein. All rights reserved.
//

#ifndef ListPack_h
#define ListPack_h

// header responsible for packing types or values into lists

#include <stdio.h>
#include "List.h"

// packs a boolean into a list.
void ListPack_bool(List* lst, int b);

#endif /* ListPack_h */
