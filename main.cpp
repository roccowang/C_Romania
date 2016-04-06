#include <iostream>
#include "Graph.h"
#include "DFS.h"

using namespace std;

int main() {
    Graph::init();
    Graph nonrecursive;
    DFS search(&nonrecursive);
    search.DFS_nonRecursive("Arad", "Bucharest");
    search.output();
    return 0;
}