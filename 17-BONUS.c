#include "graphs.c"
#include "file-handlers.c"
#include <stdio.h>
#include <string.h>

int main() {
    Graph graphA;
    Graph graphASorted;
    initGraph(&graphA);
    initGraph(&graphASorted);

    Graph graphB;
    Graph graphBSorted;
    initGraph(&graphB);
    initGraph(&graphBSorted);

    char fileNameA[64];
    char graphAName;
    FILE *fileA;

    char fileNameB[64];
    char graphBName;
    FILE *fileB;

    printf("Please input the filename for the first graph:\n");
    scanf("%s", fileNameA);
    graphAName = fileNameA[0];
    fileA = fopen(fileNameA, "r");
    
    if (fileA == NULL) {
        printf("File cannot be found. Aborting operation\n");
        return -1;
    }

    printf("Please input the filename for the second graph:\n");
    scanf("%s", fileNameB);
    graphBName = fileNameB[0];
    fileB = fopen(fileNameB, "r");

    if (fileB == NULL) {
        printf("File cannot be found. Aborting operation\n");
        return -1;
    }

    readInput(fileNameA, &graphA, &graphASorted);
    readInput(fileNameB, &graphB, &graphBSorted);   

    // producing output file #7

    char outputFileName[17];
    sprintf(outputFileName, "%c-%c-SUBGRAPH.TXT", graphAName, graphBName);

    FILE *outfp = fopen(outputFileName, "w");
    if (outfp == NULL) {
        printf("Error in creating the output file. Aborting operation.");
        return -1;
    }

    int isSubgraph = 1;

    // For vertices
    for (int i=0; i < graphBSorted.vertexCount; i++) {
        char vertexInB[MAX_VERTEX_NAME];
        strcpy(vertexInB, graphBSorted.vertices[i]);

        int vertexFoundInA = 0;

        for (int j=0; j<graphASorted.vertexCount; j++) {
            char vertexInA[MAX_VERTEX_NAME];
            strcpy(vertexInA, graphASorted.vertices[j]);

            if (strcmp(vertexInA, vertexInB) == 0)
                vertexFoundInA = 1;
        }

        char endSymbol = '-';
        if (vertexFoundInA)
            endSymbol = '+';
        else
            isSubgraph = 0;
        
        fprintf(outfp, "%s %c\n", vertexInB, endSymbol);
    }

    // For Edges
    for (int i=0; i < graphBSorted.vertexCount; i++) {
        char vertexInB[MAX_VERTEX_NAME];
        strcpy (vertexInB, graphBSorted.vertices[i]);

        int vertexIndexInB = i;

        char vertexInA[MAX_VERTEX_NAME];
        int vertexIndexInA = -1;

        for (int j=0; j<graphASorted.vertexCount; j++) {
            strcpy(vertexInA, graphASorted.vertices[j]);

            if (strcmp(vertexInA, vertexInB) == 0)
                vertexIndexInA = j;
        }
        
        for (int k=0; k < graphBSorted.adjacencyCount[vertexIndexInB]; k++) {
            char adjacencyInB[MAX_VERTEX_NAME];
            strcpy(adjacencyInB, graphBSorted.adjacencyList[vertexIndexInB][k]);

            int adjacencyFoundInA = 0;

            // To avoid duplicates and ensure that (u,v) such that u > v in ASCII comparison. Put simply, ensuring they're alphabetically sorted.
            if (strcmp(vertexInB, adjacencyInB) > 0) 
                continue;
                
            if (vertexIndexInA > -1) {
                for (int l=0; l < graphASorted.adjacencyCount[vertexIndexInA]; l++) {
                    char adjacencyInA[MAX_VERTEX_NAME];
                    strcpy(adjacencyInA, graphASorted.adjacencyList[vertexIndexInA][l]);
    
                    if (strcmp(adjacencyInA, adjacencyInB) == 0)
                        adjacencyFoundInA = 1;
                }
            }
            
            char endSymbol = '-';
            if (adjacencyFoundInA)
                endSymbol = '+';
            else
                isSubgraph = 0;
            
            fprintf(outfp, "(%s,%s) %c\n", vertexInB, adjacencyInB, endSymbol);
        }
    }

    if (isSubgraph)
        fprintf(outfp, "%c is a subgraph of %c.", graphBName, graphAName);
    else
        fprintf(outfp, "%c is not a subgraph of %c.", graphBName, graphAName);

    fclose(outfp);

    return 0;

    // List vertices in the second graph (alphabetical order) with '+' or '-'
    // List of edges in alphabetical order
    // Graph __ is (not) a subgraph of ___.
}