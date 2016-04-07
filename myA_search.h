//
// Created by Rocco Wang on 16/4/7.
//

#ifndef C_ROMANIA_MYA_SEARCH_H
#define C_ROMANIA_MYA_SEARCH_H


#include "uniform_cost.h"

//与A_search类似
class myA_search : public uniform_cost {
public:
    myA_search(Graph *graph);

    static int myA_cost_calc(node current, string child, Graph *g);
};


#endif //C_ROMANIA_MYA_SEARCH_H
