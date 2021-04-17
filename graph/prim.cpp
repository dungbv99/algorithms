//
// Created by dung on 10/04/2021.
//
#include "bits/stdc++.h"
using namespace std;
# define INF 0x3f3f3f3f

typedef pair<int, int> iPair;

void addEdge(vector<pair<int,int>> adj[], int u, int v, int w){
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}

void primMST(vector<pair<int,int>> adj[], int V){
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    int src = 0;
    vector<int> key(V, INF);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);
    pq.push(make_pair(0,src));
    key[src] = 0;

    while (!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;
        for(auto x : adj[u]){
            int v = x.first;
            int w = x.second;
//            cout << v << "  " << inMST[v] << "\n";
            if (inMST[v] == false && key[v] > w){
                key[v] = w;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    for (int i = 1; i < V; ++i){
        cout << parent[i] << "-" << i << "\n";
    }
}

int main(){
    int V = 9;
    vector<iPair > adj[V];

    // making above shown graph
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);

    primMST(adj, V);

    return 0;
}