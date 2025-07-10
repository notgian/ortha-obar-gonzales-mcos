#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 20

typedef char String20[21];
typedef char String8[9];

struct gNode {
	String8 id;
	struct gNode *neighbors[MAX_NODES];	
	int n;
};

// Typedef done separate from struct declaration due to the reflexive use of the the struct in its definition
typedef struct gNode GraphNode;

typedef struct {
	GraphNode *nodes[MAX_NODES];
	int n;
} Graph;

/* createGraphNode - creates a node not attached to a graph, returning a pointer to this node
 * 
 * @return         - pointer to a newly created, empty graph node structure
 */
GraphNode *createNode(char *iding) {
	GraphNode *node = malloc(sizeof(GraphNode)); 	

	strcpy(node->id, iding);

	node->n = 0;
	for (int i=0; i<MAX_NODES; i++) {
		node->neighbors[i] = NULL;
	}

	return node;
}

/* createGraph - initializes and creates a graph data structure, returning a pointer to the graph.
 * 
 * @return     - pointer to a newly created, empty graph data structure
 */
Graph *createGraph() {
	Graph *graph = malloc(sizeof(Graph));
	graph->n = 0;
	for (int i=0; i<MAX_NODES; i++) {
		graph->nodes[i] = NULL;
	}

	return graph;
}

/* addGraphNode    - adds a node with the given data to the graph
 * 				     IMPORTANT: DO NOT change the second parameter type to String20. There is some memory allocation shenanigans here that I cannot explain, but it just works when you keep it like this so trust.
 * @param graph    - pointer to the graph data structure
 * @param node     - node to add to graph
 * 
 * 
 */
void addNodeToGraph(Graph *graph, GraphNode *node) {
	graph->nodes[graph->n] = node;
	graph->n += 1;
}

/* getGraphNode - takes a graph and a search key to look for a node with the specified data
 * @param graph - pointer to the graph data structure
 * @param key   - the search key to find the specified node
 * @return      - returns a pointer to the found node if it was found, otherwise returns NULL 
 */
GraphNode *getGraphNodeByString(Graph *graph, char *key) {
	for (int i = 0; i < graph-> n; i++) {
		if (strcmp(graph->nodes[i]->id, key) == 0)
			return graph->nodes[i];
	}
	return NULL;
}

int nodesAreNeighbors(GraphNode *node1, GraphNode *node2) {
	int alreadyNeighbors = 0;

	for (int i=0; i < node1->n; i++) {
		if (node1->neighbors[i] == node2)
			alreadyNeighbors = 1;
	}

	for (int i=0; i < node2->n; i++) {
		if (node2->neighbors[i] == node1)
			alreadyNeighbors = 1;
	}

	return alreadyNeighbors;
}

/* connectNodes - takes two nodes of a graph and creates and edege. 
 * 				  IMPORTANT: This assumes that the two nodes are part of the graph.
 * @param node1 - the first node of the edge
 * @param node2 - the second node of the edge
 * */
void addNeighbor(GraphNode *destNode, GraphNode *node2) {
	if (destNode != NULL && node2 != NULL) {
		// Check if already neighbors
		int alreadyNeigbored = 0;
		for (int i=0; i< destNode->n; i++) {
			if (destNode->neighbors[i] == node2)
				alreadyNeigbored = 1;
		}

		if (!alreadyNeigbored) {
			destNode->neighbors[destNode->n] = node2;
			destNode->n += 1;
		}
	}

	// printf("\n| %s %s\n", destNode->id, node2->id);
};
// void addEdge(GraphNode *node1, GraphNode *node2) {
// 	if (node1 != NULL && node2 != NULL) {
// 		// Check if already neighbors
// 		if (!nodesAreNeighbors(node1, node2)) {
// 			node1->neighbors[node1->n] = node2;
// 			node1->n += 1;

// 			node2->neighbors[node2->n] = node1;
// 			node2->n += 1;
// 		}
// 	}

// 	printf("\n| %s %s\n", node1->id, node2->id);
// };

