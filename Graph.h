//
// Created by Rocco Wang on 16/4/6.
//

#ifndef C_ROMANIA_GRAPH_H
#define C_ROMANIA_GRAPH_H

#include <unordered_map>
#include <iostream>

using namespace std;

#define MAX 20
#define INF 3000

typedef unordered_map<string, int> umap;

class Graph {
private:
    static umap Vertex2Seq;
    static string Seq2Vertex[MAX];
    static int path[MAX][MAX];
    static int heu[MAX];
    bool visited[MAX];

public:
    //静态变量初始化,从文件中读取
    static void init();

    //非静态变量初始化
    Graph();

    int getDis(string a, string b);

    void setVisited(int n);

    void setVisited(string n);

    //将所有节点设为未访问
    void setUnvisited();

    bool isVisited(int n);

    bool isVisited(string n);

    string getFirstUnvisited(string from, string child);

    //获取启发函数修正后的cost
    //直线距离
    int getHeu(string n);
};


#endif //C_ROMANIA_GRAPH_H
