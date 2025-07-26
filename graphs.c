#include "graphs.h"

/*function initGrap initializes the given graph
@param G - holds the values of the graph
*/
void initGraph(Graph *G){
  G->vertexCount = 0;

  //initializes the adjacency list to nothing for now
  for(int i = 0; i < MAX_VERTICES; i++){//iterates through every possible index
    G->adjacencyCount[i] = 0;
    G->vertices[i][0] = '\0';
    for(int j = 0; j < MAX_VERTICES; j++){//iterates through every possible adjacent vertex
      G->adjacencyList[i][j][0] = '\0'; //this clears each adjacency string
    }
  }
}

/*function vertexExists checks if a vertex already exist in the graph
@param G - holds the values of the graph
@param vertexName - holds the name of the vertex to be found in the graph
@return - returns 1 if found, 0 if not found
*/
int vertexExists(Graph *G, char *vertexName){
  int returnVal = 0;
  for(int i = 0; i < G->vertexCount; i++){
    if(strcmp(G->vertices[i], vertexName) == 0){//cheks if the vertex is already in the graph
      returnVal = 1;
      break;
    }
  }
  return returnVal;
}


/*function vertexExists adds a vertex that is not already in the graph 
@param G - holds the values of the graph
@param vertexName - holds the name of the vertex to be added in the graph
*/
void addVertex(Graph *G, char *vertexName){
  if(vertexExists(G, vertexName) == 0 && G->vertexCount < MAX_VERTICES) {//checks if the vertex does not exist in the graph and if the graph has reached its maximum number of vertices
    strcpy(G->vertices[G->vertexCount], vertexName);
    G->vertexCount++;
  }
}

/*function adjacencyExist checks if the nextVertex is already in the adjacency list of the primary vertex 
@param G - holds the values of the graph
@param secondVertex - holds the adjacency of the primary vertex
*/
int adjacencyExist(Graph *G, char *nextVertex, int u){
  int returnVal = 0;
  for(int i = 0; i < G->adjacencyCount[u]; i++){
    if(strcmp(G->adjacencyList[u][i], nextVertex) == 0){//itarates throgh the adjacency list
      returnVal = 1;
    }
  }
  return returnVal;
}

/*function addAdjacency adds the adjacencies of the vertices to a list 
@param G - holds the values of the graph
@param firstVertex - holds the primary vertex
@param secondVertex - holds the adjacency of the primary vertex
*/
void addAdjacency(Graph *G, char *firstVertex, char *nextVertex) {
  int u = getVertexIndex(G, firstVertex);//gets the index of the primary vertex
  if(u == -1){//checks if the index of the primary vertex is valid
    return;
  }
  if(adjacencyExist(G, nextVertex, u) == 1){
    return;
  }
  strcpy(G->adjacencyList[u][G->adjacencyCount[u]++], nextVertex); //stores the adjacency vertex in the list
}

/*function readInput reads the name of the input file given by the user
@param fileName - holds the name of the input file
@param G - holds the values of the graph
@param sortedG - holds the sorted values of the graph
@return - returns 1 of the file exist, else 0
*/
int readInput(char *fileName, Graph *G, Graph *sortedG){
  int valid = 0;//determines of the fileName is valid
  int numVertices;//holds the number of vertices 
  char firstWord[MAX_VERTEX_NAME];
  char vertex[MAX_VERTEX_NAME];
  char nextVertex[MAX_VERTEX_NAME];
  FILE *file = fopen(fileName, "r");

  if(file == NULL){//checks if the file exist
    printf("File %s not found.\n", fileName);
    return valid;
  }
  else{
    valid = 1;
    fscanf(file, "%d\n", &numVertices);
    for (int i = 0; i < numVertices; i++){//iterate trough the file based on the number of vertices
      fscanf(file, "%s", firstWord);
      if (strcmp(firstWord, "") == 0) {
        continue; //iterate immediately to the next line if currentLine is empty
      }
      strcpy(vertex, firstWord);//copies the firstWord to the vertex
      addVertex(G, vertex);//adds the vertices of the graph
      addVertex(sortedG, vertex);
      while (fscanf(file, "%s", firstWord) == 1 && strcmp(firstWord, "-1") != 0){//iterate though the line adding each vertex up until reaching -1
        strcpy(nextVertex, firstWord); //stores the adjancency vertix
        addAdjacency(G, vertex, nextVertex);//adds the adjancencies of the vertices in the graph
        addAdjacency(sortedG, vertex, nextVertex);
      }
    }
  }
  fclose(file);
  sortGraph(sortedG);
  return valid;
}

