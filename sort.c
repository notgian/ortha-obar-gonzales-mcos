#include "sort.h"
#include "math.h"

void arrSwap(Point arr[], int i, int j) 
{
    Point temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

/* 

    FAST ALGORITHIM ASSIGNED: Merge sort

*/


void mergeSortRecursion(Point p0, Point arr[], int l, int r)
{
    int mid = (l+r)/2;

    if (l >= r)
    {
        return;
    }

    mergeSortRecursion(p0, arr, l, mid); // Recursive call for left half
    mergeSortRecursion(p0, arr, mid+1, r); // Recursive call for right half

    // copying array

    int tempLeftLen = mid - l + 1;
    int tempRightLen = r - mid;

    Point tempLeft[tempLeftLen];
    Point tempRight[tempRightLen];

    for (int i = 0; i < tempLeftLen; i++)
        tempLeft[i] = arr[l+i];

    for (int i = 0; i < tempRightLen; i++)
        tempRight[i] = arr[mid+1+i];
    
    // merge step

    int k = 0;
    int pL = 0;
    int pR = 0;
    
    while (k < r-l+1)
    {
        if (pL < tempLeftLen && pR < tempRightLen)
        {
            if ( comparePolarOrder(p0, tempLeft[pL], tempRight[pR]) == 1 )
                arr[l+k] = tempLeft[pL++];
            else
                arr[l+k] = tempRight[pR++];
        }
        else 
        {
            if (pL < tempLeftLen)
                arr[l+k] = tempLeft[pL++];
            else
                arr[l+k] = tempRight[pR++];
        }
        k++;
    }
}

void mergeSort(Point p0, Point arr[], int n)
{
    mergeSortRecursion(p0, arr, 0, n-1);
}


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