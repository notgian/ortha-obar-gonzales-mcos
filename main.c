#include <stdio.h>
#include <string.h>
#include "stack.c"
#include "sort.c"
#include "geom.c"
#include "graham_scan.c"
#include "timer.c"

typedef char String[100];

int main()
{
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
    Point pointsA[inputSize];
    Point pointsB[inputSize];

    for (int i = 0; i < inputSize; i++)
        fscanf(file, "%lf %lf", &points[i].x, &points[i].y);
    
    fclose(file);

    // copy points to arrays
    for (int i=0; i < inputSize; i++) 
    {
        pointsA[i] = points[i];
        pointsB[i] = points[i];
    }

    Stack convexHullA;
    Stack convexHullB;

    Timer timer;
    double elapsedA;
    double elapsedB;

    // Calling Graham Scan Algorithims
    printf("========================================================\n");
    printf("   Running Graham Scan Algorithim (Slow Sorting Algo)\n");
    printf("========================================================\n");

    startTimer(&timer);
    grahamScanSlow(pointsA, inputSize, &convexHullA);
    endTimer(&timer);
    elapsedA = timer.elapsed;

    printf("          Execution completed in %10lfms\n", elapsedA);
    printf("========================================================\n");
    printf("\n\n");

    printf("========================================================\n");
    printf("   Running Graham Scan Algorithim (Fast Sorting Algo)\n");
    printf("========================================================\n");

    startTimer(&timer);
    grahamScanFast(pointsB, inputSize, &convexHullB);
    endTimer(&timer);
    elapsedB = timer.elapsed;

    printf("          Execution completed in %10lfms\n", elapsedB);
    printf("========================================================\n");

    //  Output data into their respective text files
    String outFilePrefix;
    String outFileSlow;
    String outFileFast;

    printf("\n\nExecution completed.\n");
    printf("Please enter output filename prefix:\n");
    scanf("%s", outFilePrefix);

    // For slow sorting algo version
    strcpy(outFileSlow, outFilePrefix);
    strcat(outFileSlow, "-slow.txt");

    file = fopen(outFileSlow, "w");
    fprintf(file, "Elapsed Time: %lfms\n", elapsedA);
    fprintf(file, "%d\n", convexHullA.top + 1);
    for (int i = 0; i <= convexHullA.top; i++)
    {
        fprintf(file, "%-10lf %-10lf\n", convexHullA.data[i].x, convexHullA.data[i].y);
    }
    fclose(file);

    // For fast sorting algo version
    strcpy(outFileFast, outFilePrefix);
    strcat(outFileFast, "-fast.txt");

    file = fopen(outFileFast, "w");
    fprintf(file, "Elapsed Time: %lfms\n", elapsedB);
    fprintf(file, "%d\n", convexHullB.top + 1);
    for (int i = 0; i <= convexHullB.top; i++)
    {
        fprintf(file, "%-10lf %-10lf\n", convexHullB.data[i].x, convexHullB.data[i].y);
    }
    fclose(file);

    return 0;
}
