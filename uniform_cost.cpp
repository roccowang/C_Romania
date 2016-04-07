//
// Created by Rocco Wang on 16/4/6.
//

#include "uniform_cost.h"
#include <queue>

uniform_cost::uniform_cost(Graph *graph, bool _DEBUG)
        : solution() {
    g = graph;
    title = "uniform_cost:";
    calc = &uniform_cost_calc;
    DEBUG = _DEBUG;
}

uniform_cost::node::node(string _name, int _cost, string _parent) {
    name = _name;
    cost = _cost;
    parent = _parent;
}

void uniform_cost::uniform_cost_search(string from, string to) {
    cout << title << endl;
    priority_queue<node> heap;
    debug_output(from, calc(node("begin", 0, ""), from, g), "add");
    heap.push(node(from, calc(node("begin", 0, ""), from, g), ""));
    node current = heap.top();
    string child = "";
    while (!heap.empty()) {
        current = heap.top();
        debug_output(current.name, current.cost, "visit");
        solution.push_back(make_pair(current.name, current.parent));
        if (current.name == to)
            break;
        g->setVisited(current.name);
        heap.pop();
        child = g->getFirstUnvisited(current.name, "");
        while (!child.empty()) {
            heap.push(node(child, calc(current, child, g), current.name));
            debug_output(child, calc(current, child, g), "add");
            child = g->getFirstUnvisited(current.name, child);
        }
    }
}

void uniform_cost::output() {
    cout << get<0>(*(solution.end() - 1)) << "<-";
    string parent = get<1>(*(solution.end() - 1));
    for (deque<pair<string, string>>::iterator i = solution.end() - 1;
         !get<1>(*i).empty(); i--) {
        if (get<0>(*i) == parent) {
            cout << parent;
            parent = get<1>(*i);
            cout << "<-";
        }
    }
    cout << get<0>(*solution.begin()) << endl;
}

int uniform_cost::uniform_cost_calc(node current, string child, Graph *g) {
    if (current.name == "begin")
        return 0;
    return current.cost + g->getDis(current.name, child);
}

void uniform_cost::debug_output(string name, int cost, string type) {
    if (DEBUG) {
        if (type == "add") {
            cout << "node added to heap:";
        }
        else {
            cout << "node visited:";
        }
        cout << name << " cost:" << cost << endl;
    }
}

void uniform_cost::setDebug(bool _DEBUG) {
    DEBUG = _DEBUG;
}