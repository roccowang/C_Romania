//
// Created by Rocco Wang on 16/4/6.
//

#ifndef C_ROMANIA_UNIFORM_COST_H
#define C_ROMANIA_UNIFORM_COST_H


#include <iostream>
#include "Graph.h"
#include <deque>

using namespace std;

class uniform_cost {
protected:
    struct node {
        string name;
        int cost;
        string parent;

        node(string _name, int _cost, string _parent);

        //比较器,由于堆默认是大根堆,所以取反
        friend bool operator<(const node &a, const node &b) {
            return a.cost > b.cost;
        }
    };

    Graph *g;
    deque<pair<string, string>> solution;//0 为当前节点, 1 为父节点
    string title;
    int (*calc)(node, string, Graph*);


public:
    uniform_cost(Graph *graph);

    void uniform_cost_search(string from, string to);

    void output();

    static int uniform_cost_calc(node current, string child, Graph *g);
};


#endif //C_ROMANIA_UNIFORM_COST_H
