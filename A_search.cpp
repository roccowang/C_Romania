//
// Created by Rocco Wang on 16/4/7.
//

#include "A_search.h"
#include <queue>

A_search::A_search(Graph *graph, bool _DEBUG) : uniform_cost(graph) {
    title = "A_search:";
    calc = &A_cost_calc;
    DEBUG = _DEBUG;
}

//void A_search::uniform_cost_search(string from, string to) {
//    cout << "A* search:" << endl;
//    priority_queue<node> heap;
//    heap.push(node(from, g->getHeu(from), ""));
//    node current = heap.top();
//    string child = "", prev = "", next = "";
//    while (!heap.empty()) {
//        current = heap.top();
//        solution.push_back(make_pair(current.name, current.parent));
//        if (current.name == to)
//            break;
//        g->setVisited(current.name);
//        heap.pop();
//        child = g->getFirstUnvisited(current.name, "");
//        while (!child.empty()) {
//            heap.push(node(child, current.cost - g->getHeu(current.name) + g->getDis(current.name, child) + g->getHeu(child), current.name));
//            child = g->getFirstUnvisited(current.name, child);
//        }
//    }
//}

int A_search::A_cost_calc(node current, string child, Graph *g) {
    if (current.name == "begin")
        return g->getHeu(child);
    return current.cost - g->getHeu(current.name) + g->getDis(current.name, child) + g->getHeu(child);
}