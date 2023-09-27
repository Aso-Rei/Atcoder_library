#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const long long INF = 1LL << 60;

struct Edge {
    int to;
    long long w;
    Edge(int to, long long w) : to(to), w(w) { }
};

using Graph = vector<vector<Edge>>;
using P = pair<long long, int>;

template<class T> bool chmin(T& a, T b){
    if(a>b){
        a = b;
        return false;
    }else{
        return true;
    }
}

int main(){
    int n, m, s;
    cin >> n >> m >> s;

    Graph G(n);
    for(int i=0;i<m;i++){
        int a, b;
        long long w;
        cin >> a >> b >> w;
        a--; b--;
        G[a].push_back(Edge(b,w));
    }

    vector<long long> dist(n, INF);
    dist[s] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.push({dist[s], s});

    while(!que.empty()){
        auto [d, v] = que.top();
        que.pop();

        if(d>dist[v]) continue;

        for(auto e : G[v]){
            if(chmin(dist[e.to], dist[v]+e.w)){
                que.push({dist[e.to], e.to});
            }
        }
    }

    for(int v=0;v<n;v++){
        if(dist[v]<INF) cout << dist[v] << endl;
        else cout << "INF" << endl;
    }
    return 0;
}