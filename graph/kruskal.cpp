//
// Created by dung on 10/04/2021.
//

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> iPair;

struct DisjoinSets{
    int *parent, *num;
    int n;
    DisjoinSets(int n){
        this->n = n;
        parent = new int[n+1];
        num = new int[n+1];

        // init n disjoint set
        for(int i = 0; i <= n; i++){
            num[i] = 1;
            parent[i] = i;
        }
    }

    int Find(int u){
        while(u != parent[u]){
            u = parent[u];
        }
        return u;
    }

    void Union(int x, int y){
        int u = Find(x);
        int v = Find(y);
        if(num[u] > num[v]){
            parent[v] = u;
            num[u] += num[v];
        }else{
            parent[u] = v;
            num[v] += num[u];
        }
    }
};

class Graph{
public:
    int V, E;
    vector<pair<int, iPair>> edges; // value and edge

    Graph(int V, int E){
        this->E = E;
        this->V = V;
    }

    void addEdge(int u, int v, int weight){
        edges.push_back({weight,{u,v}});
    }

    int kruskalMST_DisjoinSet(){
        int mst_wt = 0;
        sort(edges.begin(), edges.end());

        DisjoinSets ds(V);

        vector<pair<int, iPair>>::iterator it;
        for(it = edges.begin(); it != edges.end(); it++){
            int u = it->second.first;
            int v = it->second.second;

            int set_u = ds.Find(u);
            int set_v = ds.Find(v);

            if (set_u != set_v){
                cout << "(" << u << ", " << v << "),";
                mst_wt += it->first;
                ds.Union(set_u, set_v);
            }


        }
        return mst_wt;
    }
};


int main(){
    int V = 9;
    int E = 14;
    Graph g(V,E);
    g.addEdge(0,1,4);
    g.addEdge(1,2,8);
    g.addEdge(2,3,7);
    g.addEdge(2,5,4);
    g.addEdge(3,5,14);
    g.addEdge(5,6,2);
    g.addEdge(6,8,6);
    g.addEdge(0,7,8);
    g.addEdge(1,7,11);
    g.addEdge(2,8,2);
    g.addEdge(3,4,9);
    g.addEdge(4,5,10);
    g.addEdge(6,7,1);
    g.addEdge(7,8,7);

    int mst_wt = g.kruskalMST_DisjoinSet();
    cout << "\n";
    cout << mst_wt;
    return 0;
}