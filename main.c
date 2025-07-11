#include "graph.c"
#include <stdio.h>

GraphNode *getInTempNodeList(GraphNode *tempNodeList[], int n, char *stringKey) {
	GraphNode *ptr = NULL;
	for (int i=0; i<n; i++) {
		if (strcmp(tempNodeList[i]->id, stringKey) == 0)
			ptr = tempNodeList[i];
	}
	
	return ptr;
}

int readFile(char *filename, Graph *graph) {
	FILE *fp;

	fp = fopen(filename, "r");

	if (fp == NULL)
		return 0;

	int nNodes;
	fscanf(fp, "%d", &nNodes);

	GraphNode *tempNodes[nNodes];
	
	int tempN = 0;

	for (int i = 0; i < nNodes; i++) {
		String20 nodeName;
		fscanf(fp, "%s", nodeName);

		GraphNode *pCurrentNode = getInTempNodeList(tempNodes, tempN, nodeName);

		if (pCurrentNode == NULL) {
			pCurrentNode = createNode(nodeName);
			tempNodes[tempN] = pCurrentNode;
			tempN++;
		}

		addNodeToGraph(graph, pCurrentNode);

		while (1) {
			String20 neighborName;
			fscanf(fp, "%s", neighborName);

			// terminate while loop if end of line
			if (strcmp(neighborName, "-1") == 0) {
				break;
			}

			GraphNode *pNeighborNode = getInTempNodeList(tempNodes, tempN, neighborName);

			if (pNeighborNode == NULL) {
				pNeighborNode = createNode(neighborName);
				tempNodes[tempN] = pNeighborNode;
				tempN++;
			}

			addNeighbor(pCurrentNode, pNeighborNode);
			
		}

		// addGraphNode(graph, pCurrentNode);
	}

	return 1;
}


int main() {
	
	Graph *graph = createGraph();

	readFile("Y.txt", graph);

	printf("\n\n%d", graph->n);
	for (int i=0; i < graph->n; i++) {
		printf("\n%s->", graph->nodes[i]->id);
		for (int j=0; j < graph->nodes[i]->n; j++) {
			printf("%s->", graph->nodes[i]->neighbors[j]->id);
		}
		printf("\\");
	}

	printf("\n\n");
		
	return 0;
}
