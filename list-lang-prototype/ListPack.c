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

int ListPack_fmt_len(const char* fmt)
{
    int total = 0;
    while(*fmt)
    {
        switch(*fmt)
        {
            case 'b':
                total += 2;
                fmt++;
                break;
            default:
                fprintf(stderr, "Pack Error: Unknown specifier '%c', exiting.\n", *fmt);
                exit(2);
        }
    }
    return total;
}

void ListPack_fmt(List* lst, const char* fmt, ...)
{
    va_list packArgs;
    va_start(packArgs, fmt);
    char* writer = (char*)lst->data;
    while(*fmt)
    {
        switch(*fmt)
        {
            case 'b': // Packs a bool into the list.
                *writer++ = ListType_Bool;
                *writer++ = va_arg(packArgs, int);
                fmt++;
                break;
            default:
                fprintf(stderr, "Pack Error: Unknown specifier '%c', exiting.\n", *fmt);
                exit(2);
        }
    }
    va_end(packArgs);
    return;
}

List* ListPack_new(const char* fmt, ...)
{
    int sized = ListPack_fmt_len(fmt);
    List* newlist = malloc(sizeof(List) + sized);
    newlist->size = sized;
    va_list packArgs;
    va_start(packArgs, fmt);
    char* writer = (char*)newlist->data;
    while(*fmt)
    {
        switch(*fmt)
        {
            case 'b': // Packs a bool into the list.
                *writer++ = ListType_Bool;
                *writer++ = va_arg(packArgs, int);
                fmt++;
                break;
            default:
                fprintf(stderr, "Pack Error: Unknown specifier '%c', exiting.\n", *fmt);
                exit(2);
        }
    }
    va_end(packArgs);
    return newlist;
}