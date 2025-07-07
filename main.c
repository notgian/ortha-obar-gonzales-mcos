#include "graph.c"

int main() {
	
	Graph *g = createGraph();
	
	addGraphNode(g, "1");
	addGraphNode(g, "22");
	return 0;
}
