#include <stdio.h>
#include <string.h>
#include "geom.c"
#include "stack.c"
#include "timer.c"
#include "sort.c"
#include "graham_scan1.c"

typedef char String[100];

int main() {
    FILE *file = NULL;
    String inputFileName;
    
    while (NULL == file)
    {
        printf("Please enter the file name of your input data:\n");
        scanf("%s", inputFileName);
        file = fopen(inputFileName, "r");
        if (file == NULL)
            perror("Error! File Not Found");
    }

    int inputSize; 
    fscanf(file, "%d", &inputSize);
    Point points[inputSize];

    for (int i = 0; i < inputSize; i++)
        fscanf(file, "%lf %lf", &points[i].x, &points[i].y);
    
    fclose(file);

    Stack convexHull;

    Timer timer;
    double elapsed;

    // Calling Graham Scan Algorithims
    printf("========================================================\n");
    printf("   Running Graham Scan Algorithim (Slow Sorting Algo)\n");
    printf("========================================================\n");

    startTimer(&timer);
    grahamScanSlow(points, inputSize, &convexHull);
    endTimer(&timer);
    elapsed = timer.elapsed;

    printf("          Execution completed in %10lfms\n", elapsed);
    printf("========================================================\n");
    printf("\n");

    //  Output data into text file
    String outFilePrefix;
    String outFileSlow;

    printf("Please enter output filename prefix:\n");
    scanf("%s", outFilePrefix);

    strcpy(outFileSlow, outFilePrefix);
    strcat(outFileSlow, "-slow.txt");

    file = fopen(outFileSlow, "w");
    fprintf(file, "%d\n", convexHull.top + 1);
    for (int i = 0; i <= convexHull.top; i++)
    {
        fprintf(file, "%.6lf %.6lf\n", convexHull.data[i].x, convexHull.data[i].y);
    }
    fclose(file);

    return 0;
}