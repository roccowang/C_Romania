//
// Created by Rocco Wang on 16/4/6.
//

#include "DFS.h"

DFS::DFS(Graph *graph, bool _DEBUG)
        : solution() {
    g = graph;
    DEBUG = _DEBUG;
}

void DFS::DFS_nonRecursive(string start, string goal) {
    cout << "DFS_nonRecursive:" << endl;
    solution.push_back(start);
    debug_output(solution.back(), "visit");
    g->setVisited(start);
    string next, top;
    while (true) {
        top = solution.back();
        next = g->getFirstUnvisited(top, "");
        while (next.empty()) {
            debug_output(solution.back(), "withdraw");
            solution.pop_back();
            next = g->getFirstUnvisited(solution.back(), next);
        }
        solution.push_back(next);
        debug_output(solution.back(), "visit");
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

void DFS::debug_output(string name, string type) {
    if (DEBUG) {
        if (type == "visit") {
            cout << "node visited:" << name << endl;
        } else {
            cout << "deadend, withdraw from:" << name << endl;
        }
    }
}

void DFS::setDebug(bool _debug) {
    DEBUG = _debug;
}