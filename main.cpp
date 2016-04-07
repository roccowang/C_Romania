#include <iostream>
#include "Graph.h"
#include "DFS.h"
#include "uniform_cost.h"
#include "A_search.h"
#include "myA_search.h"

using namespace std;

int main() {
    Graph::init();
    string from = "Arad", to = "Bucharest";

    Graph graph;
    //构造函数的最后一个参数是是否开启调试模式,true时会输出结点情况,下同,默认为false,只输出结果
    //可通过setDebug(bool)方法来切换
    DFS dfsearch(&graph, true);
    dfsearch.DFS_nonRecursive(from, to);
    dfsearch.output();

    cout << endl << endl << endl << endl;

    graph.setUnvisited();
    uniform_cost ucost(&graph, true);
    ucost.uniform_cost_search(from, to);
    ucost.output();

    cout << endl << endl << endl << endl;

    graph.setUnvisited();
    A_search a_search(&graph, true);
    a_search.uniform_cost_search(from, to);
    a_search.output();

    cout << endl << endl << endl << endl;

    graph.setUnvisited();
    myA_search myASearch(&graph, true);
    myASearch.uniform_cost_search("Arad", "Hirsova");
    myASearch.output();
    return 0;
}