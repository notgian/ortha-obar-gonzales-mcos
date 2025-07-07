#include "geom.h"
#include "stack.h"
#include "sort.h"
#include "gs_helpers.c"

/* grahamScanSlow:      the Graham Scan algorithim using a slow sorting algorithm
    @param points:      the array of points to input for the algorithim
    @param n:           the size of the array
    @param *convexHull: the pointer to the stack to store the resulting convex hull to
*/
void grahamScanSlow(Point points[], int n, Stack *convexHull)
{
    Point p0;
    getReferencePoint(&p0, points, n);
    insertionSort(p0, points + 1, n);
    grahamScanConvexHull(convexHull, points, n);
}