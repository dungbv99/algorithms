//
// Created by dung on 16/04/2021.
//

#include "bits/stdc++.h"
using namespace std;

class Graph{
    int V;
    vector<vector<int>> edges;
public:
    Graph(int v){
        this->V = v;
        edges.resize(v);
    }

    void addEdge(int u, int v){
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    void dfs(int u, vector<bool> &visited, vector<bool> &cutVertex, vector<int> & parent, int time, vector<int> &low, vector<int> &d){
        visited[u] = true;
        time++;
        d[u] = time;
        low[u] = time;
        int numChild = 0;

        for(int v = 0 ; v < edges[u].size(); v++){
            int e = edges[u][v];
            if(!visited[e]){
                numChild++;
                parent[e] = u;
                dfs(e,visited, cutVertex, parent, time, low, d);
                low[u] = min(low[u], low[e]);
                if(parent[u] == -1 && numChild > 1){
                    cutVertex[u] = true;
                }
                if (parent[u] != -1 && low[e] >= d[u]){
                    cutVertex[u] = true;
                }
            }else if(parent[u] != e){
                low[u] = min(low[u], d[e]);
            }
        }
    }
    void findCutVertex(){

        vector<bool> visited(this->V, false);
        vector<bool> cutVertex(this->V, false);
        vector<int> parent(this->V, -1);
        vector<int> low(this->V, 0);
        vector<int> d(this->V, 0);
        int time = 0;

        for(int u = 0; u < this->V; u++){
            if(!visited[u]){
                dfs(u, visited, cutVertex, parent, time, low, d);
            }
        }
        for(int i = 0; i < this->V; i++){
            if(cutVertex[i] == true){
                cout << i << " ";
            }
        }
        cout << "\n";
    }


};

int main(){
    cout << "Articulation points in first graph \n";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);

    g1.findCutVertex();

    cout << "\nArticulation points in second graph \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);

    g2.findCutVertex();


    cout << "\nArticulation points in third graph \n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);

    g3.findCutVertex();
}