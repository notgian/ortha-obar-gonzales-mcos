#include <stdio.h>
#include "geom.h"
#pragma once

#define MAX 32768

typedef struct
{
    Point data[MAX];
    int top;
} Stack;

void Create(Stack *convexHull);
void Push(Stack *convexHull, Point elem);
Point Pop(Stack *convexHull);
Point Top(Stack *convexHull);
Point nextToTop(Stack *convexHull);
int isFull(Stack *convexHull);
int isEmpty(Stack *convexHull);
