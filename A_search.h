//
// Created by Rocco Wang on 16/4/7.
//

#ifndef C_ROMANIA_A_SEARCH_H
#define C_ROMANIA_A_SEARCH_H


#include "uniform_cost.h"

class A_search : public uniform_cost {
public:
    A_search(Graph *graph);
    static int A_cost_calc(node current, string child, Graph *g);
};


#endif //C_ROMANIA_A_SEARCH_H
