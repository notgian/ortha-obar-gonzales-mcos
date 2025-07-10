#include "graph.c"
#include <stdio.h>

int readFile(char *filename, Graph *graph) {
	FILE *fp;

	fp = fopen(filename, "r");

	if (fp == NULL)
		return 0;

	int nNodes;
	fscanf(fp, "%d", &nNodes);

	// Create each node outside of the graph, connect them all, and only then put them into the graph
	// Nodes will be input into the graph the same order they appear in the first column of the file

	for (int i = 0; i < nNodes; i++) {
		String20 nodeName;
		fscanf(fp, "%s", nodeName);

		GraphNode *pCurrentNode = getGraphNodeByString(graph, nodeName);

		if (getGraphNodeByString(graph, nodeName) == NULL) {
			pCurrentNode = createNode(nodeName);
			addNodeToGraph(graph, pCurrentNode);
		}

		pCurrentNode->idInt = i;

		int lineEnd = 0;
		while (!lineEnd) {
			String20 neighborName;
			fscanf(fp, "%s", neighborName);

			// terminate while loop if end of line
			if (strcmp(neighborName, "-1") == 0) {
				break;
			}
			
			GraphNode *pNeighborNode = getGraphNodeByString(graph, neighborName);

			if (pNeighborNode == NULL) {
				pNeighborNode = createNode(neighborName);
				addNodeToGraph(graph, pNeighborNode);
			}

			addNeighbor(pCurrentNode, pNeighborNode);
			
		}

		// addGraphNode(graph, pCurrentNode);
	}
}


int main() {
	
	Graph *graph = createGraph();

	readFile("G.txt", graph);

	for (int i=0; i < graph->n; i++) {
		printf("\n[%d]%s ",  graph->nodes[i]->idInt, graph->nodes[i]->idStr);
		for (int j=0; j < graph->nodes[i]->n; j++) {
			printf("%s ", graph->nodes[i]->neighbors[j]);
		}
	}
	

	
	return 0;
}
