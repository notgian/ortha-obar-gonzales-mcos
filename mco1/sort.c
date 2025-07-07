#include <math.h>
#include "sort.h"
#include "geom.h"

/* arrSwap:     swaps the ith and jth elements in an array. Presupposed that i and j are valid indexes of the array
    @param arr: the array where elements will be swapped
    @param i:   the index of the first element in the swap
    @param j:   the index of the second element in the swap
*/
void arrSwap(Point arr[], int i, int j)
{
    Point temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

/* mergeSortRecursion: the recursive call for the mergeSort algorithim. Uses left and right indices to denote the subarray to manipulate in the current recursive call
    @param p0:         the reference point to be used for comparisons
    @param arr:        the array of points to sort. SHOULD NOT INCLUDE THE FIRST INDEX p0!!
    @param l:          the left index of the subarray
    @param r:          the right index of the subarray

*/
void mergeSortRecursion(Point p0, Point arr[], int l, int r)
{
    int mid = (l + r) / 2;

    if (l >= r)
    {
        return;
    }

    mergeSortRecursion(p0, arr, l, mid);     // Recursive call for left half
    mergeSortRecursion(p0, arr, mid + 1, r); // Recursive call for right half

    // copying array
    int tempLeftLen = mid - l + 1;
    int tempRightLen = r - mid;

    Point tempLeft[tempLeftLen];
    Point tempRight[tempRightLen];

    for (int i = 0; i < tempLeftLen; i++)
        tempLeft[i] = arr[l + i];

    for (int i = 0; i < tempRightLen; i++)
        tempRight[i] = arr[mid + 1 + i];

    // merge step

    int k = 0;
    int pL = 0;
    int pR = 0;

    while (k < r - l + 1)
    {
        if (pL < tempLeftLen && pR < tempRightLen)
        {
            if (comparePolarOrder(p0, tempLeft[pL], tempRight[pR]) == 1)
                arr[l + k] = tempLeft[pL++];
            else
                arr[l + k] = tempRight[pR++];
        }
        else
        {
            if (pL < tempLeftLen)
                arr[l + k] = tempLeft[pL++];
            else
                arr[l + k] = tempRight[pR++];
        }
        k++;
    }
}

/* mergeSort:   implementation of merge sort algorithim. Used to wrap the mergeSortRecursion function to avoid needing to pre-index the left and right of the array
    @param p0:  the reference point to use for comparisons
    @param arr: the array of points to sort. SHOULD NOT INCLUDE THE FIRST INDEX p0!!
    @param n:   size of the array
*/
void mergeSort(Point p0, Point arr[], int n)
{
    mergeSortRecursion(p0, arr, 0, n - 1);
}

/* insertionSort:  implementation of insertion sort algorithim
    @param p0:     the reference point to use for comparisons
    @param points: the array of points to sort. SHOULD NOT INCLUDE THE FIRST INDEX p0!!
    @n:            the size of the array

*/
void insertionSort(Point p0, Point points[], int n)
{
    for (int i = 1; i < n - 1; i++)
    {
        Point key = points[i];
        int j = i - 1;
        // sort array by polar angle
        while (j >= 0 && comparePolarOrder(p0, points[j], key) == 0)
        {
            points[j + 1] = points[j];
            j = j - 1;
        }
        points[j + 1] = key;
    }
}