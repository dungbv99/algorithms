//
// Created by dung on 11/04/2021.
//

#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef pair<int, int> iPair;

class Graph{
    int V;
    list<iPair> *adj;
public:
    Graph(int v);
    ~Graph(){
        delete []adj;
    }

    void addEdge(int u, int v, int weight);

    void Dijkstra(int s);

    void Dijkstra_PriorityQueue(int s);
};

Graph::Graph(int v) {
    this->V = v;
    adj = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int weight) {
    adj[u].push_back(make_pair(v,weight));
    adj[v].push_back(make_pair(u, weight));
}

void Graph::Dijkstra(int s) {
    vector<int> d(V, INF);
    vector<int> p(V,s);
    vector<bool> k(V,0);
    d[s] = 0;
    int count = 1;
//    int mindistance, i,j,u;
    int mindistance;
    int u = 0;
    while (count < V-1){

        mindistance = INF;
        for(int i = 1; i < V; i++){
            if(!k[i] && d[i] < mindistance){
                mindistance = d[i];
                u = i;
            }
        }
        k[u] = 1;

        for(auto it = adj[u].begin(); it != adj[u].end(); ++it ){
            int v = (*it).first;
            int weight =(*it).second;
            if (d[v] > d[u] + weight){
                d[v] = d[u] + weight;
                p[v] = u;
            }

        }
        count++;
    }


    cout <<  s << "\n";
    for(int i = 0; i < V; i++){
        if(i != s){
            cout << i << " \t \t " << d[i] << "\t\t\t";
            cout << i;
            int j = i;
            do{
                j = p[j];
                cout << " <- "<< j;
            } while ((j != s));
            cout << endl;
        }
    }
}



void Graph::Dijkstra_PriorityQueue(int s) {
    priority_queue<iPair, vector<iPair>, greater<iPair>> Q;
    vector<int> d(V,INF);
    vector<int> p(V,s);
    vector<bool> k(V,0);

    d[s] = 0;
    Q.push(make_pair(d[s],s));

    while(!Q.empty()){
        int  u = Q.top().second;
        int temp = Q.top().first;
        Q.pop();
        if(!k[u]){
            k[u] = true;
            for(auto i = adj[u].begin(); i != adj[u].end(); ++i){
                int v = (*i).first;
                int weight = (*i).second;
                if(d[v] > d[u] + weight){
                    d[v] = d[u] + weight;
                    Q.push(make_pair(d[v], v));
                    p[v] = u;
                }
            }
        }
    }
    cout <<  s << "\n";
    for(int i = 0; i < V; i++){
        if(i != s){
            cout << i << " \t \t " << d[i] << "\t\t\t";
            cout << i;
            int j = i;
            do{
                j = p[j];
                cout << " <- "<< j;
            } while ((j != s));
            cout << endl;
        }
    }
}

int main(){
    int V = 9;
    Graph g(V);
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

    cout << "dijkstra \n";
    g.Dijkstra(0);

    cout << "dijkstra priority queue\n";
    g.Dijkstra_PriorityQueue(0);
    return 0;
}