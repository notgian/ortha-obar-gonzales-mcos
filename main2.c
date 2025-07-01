#include <stdio.h>
#include "stack.c"
#include "sort.c"
#include "graham_scan1.c"

int main()
{
    FILE *fp;
    Stack convexHull;
    Point p0;
    int size;

    // Slow
    
    fp = fopen("sample-input.txt", "r");

    fscanf(fp, "%d", &size);
    Point points[size];
    for (int i = 0; i < size; i++)
    {
        fscanf(fp, "%lf %lf", &points[i].x, &points[i].y);
    }
    fclose(fp);

    grahamScanSlow(p0, points, size, &convexHull);
    char outIns[100] = "outins";
    
    fp = fopen(outIns, "w");
    fprintf(fp, "%d \n", convexHull.top+1); // Size of stack

    for (int i = 0; i <= convexHull.top; i++)
    { // input convex hull
        fprintf(fp, "%-9lf %-9lf\n", convexHull.data[i].x, convexHull.data[i].y);
    }

    fclose(fp);

    // Fast

    fp = fopen("sample-input.txt", "r");

    fscanf(fp, "%d", &size);
    for (int i = 0; i < size; i++)
    {
        fscanf(fp, "%lf %lf", &points[i].x, &points[i].y);
    }
    fclose(fp);

    grahamScanFast(p0, points, size, &convexHull);
    char outMrg[100] = "outmrg";
    
    fp = fopen(outMrg, "w");
    fprintf(fp, "%d \n", convexHull.top+1); // Size of stack

    for (int i = 0; i <= convexHull.top; i++)
    { // input convex hull
        fprintf(fp, "%-9lf %-9lf\n", convexHull.data[i].x, convexHull.data[i].y);
    }

    fclose(fp);

    return 0;
}