void sortGraph(Graph *G) {
  char tempVertexName[MAX_VERTEX_NAME];
  char tempAdjacencyList[MAX_VERTICES][MAX_VERTEX_NAME];
  int tempAdjacencyCount;

  // Pass to sort the vertices
  for(int i = 0; i < G->vertexCount - 1; i++){
    for(int j = i + 1; j < G->vertexCount; j++){//iterates through all the vertices 
      if(strcmp(G->vertices[i], G->vertices[j]) > 0){//sorts the vertices alphabetically

        // Store i to temp
        strcpy(tempVertexName, G->vertices[i]);
        for (int k=0; k < G->adjacencyCount[i]; k++) {
          strcpy(tempAdjacencyList[k], G->adjacencyList[i][k]);
        }
        tempAdjacencyCount = G->adjacencyCount[i];

        // swap i and j
        strcpy(G->vertices[i], G->vertices[j]);
        for (int k=0; k < G->adjacencyCount[j]; k++) {
          strcpy(G->adjacencyList[i][k], G->adjacencyList[j][k]);
        }
        G->adjacencyCount[i] = G->adjacencyCount[j];

        // store temp to j
        strcpy(G->vertices[j], tempVertexName);
        for (int k=0; k < tempAdjacencyCount; k++) {
          strcpy(G->adjacencyList[j][k], tempAdjacencyList[k]);
        }
        G->adjacencyCount[j] = tempAdjacencyCount;
      }
    }
  }

  // Pass to sort each adjacencyList
  char tempAdjacencyName[MAX_VERTEX_NAME];
  
  for(int i = 0; i < G->vertexCount; i++) {
    for(int j = 0; j < G->adjacencyCount[i] - 1; j++) {
      for(int k = j + 1; k < G->adjacencyCount[i]; k++)   { 
        if(strcmp(G->adjacencyList[i][j], G->adjacencyList[i][k]) > 0) {
          
          strcpy(tempAdjacencyName, G->adjacencyList[i][j]);
          strcpy(G->adjacencyList[i][j], G->adjacencyList[i][k]);
          strcpy(G->adjacencyList[i][k], tempAdjacencyName);
        }
      }
    }
  }
}

/*function getVertexIndex is used to get the indexes of the vertices
@param G - holds the values of the graph
@param vertexName - holds the name of a vertex
@return - returns the index of the vertex, if vertexName does not exist in the graph, return -1
*/
int getVertexIndex(Graph *G, char *vertexName){
  int vertexIndex = -1;
  for(int i = 0; i < G->vertexCount; i++){//iterates through the vertices and gets their index
    if(strcmp(G->vertices[i], vertexName) == 0){
      vertexIndex = i;
      break;
    }
  }
  return vertexIndex;
}

