//
// Created by Rocco Wang on 16/4/6.
//

#include "uniform_cost.h"
#include <queue>

uniform_cost::uniform_cost(Graph *graph)
        : solution() {
    g = graph;
    title = "uniform_cost:";
    calc = &uniform_cost_calc;
}

uniform_cost::node::node(string _name, int _cost, string _parent) {
    name = _name;
    cost = _cost;
    parent = _parent;
}

void uniform_cost::uniform_cost_search(string from, string to) {
    cout << title << endl;
    priority_queue<node> heap;
    heap.push(node(from, 0, ""));
    node current = heap.top();
    string child = "", prev = "", next = "";
    while (!heap.empty()) {
        current = heap.top();
        solution.push_back(make_pair(current.name, current.parent));
        if (current.name == to)
            break;
        g->setVisited(current.name);
        heap.pop();
        child = g->getFirstUnvisited(current.name, "");
        while (!child.empty()) {
            heap.push(node(child, calc(current, child, g), current.name));
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
    cout << "Arad" << endl;
}

int uniform_cost::uniform_cost_calc(node current, string child, Graph *g) {
    return current.cost + g->getDis(current.name, child);
}