//
//  list.h
//  list-lang-prototype
//
//  Created by Joshua Weinstein on 3/6/18.
//  Copyright © 2018 Joshua Weinstein. All rights reserved.
//

#ifndef list_h
#define list_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define List_SIZE(lst) (sizeof(List) + lst->size)

// type marker used for writing data to lists.
typedef enum
{
    ListType_Bool
} ListType;

// list structure
typedef struct
{
    size_t size;
    unsigned char data[0];
} List;

// Creates a new list from some amount of bytes
List* List_new(unsigned char* bytes, size_t n);

// Creates and returns an empty list of size n.
List* List_new_empty(size_t n);

// copy constructor for list.
List* List_new_copy(List* lst);


#endif /* list_h */
