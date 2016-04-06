//
// Created by Rocco Wang on 16/4/6.
//

#include "Graph.h"
#include <fstream>

/*静态变量初始化*/
umap Graph::Vertex;
int Graph::path[MAX][MAX];
int Graph::heu[MAX];
bool Graph::visited[MAX];

/*
 * 初始化结点名称与序号的映射,启发函数,邻接表,访问记录
 */
void Graph::init() {
    ifstream heuin("/Users/Rocco/Documents/Workspace/C_Romania/Heuristic.txt");
    string tmpstring, tmpstring_b;
    int dis;
    for (int count = 0; count < MAX; count++) {
        heuin >> tmpstring >> heu[count];
        Vertex[tmpstring] = count;
        visited[count] = false;
    }
    heuin.close();

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (i == j)
                path[i][j] = 0;
            else
                path[i][j] = INF;
        }
    }

    ifstream pathin("/Users/Rocco/Documents/Workspace/C_Romania/Path.txt");
    while (!pathin.eof()) {
        pathin >> tmpstring >> tmpstring_b >> dis;
        path[Vertex[tmpstring]][Vertex[tmpstring_b]] = dis;
        path[Vertex[tmpstring_b]][Vertex[tmpstring]] = dis;
    }
    pathin.close();
}

int Graph::getDis(string a, string b) {
    return path[Vertex[a]][Vertex[b]];
}