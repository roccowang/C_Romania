//
// Created by Rocco Wang on 16/4/6.
//

#ifndef C_ROMANIA_GRAPH_H
#define C_ROMANIA_GRAPH_H

#include <unordered_map>
#include <iostream>

using namespace std;

#define MAX 20
#define INF 1000

typedef unordered_map<string, int> umap;

class Graph {
public:
    static umap Vertex;
    static int path[MAX][MAX];
    static int heu[MAX];
    static bool visited[MAX];
    static void init();

    int getDis(string a, string b);
};


#endif //C_ROMANIA_GRAPH_H
