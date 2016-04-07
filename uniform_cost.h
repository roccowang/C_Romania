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
    //一致代价问题的解可以用一个队列来保存
    //0 为当前节点, 1 为父节点
    deque<pair<string, string>> solution;

    //用来表示用,A*搜索继承了一致代价搜索,可以通过修改title来辨认
    string title;

    //计算节点代价的函数指针,需要传入一个Graph指针,因为实现是static函数,不能调用局部变量
    //在派生类中可以重载此函数指针来实现A*搜索
    int (*calc)(node, string, Graph *);

    bool DEBUG;

public:
    uniform_cost(Graph *graph, bool _DEBUG = false);

    void uniform_cost_search(string from, string to);

    void output();

    static int uniform_cost_calc(node current, string child, Graph *g);

    void debug_output(string name, int cost, string type);

    void setDebug(bool _DEBUG = false);
};


#endif //C_ROMANIA_UNIFORM_COST_H
