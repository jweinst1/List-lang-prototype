//
//  list.c
//  list-lang-prototype
//
//  Created by Joshua Weinstein on 3/6/18.
//  Copyright © 2018 Joshua Weinstein. All rights reserved.
//

#include "list.h"


// Creates a new list from some amount of bytes
List* List_new(unsigned char* bytes, size_t n)
{
    List* newlist = malloc(sizeof(List) + n);
    newlist->size = n;
    memcpy(newlist->data, bytes, n);
    return newlist;
}

// Creates and returns an empty list of size n.
List* List_new_empty(size_t n)
{
    List* newlist = malloc(sizeof(List) + n);
    newlist->size = n;
    memset(newlist->data, 0, n);
    return newlist;
}

List* List_new_copy(List* lst)
{
    List* newlist = malloc(List_SIZE(lst));
    newlist->size = lst->size;
    memcpy(newlist->data, lst->data, lst->size);
    return newlist;
}