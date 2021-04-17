//
// Created by dung on 17/04/2021.
//

#include "bits/stdc++.h"
using namespace std;

class Graph{
    int V;
    vector<vector<int>> edges;
public:
    Graph(int v){
        this->V = v;
        this->edges.resize(v);
    }

    void addEdge(int u, int v){
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    void dfs(int u, int time, vector<bool> &visited, vector<int> &d, vector<int> &low, vector<int> &parent){
        visited[u] = true;

        d[u] = low[u] = ++time;


        for(int i = 0; i < edges[u].size(); i++){
            int v = edges[u][i];
            if(!visited[v]){
                parent[v] = u;
                dfs(v, time, visited, d, low, parent);
                low[u] = min(low[u], low[v]);
                if(low[v] > d[u]){
                    cout << u << "-" << v << "\n";
                }
            }else if(parent[u] != v)
                low[u] = min(low[u], d[v]);
        }
    }

    void solution(){
        vector<int> parent(this->V, -1);
        vector<bool> visited(this->V, false);
        vector<int> d(this->V,0);
        vector<int> low(this->V, 0);

        int time = 0;
        for(int i = time; i < this->V; i++){
            if(!visited[i]){
                dfs(i,0, visited, d, low, parent);
            }
        }
        for(int i  = 0; i < this->V; i++){
            cout << low[i] << " ";
        }
        cout << "\n";
        for(int i  = 0; i < this->V; i++){
            cout << d[i] << " ";
        }
        cout << "\n";
    }




};

int main(){
//    cout << "\nBridges in first graph \n";
//    Graph g1(5);
//    g1.addEdge(1, 0);
//    g1.addEdge(0, 2);
//    g1.addEdge(2, 1);
//    g1.addEdge(0, 3);
//    g1.addEdge(3, 4);
//    g1.solution();
//
//
//    cout << "\nBridges in second graph \n";
//    Graph g2(4);
//    g2.addEdge(0, 1);
//    g2.addEdge(1, 2);
//    g2.addEdge(2, 3);
//    g2.solution();

    cout << "\nBridges in third graph \n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.solution();
}