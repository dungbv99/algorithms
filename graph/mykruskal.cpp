//
// Created by dung on 10/04/2021.
//

#include "bits/stdc++.h";

using namespace std;

struct DisjointSet{
    int *parent, *num;
    int n;
    DisjointSet(int n){
        parent = new int[n+1];
        num = new int[n+1];
        //init disjoint sets
        for(int i = 0; i <=n ; i++){
            num[i] = 1;
            parent[i] = i;
        }
    }

    int Find(int u){
        while (u != parent[u]){
            u = parent[u];
        }
        return u;
    }

    void Union(int u, int v){
        int p_u = Find(u);
        int p_v = Find(v);
        if (num[p_u] < num[p_v]){
            parent[p_u] = p_v;
            num[p_v] += num[p_u];
        }else{
            parent[p_v] = p_u;
            num[p_u] += num[p_v];
        }
    }
};



class Graph{
public:
    int V, E;
    vector<pair<int, pair<int,int>>> edges;
    Graph(int v, int e){
        this->V = v;
        this->E = e;


    }

    void addEdge(int u, int v, int weight){
        edges.push_back({weight,{u,v}});
    }

    int solution(){
        int krus_min = 0;
        sort(edges.begin(), edges.end());

        DisjointSet ds(this->E);
        for(auto it = edges.begin(); it != edges.end(); it++){
            int u = it->second.first;
            int v = it->second.second;

            int pu = ds.Find(u);
            int pv = ds.Find(v);

            if (pu != pv){
                krus_min += it->first;
                ds.Union(pu, pv);
            }
        }
        return krus_min;
    }

}

int main(){
    return 1;
}