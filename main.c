#include "graph.c"
#include <stdio.h>

GraphNode *getInTempNodeList(GraphNode *tempNodeList[], int n, char *stringKey) {
	GraphNode *ptr = NULL;
	printf("\nKEY: %s\n",stringKey);
	for (int i=0; i<n; i++) {
		printf("%s ", tempNodeList[i]->id);
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
		printf("\n%s ", nodeName);

		GraphNode *pCurrentNode = getInTempNodeList(tempNodes, nNodes, nodeName);

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

			GraphNode *pNeighborNode = getInTempNodeList(tempNodes, nNodes, neighborName);

			if (pNeighborNode == NULL) {
				pNeighborNode = createNode(neighborName);
				tempNodes[tempN] = pNeighborNode;
				tempN++;
			}

			addNeighbor(pCurrentNode, pNeighborNode);
			
		}

		// addGraphNode(graph, pCurrentNode);
	}
}


int main() {
	
	Graph *graph = createGraph();

	readFile("G.txt", graph);

	printf("\n\n%d", graph->n);
	for (int i=0; i < graph->n; i++) {
		printf("\n%s->", graph->nodes[i]->id);
		for (int j=0; j < graph->nodes[i]->n; j++) {
			printf("%s->", graph->nodes[i]->neighbors[j]);
		}
		printf("\\");
	}
		
	return 0;
}
