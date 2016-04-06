//
// Created by Rocco Wang on 16/4/6.
//

#include "DFS.h"

DFS::DFS(Graph *graph)
        : solution() {
    g = graph;
}

void DFS::DFS_nonRecursive(string start, string goal) {
    cout << "DFS_nonRecursive:" << endl;
    solution.push_back(start);
    g->setVisited(start);
    string next, top;
    while (true) {
        top = solution.back();
        next = g->getFirstUnvisited(top, "");
        while (next.empty()) {
            solution.pop_back();
            next = g->getFirstUnvisited(solution.back(), next);
        }
        solution.push_back(next);
        g->setVisited(next);
        if (next == goal)
            break;
    }
}

void DFS::output() {
    for (deque<string>::iterator i = solution.begin(); i != solution.end(); i++) {
        cout << *i;
        if (i + 1 != solution.end())
            cout << "->";
    }
    cout << endl;
}