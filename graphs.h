#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma once

#define MAX_VERTICES 20 //defines the maximum number of vertices allowed
#define MAX_VERTEX_NAME 9 //allows the names of the vertices to be at most 8 characters
#define MAX_EDGES 200 //maximum number (190) of unique edges in a graph with the most allowed vertices (20) rounded off to (200) for simplicity

typedef struct {// Structure of the graph 
    char vertices[MAX_VERTICES][MAX_VERTEX_NAME]; //holds the vertices
    char adjacencyList[MAX_VERTICES][MAX_VERTICES][MAX_VERTEX_NAME]; //adjacency list 
    int adjacencyCount[MAX_VERTICES];  
    int vertexCount;
} Graph;

void initGraph(Graph *G);
int vertexExists(Graph *G, char *vertexName);
void addVertex(Graph *G, char *vertexName);
int adjacencyExist(Graph *G, char *nextVertex, int u);
int getVertexIndex(Graph *G, char *vertexName);
void addAdjacency(Graph *G, char *firstVertex, char *nextVertex);
void sortGraph(Graph *G);
void BFSTraversal(Graph *G, char *startVertex, int *visitOrder, int *count);
void DFSTraversal(Graph *G, char startVertex[MAX_VERTEX_NAME], char traversalStringOutput[MAX_VERTICES*MAX_VERTEX_NAME]);