//
// Created by Rocco Wang on 16/4/6.
//

#ifndef C_ROMANIA_DFS_H
#define C_ROMANIA_DFS_H

#include "Graph.h"
#include <deque>
#include <iostream>

using namespace std;

class DFS {
private:
    Graph *g;
    deque<string> solution;
public:
    DFS(Graph *graph);

    void DFS_nonRecursive(string start, string goal);

    void output();
};


#endif //C_ROMANIA_DFS_H
