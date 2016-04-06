//
// Created by Rocco Wang on 16/4/6.
//

#include "Graph.h"
#include <fstream>

/*静态变量初始化*/
umap Graph::Vertex2Seq;
int Graph::path[MAX][MAX];
int Graph::heu[MAX];
string Graph::Seq2Vertex[MAX];

Graph::Graph() {
    for (int i = 0; i < MAX; i++)
        visited[i] = false;
}

/*
 * 初始化结点名称与序号的映射,启发函数,邻接表,访问记录
 */
void Graph::init() {
    ifstream heuin("/Users/Rocco/Documents/Workspace/C_Romania/Heuristic.txt");
    string tmpstring, tmpstring_b;
    int dis;
    for (int count = 0; count < MAX; count++) {
        heuin >> tmpstring >> heu[count];
        Vertex2Seq[tmpstring] = count;
        Seq2Vertex[count] = tmpstring;
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
//    int count = 1;
    while (!pathin.eof()) {
        pathin >> tmpstring >> tmpstring_b >> dis;
//        cout << count << " " << tmpstring << " " << tmpstring_b << " " << dis << endl;
        path[Vertex2Seq[tmpstring]][Vertex2Seq[tmpstring_b]] = dis;
        path[Vertex2Seq[tmpstring_b]][Vertex2Seq[tmpstring]] = dis;
//        count++;
    }
    pathin.close();

    ofstream pathout("/Users/Rocco/Documents/Workspace/C_Romania/Pathout.txt");
    for (int i = 0; i < MAX; i++)
        pathout << i << "\t";
    pathout << endl;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (path[i][j] == INF)
                pathout << "\t";
            else
                pathout << path[i][j] << "\t";
        }
        pathout << endl;
    }
    pathout.close();
}

int Graph::getDis(string a, string b) {
    return path[Vertex2Seq[a]][Vertex2Seq[b]];
}

void Graph::setVisited(int n) {
    visited[n] = true;
}

void Graph::setVisited(string n) {
    visited[Vertex2Seq[n]] = true;
}

bool Graph::isVisited(int n) {
    return visited[n];
}

bool Graph::isVisited(string n) {
    return visited[Vertex2Seq[n]];
}

string Graph::getFirstUnvisited(string from, string child) {
    int i = Vertex2Seq[from];
    int start;
    if (!child.empty())
        start = 0;
    else
        start = Vertex2Seq[child];
    for (int j = start; j < MAX; j++) {
        if (path[i][j] < INF && path[i][j] != 0 && !visited[j]) {
            return Seq2Vertex[j];
        }
    }
    return "";
}