#include "file-handlers.h"
#include "graphs.h"

/*function outputSets prints the  set of vertices V(G) and set of edges E(G) on a graph-SET.txt
@param fileName - holds the name of the input file
@param sortedG - holds the sorted values of the graph
*/
void outputSets(char graphName, char *outputFileName, Graph *sortedG){
    int first = 1;
    char *u;
    char *v;
    FILE *file = fopen(outputFileName, "w");
  
    if(file == NULL){
      printf("Could not create the output file: %s\n", outputFileName);
      return;
    }
  
    // For vertex set
    fprintf(file, "V(%c)={", graphName);
    for (int i = 0; i < sortedG->vertexCount; i++){
      fprintf(file, "%s", sortedG->vertices[i]);
  
      // If next exists
      if (i < sortedG->vertexCount - 1){
        fprintf(file, ",");
      }
    }
    fprintf(file, "}\n");
  
    fprintf(file, "E(%c)={", graphName);
    for(int i = 0; i < sortedG->vertexCount; i++){
      u = sortedG->vertices[i];
      
      for(int j = 0; j < sortedG->adjacencyCount[i]; j++){
        v = sortedG->adjacencyList[i][j];
        if(strcmp(u, v) < 0){// avoids duplicates, Diana-Hal == Hal-Diana 
          if(!first){ 
            fprintf(file, ",");
          }
          fprintf(file, "(%s,%s)", u, v);
          first = 0;
        }
      }
    }
    fprintf(file, "}\n");
    fclose(file);
  }
  
  /*function outputDegress prints the list of vertex IDs with the corresponding degree for each vertex
  @param fileName - holds the name of the input file
  @param sortedG - holds the sorted values of the graph
  */
  void outputDegrees(char *outputFileName, Graph *sortedG) {
    FILE *file = fopen(outputFileName, "w");
    if(file == NULL){
      printf("Could not create the output file: %s\n", outputFileName);
      return;
    }
  
    for (int i = 0; i < sortedG->vertexCount; i++) {
          fprintf(file, "%s %d\n", sortedG->vertices[i], sortedG->adjacencyCount[i]);//prints the vertices with their respective degrees
    }
    fclose(file);
  }
  
  /*function outputAdjacencyList prints the adjacency List representation of the graph
  @param fileName - holds the name of the input file
  @param G - holds the values of the graph
  */
  void outputAdjacencyList(char *outputFileName, Graph *G){
    FILE *outputFile = fopen(outputFileName, "w");
  
    if(outputFile == NULL){
      printf("Error opening output file: %s\n", outputFileName);
      return;
    }
    for(int i = 0; i < G->vertexCount; i++){//iterates through the primary vertices
      fprintf(outputFile, "%s", G->vertices[i]);
      for(int j = 0; j < G->adjacencyCount[i]; j++){//iterates through the adjacency vertices
        fprintf(outputFile, "->%s", G->adjacencyList[i][j]);
      }
        fprintf(outputFile, "->\\\n");
    }
    fclose(outputFile);
  }
  
  
  /*function outputAdjacencyMatrix prints the adjacency matrix representation of the graph. 
  @param fileName - holds the name of the input file
  @param G - holds the values of the graph
  */
  void outputAdjacencyMatrix(char *outputFileName, Graph *G){
    int numVertices = G->vertexCount;
    int connected;//holds 1 or 0 if the vertex is connected to another vertex
    FILE *outputFile = fopen(outputFileName, "w");
    if(outputFile == NULL){
      printf("Error opening output file: %s\n", outputFileName);
      return;
    }
    fprintf(outputFile, "%-8s", "");//for alignment of the header row
    for(int i = 0; i < numVertices; i++){
      fprintf(outputFile, "%-8s", G->vertices[i]);//for the header row
    }
    fprintf(outputFile, "\n");
      
    for (int i = 0; i < numVertices; i++) {//prints a row containing a primary vertex
      fprintf(outputFile, "%-8s", G->vertices[i]);
      for(int j = 0; j < numVertices; j++){
        connected = 0;
        for(int k = 0; k < G->adjacencyCount[i]; k++){
          if(strcmp(G->adjacencyList[i][k], G->vertices[j]) == 0){//checks if there is an adjacency 
            connected = 1;
            break;
          }
        }
        fprintf(outputFile, "%-8d", connected);//prints 1 or 0
      }
      fprintf(outputFile, "\n");//goes over the next row
    }
    fclose(outputFile);
  }

/*function outputBFS prints out the BFS textfile
@param G - holds the values of the graph
@param fileName - holds the name of the input file 
@param startVertex - holds the name of the starting vertex for traversal
*/
void outputBFS(char *outputFileName, Graph *G, char *startVertex) {
    int visitOrder[MAX_VERTICES];
    int count = 0; //integer to hold how many vertices have been visited 
    BFSTraversal(G, startVertex, visitOrder, &count);//Breathd First Search
    FILE *file = fopen(outputFileName, "w");
    if (file == NULL) {
        printf("Error opening output file %s.\n", outputFileName);
        return;
    }
    for (int i = 0; i < count; i++) {//prints out the BFS results
        fprintf(file, "%s", G->vertices[visitOrder[i]]);
        if (i < count - 1) fprintf(file, " ");
    }
    fprintf(file, "\n");
    fclose(file);
}

/* outputDFS: produces the DFS textfile. Assumes the start vertex exists as
   @param outputFileName - name of the output file
   @param G              - pointer to the graph data structure
   @param startVertex    - vertex ID to begin the traversal from
*/
void outputDFS(char *outputFileName, Graph *G, char *startVertex) {
    char DFSOutput[MAX_VERTICES*MAX_VERTEX_NAME];
    DFSTraversal(G, startVertex, DFSOutput);

    FILE *file = fopen(outputFileName, "w");
    if (file == NULL) {
        printf("Error opening output file %s.\n", outputFileName);
        return;
    }

    fprintf(file, DFSOutput);
    fclose(file);
}

