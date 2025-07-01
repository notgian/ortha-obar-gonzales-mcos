#include "Point.h"
#include "structStack.h"
#include <time.h>

// using insertion sort
void grahamScanSlow(Point P0, Point points[], int n, Stack *convexHull)
{
  int minIndex = 0;
  // find the point with the lowest y value or if same y value, find the point with the lower x value
  // find  P0 or the pivot point
  for (int i = 1; i < n; i++)
  {
    if ((points[i].y < points[minIndex].y) || (points[i].y == points[minIndex].y && points[i].x < points[minIndex].x))
    {
      minIndex = i;
    }
  }

  // move P0 to index 0 and use as reference to find the other nodes
  Point temp = points[0];
  points[0] = points[minIndex];
  points[minIndex] = temp;
  P0 = points[0];

  // sort the rest of the points
  insertionSort(P0, points + 1, n);

  FILE *fp;
  fp = fopen("outslowsort", "w");
  fprintf(fp, "%d\n", n);
  for (int i=0; i<n; i++) {
    fprintf(fp, "%lf %lf\n", points[i].x, points[i].y);
  }
  fclose(fp);

  // initialize the stack
  Create(convexHull);
  // push the first three points onto the stack
  for (int i = 0; i < 3; i++)
  {
    Push(convexHull, points[i]);
  }

  // find the rest of the convex hull using their angle oreintation
  for (int i = 3; i < n; i++)
  {
    while (convexHull->top >= 1 && angleOrientation(nextToTop(convexHull), Top(convexHull), points[i]) != 2)
    {
      Pop(convexHull); // if collinear or clockwise and there is more than 2 elems iin the stack, we pop the top element
    }
    Push(convexHull, points[i]); // else we push the incoming element
  }
}

void grahamScanFast(Point P0, Point points[], int n, Stack *convexHull)
{
  int minIndex = 0;
  // find the point with the lowest y value or if same y value, find the point with the lower x value
  // find  P0 or the pivot point
  for (int i = 1; i < n; i++)
  {
    if ((points[i].y < points[minIndex].y) || (points[i].y == points[minIndex].y && points[i].x < points[minIndex].x))
    {
      minIndex = i;
    }
  }

  // move P0 to index 0 and use as reference to find the other nodes
  Point temp = points[0];
  points[0] = points[minIndex];
  points[minIndex] = temp;
  P0 = points[0];

  // sort the rest of the points
  mergeSort(P0, points + 1, n-1);
  
  FILE *fp;
  fp = fopen("outmergesort", "w");
  fprintf(fp, "%d\n", n);
  for (int i=0; i<n; i++) {
    fprintf(fp, "%lf %lf\n", points[i].x, points[i].y);
  }
  fclose(fp);

  // initialize the stack
  Create(convexHull);
  // push the first three points onto the stack
  for (int i = 0; i < 3; i++)
  {
    Push(convexHull, points[i]);
  }

  // find the rest of the convex hull using their angle oreintation
  for (int i = 3; i < n; i++)
  {
    while (convexHull->top >= 1 && angleOrientation(nextToTop(convexHull), Top(convexHull), points[i]) != 2)
    {
      Pop(convexHull); // if collinear or clockwise and there is more than 2 elems iin the stack, we pop the top element
    }
    Push(convexHull, points[i]); // else we push the incoming element
  }
}