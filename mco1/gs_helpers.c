#include "geom.h"
#include "stack.h"

/* getReferencePoint: finds the reference point to be used in the Graham Scan Algorithim
    @param *p0:       pointer to an existing point of where to store the value of the reference point
    @param points:    the array of points to use to search for the reference point
    @param n:         the soze of the points array
*/
void getReferencePoint(Point *p0, Point points[], int n)
{
    // Find the point with the lowest y value or if same y value, find the point with the lower x value
    int minIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if ((points[i].y < points[minIndex].y) || (points[i].y == points[minIndex].y && points[i].x < points[minIndex].x))
            minIndex = i;
    }

    // Move p0 to the first index and set the value of p0
    Point temp = points[0];
    points[0] = points[minIndex];
    points[minIndex] = temp;
    *p0 = points[0];
}

/* grahamScanConvexHull: finds the convex hull of a set of points using the grahams scan algorithim given a set of points. Assumed that the points are already sorted and that the first element is the reference point in the array.
    @param *convexHull:  the pointer to the stack to store the resulting convex hull to
    @param points:       the array of points. Must have the reference point at index 0 and be sorted
    @param n:            the size of the array of points
*/
void grahamScanConvexHull(Stack *convexHull, Point points[], int n) {
    Create(convexHull);
    for (int i = 0; i < 3; i++)
        Push(convexHull, points[i]);

    // Find the rest of the convex hull using their angle oreintation
    for (int i = 3; i < n; i++)
    {   
        // If collinear or clockwise we pop the top element
        while (convexHull->top >= 1 && angleOrientation(nextToTop(convexHull), Top(convexHull), points[i]) != -1)
            Pop(convexHull); 
        // Else push the incoming element
        Push(convexHull, points[i]); 
    }
}
