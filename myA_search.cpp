//
// Created by Rocco Wang on 16/4/7.
//

#include "myA_search.h"

myA_search::myA_search(Graph *graph) : uniform_cost(graph) {
    title = "myA_search";
    calc = &myA_cost_calc;
}

int myA_search::myA_cost_calc(node current, string child, Graph *g) {
    return current.cost - (g->getHeu(current.name) + 183) + g->getDis(current.name, child) + (g->getHeu(child) + 183);
}