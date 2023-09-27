#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge{
    int to;
    long long w;
    Edge(int to, long long w) : to(to), w(w) { };
};

void Dijkstra(vector<vector<Edge>>& G, int start, vector<int>& dist){
    priority_queue<pair<long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> que;
    dist[start] = 0;
    que.push({dist[start], start});
    
    while(!que.empty()){
        auto [d, v] = que.top();
        que.pop();

        if(dist[v]<d) continue;
        for(auto e : G[v]){
            if(dist[e.to]>dist[v]+e.w){
                dist[e.to] = dist[v]+e.w;
                que.push({dist[e.to], e.to});
            }
        }
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> G(n);
    int INF = 1 << 30;
    for(int i=0;i<m;i++){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back(Edge(b,c));
        G[b].push_back(Edge(a,c));
    }

    vector<int> dist_from1(n, INF);
    vector<int> dist_fromN(n, INF);
    Dijkstra(G, 0, dist_from1);
    Dijkstra(G, n-1, dist_fromN);

    for(int i=0;i<n;i++){
        cout << dist_from1[i] + dist_fromN[i] << endl;
    }
    return 0;
}