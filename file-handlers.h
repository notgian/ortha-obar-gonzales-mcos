#include "graphs.h"
#pragma once

int readInput(char *fileName, Graph *G, Graph *sortedG);

void outputSets(char graphName, char *outputFileName, Graph *sortedG);
void outputDegrees(char *outputFileName, Graph *sortedG);
void outputAdjacencyList(char *outputFileName, Graph *G);
void outputAdjacencyMatrix(char *outputFileName, Graph *G);
void outputBFS(char *outputFileName, Graph *G, char *startVertex);