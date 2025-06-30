#include "sort.h"
#include "math.h"

void insertionSort(Point P0, Point points[], int n)
{
  for (int i = 1; i < n - 1; i++)
  {
    Point key = points[i];
    int j = i - 1;
    while (j >= 0 && comparePolarOrder(P0, points[j], key) == 0)
    { // sort array by polar angle
      points[j + 1] = points[j];
      j = j - 1;
    }
    points[j + 1] = key;
  }
}

/*void mergeSort(Point points[], int key){
}*/

int comparePolarOrder(Point P0, Point point, Point key)
{
  Point firstPoint = point;
  Point secondPoint = key;
  int returnVal = 0;
  int orientation = angleOrientation(P0, firstPoint, secondPoint); // 0 means collinear, 1 means clockwise, 2 means counterclockwise
  if (orientation == 0)
  {
    returnVal = euclidianDistance(P0, firstPoint) < euclidianDistance(P0, secondPoint); // compare distances from pivotPoint to both points
  }
  else
  {
    returnVal = orientation == 2; // true if counterclockwise else clockwise
  }
  return returnVal;
}

int angleOrientation(Point nextToTop, Point Top, Point pointToBeInserted)
{
  int returnVal = 0;
  // formula for finding the determinant of a 2x2 matrix using 3 point cross product to compute for orientation
  // (y2-y1) * (x3-x2) - (x2-x1) * (y3-y1) derived from ad-bc
  double angleVal = (Top.y - nextToTop.y) * (pointToBeInserted.x - Top.x) - (Top.x - nextToTop.x) * (pointToBeInserted.y - Top.y);
  if (angleVal == 0)
  {
    returnVal = 0; // collinear
  }
  else if (angleVal > 0)
  {
    returnVal = 1; // clockwise
  }
  else
  {
    returnVal = 2; // counterclockwise
  }
  return returnVal;
}

double euclidianDistance(Point P0, Point point)
{
  // distance formula: sqrt((x1-x2)^2 + (y1-y2)^2)
  return sqrt(pow((P0.x - point.x), 2) + pow((P0.y - point.y), 2));
}