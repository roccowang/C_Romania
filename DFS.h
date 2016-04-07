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
    bool DEBUG;
public:
    DFS(Graph *graph, bool _DEBUG = false);

    //无递归DFS,主要利用了栈
    void DFS_nonRecursive(string start, string goal);

    void output();

    void debug_output(string name, string type);

    void setDebug(bool _debug = false);
};


#endif //C_ROMANIA_DFS_H
