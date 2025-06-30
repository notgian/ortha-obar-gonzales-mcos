#include <stdio.h>
#include "stack.c"
#include "sort.c"
#include "graham_scan1.c"

int main()
{
  Stack convexHull; // declare the stack
  Point P0;         // pivot point
  clock_t time;     // time variable
  char filename[100];
  FILE *file;
  int validFile = 0;
  while (validFile == 0)
  { // checks if the file name is valid
    printf("What is the name of your file? (CONVEXPOLYGON.TXT): ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL)
    {
      perror("error, file not found!");
      validFile = 0;
    }
    else
    {
      validFile = 1;
    }
  }
  int n; // number of points of the convex polygon
  fscanf(file, "%d", &n);
  Point points[n]; // x & y values of the points
  for (int i = 0; i < n; i++)
  {
    fscanf(file, "%lf %lf", &points[i].x, &points[i].y);
  }
  fclose(file);

  // call graham scans algorithm
  grahamScan(P0, points, n, &convexHull, &time);

  // input the convex hull into an text file
  printf("Enter output filename (CONVEXHULL.TXT): ");
  scanf("%s", filename);
  file = fopen(filename, "w");
  fprintf(file, "Processor time taken for convex hull using insertion sort: %lf "
                "seconds\n",
          (double)time / CLOCKS_PER_SEC); // input time
  fprintf(file, "%d\n", convexHull.top + 1);
  for (int i = 0; i <= convexHull.top; i++)
  { // input convex hull
    fprintf(file, "(%lf, %lf)\n", convexHull.data[i].x, convexHull.data[i].y);
  }
  fclose(file);
  return 0;
}
