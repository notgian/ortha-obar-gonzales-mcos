#include "graphs.c"
#include "file-handlers.c"

int main(){
  Graph G;
  Graph sortedG;
  char fileName[64];
  char startVertex[MAX_VERTEX_NAME];
  char outputFileName[64];
  printf("Input the filename: ");
  scanf("%s", fileName); 
  initGraph(&G);
  initGraph(&sortedG);
  if(readInput(fileName, &G ,&sortedG) == 1){
    
    snprintf(outputFileName, sizeof(outputFileName), "%c-SET.TXT", fileName[0]);//output file name for file#1
    outputSets(outputFileName, &sortedG); //output file #1
    snprintf(outputFileName, sizeof(outputFileName), "%c-DEGREE.TXT", fileName[0]);//output file name for file#2
    outputDegrees(outputFileName, &sortedG); //output file #2
    snprintf(outputFileName, sizeof(outputFileName), "%c-LIST.TXT", fileName[0]);//output file name for file #3
    outputAdjacencyList(outputFileName, &G); //output file #3
    snprintf(outputFileName, sizeof(outputFileName), "%c-MATRIX.TXT", fileName[0]);//output file name for file #4
    outputAdjacencyMatrix(outputFileName, &G); //output file #4
    printf("Input start vertex for the traversal: ");
    scanf("%s", startVertex);
    if(vertexExists(&G, startVertex) == 1){//checks if the starting vertex is valid/exists
      snprintf(outputFileName, sizeof(outputFileName), "%c-BFS.TXT", fileName[0]);//output file name for file #5
      outputBFS(outputFileName, &G, startVertex);//output file #5
      snprintf(outputFileName, sizeof(outputFileName), "%c-DFS.TXT", fileName[0]);//output file name for file #6
      outputDFS(outputFileName, &G, startVertex);//output file #5
    }
    else{
      printf("Vertex %s not found.\n", startVertex);
    }
  }
  return 0;
}