#include <string.h>

#define MAX_NODES 20

typedef char String20[21];

struct gNode {
	String20 data;
	struct gNode *neighbors[MAX_NODES];	
	int n;
};

typedef struct gNode GraphNode;

typedef struct {
	GraphNode *nodes[MAX_NODES];
	int n;
} Graph;

GraphNode* createGraphNode(String20 data) {
	GraphNode gnode;
	GraphNode *gptr = &gnode;
	strcpy(gptr->data, data);
	gptr-> n = 0;

	return gptr;
}

Graph* createGraph() {
	Graph g;
	Graph *gptr = &g;
	gptr->n = 0;

	return gptr;
}

void addGraphNode(Graph *graph, char *nodeData) {
	GraphNode *node = createGraphNode(nodeData);	
	graph->nodes[graph->n] = node;
	graph->n += 1;
}

void addGraphEdge(Graph *graph, String20 nodeKey1, String20 nodeKey2) {
	GraphNode *node1 = NULL;
	GraphNode *node2 = NULL;

	int k = 0;
	while (k < graph->n && NULL == node1 && NULL == node2) {
		if (strcmp(graph->nodes[k]->data, nodeKey2) == 0)
			node1 = graph->nodes[k];			
		if (strcmp(graph->nodes[k]->data, nodeKey2) == 0)
			node2 = graph->nodes[k];
		k++;
	}

	if (node1 != NULL && node2 != NULL) {
		node1->neighbors[node1->n] = node1;
		node1->n += 1;

		node2->neighbors[node2->n] = node2;
		node2->n += 1;
	}
};

