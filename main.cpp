#include <iostream>
#include "Graph.h"
#include "DFS.h"
#include "uniform_cost.h"
#include "A_search.h"

using namespace std;

int main() {
    Graph::init();

    Graph graph;
    DFS dfsearch(&graph);
    dfsearch.DFS_nonRecursive("Arad", "Bucharest");
    dfsearch.output();

    graph.setUnvisited();
    uniform_cost ucost(&graph);
    ucost.uniform_cost_search("Arad", "Bucharest");
    ucost.output();

    graph.setUnvisited();
    A_search a_search(&graph);
    a_search.uniform_cost_search("Arad", "Bucharest");
    a_search.output();

    graph.setUnvisited();
    return 0;
}