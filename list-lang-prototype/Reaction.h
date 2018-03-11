//
//  Reaction.h
//  list-lang-prototype
//
//  Created by Joshua Weinstein on 3/9/18.
//  Copyright © 2018 Joshua Weinstein. All rights reserved.
//

#ifndef Reaction_h
#define Reaction_h

// Header to implement reactions that work on lists and output new lists.
// Example:
// rx a: $1 + 2 -> print $1

#include <stdio.h>
#include <stdlib.h>

// Reaction command
typedef enum
{
    RxCmd_stop,
    RxCmd_print,
    RxCmd_add
} RxCmd;

#endif /* Reaction_h */