/*function BFSTraversal is used to get the indexes of the vertices
@param G - holds the values of the graph
@param startVertex - holds the name of the starting vertex for traversal
@param visitOrder - stores the order in which vertices are visited
@param count - counts how many vertices have been visited
@return - returns the index of the vertex, if vertexName does not exist in the graph, return -1
*/
void BFSTraversal(Graph *G, char *startVertex, int *visitOrder, int *count) {
  int visitedVertices[MAX_VERTICES] = {0}; // this tracks if a vertex was visited
  int queue[MAX_VERTICES];//a queue for BFS traversal
  int front = 0, rear = 0;//the front and rear of a queue
  int current;
  int nextVertices[MAX_VERTICES];//the next vertices following the starting vertex
  int nextVertexCount = 0;//counts how many vertices follows the starting vertex
  int temp;
  int startIndex = getVertexIndex(G, startVertex);//the index of the starting vertex
  int adjacencyIndex;//gets the index of the adjacent vertices from the adjacency list
  if(startIndex == -1){
    return;
  }
  visitedVertices[startIndex] = 1;//this marks that the starting vertex has been visited
  queue[rear++] = startIndex;//adds the starting vertex to the queue
  while(front < rear){
    current = queue[front++];//dequeue the front vertex
    visitOrder[(*count)++] = current;//store it in the visit order
    nextVertexCount = 0;
    for(int i = 0; i < G->adjacencyCount[current]; i++){  //iterate through adjacency list to find nextVertices
      adjacencyIndex = getVertexIndex(G, G->adjacencyList[current][i]);
      if(!visitedVertices[adjacencyIndex]){//checks if the vertex is already visited
        nextVertices[nextVertexCount++] = adjacencyIndex;//adds the index of the adjacent vertex to the nextVertices array
      }
    }
    for(int i = 0; i < nextVertexCount - 1; i++){//sorts the nextVertices by vertex index(lowest ID first)
      for(int j = i + 1; j < nextVertexCount; j++){
        if(nextVertices[i] > nextVertices[j]){//sorts the vertex indexes by ascending order
          temp = nextVertices[i];
          nextVertices[i] = nextVertices[j];
          nextVertices[j] = temp;
        }
      }
    }
    for(int i = 0; i < nextVertexCount; i++){ //enqueue the nextVertices
      visitedVertices[nextVertices[i]] = 1;
      queue[rear++] = nextVertices[i];
    }
  }
}

void DFSTraversal(Graph *G, char startVertex[MAX_VERTEX_NAME], char traversalStringOutput[MAX_VERTICES*MAX_VERTEX_NAME]) {
  char stack[MAX_VERTICES][MAX_VERTEX_NAME];
  int stackTop = -1;

  char visited[MAX_VERTICES][MAX_VERTEX_NAME];
  int visitIndex = -1;
  
  // Mark start vertex as visited and push to stack
  stackTop++;
  strcpy(stack[stackTop], startVertex);

  visitIndex++;
  strcpy(visited[visitIndex], startVertex);

  while (stackTop > -1) {
    int currentVertextIndex = getVertexIndex(G, stack[stackTop]);

    char vertexName[MAX_VERTEX_NAME] = "";

    for (int i=0; i < G->adjacencyCount[currentVertextIndex]; i++) {
      char adjacencyName[MAX_VERTEX_NAME];

      strcpy(adjacencyName, G->adjacencyList[currentVertextIndex][i]);

      int elligible = 1;

      // Check if current adjacent vertex has been visited
      for (int i=0; i<=visitIndex; i++) {
        if (strcmp(adjacencyName, visited[i]) == 0) {
          elligible = 0;
          break;
        }
      }
      
      if (elligible) {
        if (strlen(vertexName) == 0)
          strcpy(vertexName, adjacencyName);
        // traversal vertices alphabetically
        else if (strcmp(adjacencyName, vertexName) < 0) {
          strcpy(vertexName, adjacencyName);
        }
      }
    }

    // No elligible vertex exists, pop from stack
    if (strlen(vertexName) == 0) {
      stackTop--;
    }
    // Elligible vertex exists
    else {
      stackTop++;
      strcpy(stack[stackTop], vertexName);

      if (stackTop > 20)
        return;

      visitIndex++;
      strcpy(visited[visitIndex], vertexName);
    }
  }

  // Construct output
  strcpy(traversalStringOutput, startVertex);
  for (int i=1; i<=visitIndex; i++) {
    strcat(traversalStringOutput, " ");
    strcat(traversalStringOutput, visited[i]);
  }
}

