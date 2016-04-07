//
// Created by Rocco Wang on 16/4/7.
//

#ifndef C_ROMANIA_A_SEARCH_H
#define C_ROMANIA_A_SEARCH_H


#include "uniform_cost.h"

//继承一致代价搜索
class A_search : public uniform_cost {
public:
    //在构造函数中重载calc函数指针,指向下面的计算函数
    A_search(Graph *graph, bool _DEBUG = false);

    //A*搜索的cost计算函数
    static int A_cost_calc(node current, string child, Graph *g);
};


#endif //C_ROMANIA_A_SEARCH_H
