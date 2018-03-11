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
    List* foo = ListPack_new("bbb", 1, 0, 1);
    printf("bool is %u\n", foo->data[3]);
    free(foo);
    return 0;
}
