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
    static void init();

    Graph();

    int getDis(string a, string b);

    void setVisited(int n);

    void setVisited(string n);

    void setUnvisited();

    bool isVisited(int n);

    bool isVisited(string n);

    string getFirstUnvisited(string from, string child);

    int getHeu(string n);

    int myGetHeu(string n);
};


#endif //C_ROMANIA_GRAPH_H
