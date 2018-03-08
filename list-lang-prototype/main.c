//
//  main.c
//  list-lang-prototype
//
//  Created by Joshua Weinstein on 3/7/18.
//  Copyright © 2018 Joshua Weinstein. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "ListPack.h"

int main(int argc, const char * argv[]) {
    List* foo = List_new_empty(2);
    ListPack_bool(foo, 1);
    printf("type is %u\n", foo->data[0]);
    free(foo);
    return 0;
}
