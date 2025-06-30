#include <stdio.h>
#include "structStack.h"

void Create(Stack *convexHull);
void Push(Stack *convexHull, Point elem);
void Pop(Stack *convexHull);
Point Top(Stack *convexHull);
Point nextToTop(Stack *convexHull);
int isFull(Stack *convexHull);
int isEmpty(Stack *convexHull);
