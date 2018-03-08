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
#include <stdarg.h>
#include "List.h"

// packs a boolean into a list.
void ListPack_bool(List* lst, int b);

// calculates and returns the size required for some fmt list specifier
int ListPack_fmt_len(const char* fmt);

// Packs a list using variadic arguments and a format string.
void ListPack_fmt(List* lst, const char* fmt, ...);

// Creates a new list from some format string specification.
List* ListPack_new(const char* fmt, ...);


#endif /* ListPack_h */
