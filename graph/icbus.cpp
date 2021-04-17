//
// Created by dung on 11/04/2021.
//
/*
Country SS consists of N towns indexed from 1 to N, and each town i has its own inter city bus (IC Bus for short) system i.
 There is K roads between towns, each road connects two different towns.
 The bus can move freely in both directions on the road.

Quang is living in the town 1 in the country, and decided to go to the grandmother's house in the town N by some inter city buses.
 There are some special rules in this country:

-     If the passenger want to use the IC Bus of the town i, he has to only ride at the town i.
-     The bus fares of the IC Bus system i is Ci regardless of the distance that the passenger used.
-     The IC Bus system i allows to pass maximum Di towns per trip. If the trip has to pass more than Di towns, the passenger has to change to another IC Bus system.
-     The passenger will not be able ride to or down from the bus at a middle point different than the town.

 Your task is to to find the minimum value of the sum of the fare needed for Quang to reach the town N from the town 1.

Input
        The input consists of 1+N+K lines.

The first line contains two positive integers N and K (2≤N≤5000;N−1≤K≤10000).

i-th line in the N following lines contains 2 positive integers Ci and Di (1≤Ci≤10000;1≤Di≤N) which are the taxi fare and the maximum number of passing towns of the IC Bus system i.

Each line in the K following lines contains two positive integers i and j (1≤i<j≤N) which means these two towns has a direct road connecting them.

Output
        You should output on a single line an unique integer that is the minimum value of the sum of the fare necessary for Quang to go to the town N from the town 1.

*/


#include "bits/stdc++.h"
#define N 5001
using namespace std;
int C[N], D[N];
int n, k;
vector<vector<int>> edges(N);
int d[N][N];

void bfs(int source, int dist[]){
    for(int i = 1; i <= n; i++){
        dist[i] = INT_MAX;
    }
    queue<int> Q;
    Q.push(source);
    dist[source] = 0;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(auto v : edges[u]){
            if(dist[v] > dist[u]+1){
                dist[v] = dist[u]+1;
                Q.push(v);
            }
        }
    }
}

void caculateDistance(){
    for(int i = 1; i <=n; i++){
        bfs(i, d[i]);
    }
}

vector<int> ans(N, INT_MAX);
vector<bool> visited(N, false);

void Dijkstra(){
    //cho ans[1] = 0 de break khi = 2
    //vong while dau tien u = 2
    ans[1] = 0;
    int step  = n;
    while(step--){
        int u = 0;
        for(int i = 1; i <= n; i++){
            if(!visited[i] and ans[u] > ans[i]){
                u = i;
            }
        }
        if (u==0){
            break;
        }

        visited[u] = true;

        for(int i = 1; i <= n; i++){
            if(d[u][i] <= D[u]){
                ans[i] = min(ans[i], ans[u]+C[u]);
            }
        }


    }
    cout << ans[n];

}

int main(){
    cin >> n >> k;
    int a,b;
    for(int i = 1; i <= n; i++){
        cin >> a >> b;
        C[i] = a;
        D[i] = b;
    }
    for(int i = 0; i < k; i++){
        cin >> a >>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    caculateDistance();
    Dijkstra();
}