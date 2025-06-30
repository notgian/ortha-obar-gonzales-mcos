#include <stdio.h>
#include "Point.h"

void insertionSort(Point P0, Point points[], int n);
// void mergeSort(Point points[], Point P0, int n);
int comparePolarOrder(Point P0, Point point, Point key);
int angleOrientation(Point nextToTop, Point Top, Point pointToBeInserted);
double euclidianDistance(Point P0, Point point);
