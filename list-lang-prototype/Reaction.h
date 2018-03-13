//
//  Reaction.h
//  list-lang-prototype
//
//  Created by Joshua Weinstein on 3/9/18.
//  Copyright © 2018 Joshua Weinstein. All rights reserved.
//

#ifndef Reaction_h
#define Reaction_h

// REACTION PROTOTYPE
// Header to implement reactions that work on lists and output new lists.
// Example:
// rx a: $1 + 2 -> print $1
// This file uses its own List object

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Rx_DEFSIZE 1000 + sizeof(RxList)

// This macro allows structs to be cast as container types, with a size and variable sized array
#define Rx_BASE \
      int size; \
      int cap; \
      unsigned char elems[0]

//Macro that can expand a reaction list
// uses realloc, no throw
#define Rx_expand(rx, amount) do { \
    rx = realloc(rx, rx->cap + amount);\
    rx->cap += amount; \
} while(0)

// Test macro to write a dummy list of elements to a reaction list
// Acts as a simple test for reaction instruction set.
#define Rx_WRITE_TEST(rxl) do { \
     rxl->elems[0] = RxElem_print;\
     rxl->elems[1] = RxElem_ith;\
     rxl->elems[2] = 0;\
     rxl->elems[3] = RxElem_not;\
     rxl->elems[4] = RxElem_ith;\
     rxl->elems[5] = 0;\
     rxl->elems[6] = RxElem_print;\
     rxl->elems[7] = RxElem_ith;\
     rxl->elems[8] = 0;\
} while(0)


// REACTION ELEMENTS
// :: Reaction elements are essentially the items present in a RxList. These can alter other lists of elements, or act as values on their own.
// In a reactive language, there are no distinction between computative objects or value objects.
typedef enum
{
    RxElem_stop,
    RxElem_print,
    RxElem_bool,
    RxElem_not,
    RxElem_ith // represents some ordered element
} RxElem;

// List that contains reactions elements and items
typedef struct
{
    Rx_BASE;
} RxList;

// Creates a new empty reaction list.
RxList* RxList_new(void);

//writes new elements to a list, expands if needed.
void RxList_write(RxList* rx, unsigned char* items, int size);

// Returns a read-only pointer to some index in the reaction.
const unsigned char*
Rx_get(RxList* rxl, int index);

// Function responsible for reacting two lists.
void Rx_React(RxList* rx1, RxList* rx2);



#endif /* Reaction_h */
