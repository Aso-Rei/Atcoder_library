#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector<vector<pair<ll,ll>>> G(N);
    for(int i=0;i<N-1;i++){
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }

    vector<ll> dist(N, 0);
    //重みつきグラフ
    auto dfs = [&](auto self, pair<ll,ll> v, ll p) -> void {
        if(p!=-1) dist[v.first] += dist[p];
        dist[v.first] += v.second;

        for(const pair<ll,ll>& nv : G[v.first]){
            if(nv.first==p) continue;
            self(self, nv, v.first);
        }
    };
    //重みなしグラフ
    auto dfs = [&](auto self, int v, int p) -> void {
        if(p!=-1) dist[v] += dist[p];
        dist[v] += 1;
        for(auto nv : G[v]){
            if(nv==p) continue;
            self(self, nv, v);
        }
    };

    ll Q, K;
    cin >> Q >> K;
    K--;
    pair<ll,ll> start = {K,0LL};
    dfs(dfs, start, -1);

    for(int i=0;i<Q;i++){
        ll x, y;
        cin >> x >> y;
        x--; y--;
        cout << dist[x] + dist[y] << endl;
    }
    return 0;
}