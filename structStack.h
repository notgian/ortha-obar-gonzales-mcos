#include <stdio.h>
#include "Point.h"
#pragma once

#define MAX 32768

typedef struct
{
    Point data[MAX];
    int top;
} Stack;