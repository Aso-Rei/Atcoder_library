#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for(int i=0;i<N-1;i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> D(N, 0);
    auto dfs = [&](auto self, int v, int p) -> void{
        if(p!=-1) D[v] = D[p] + 1;
        for(auto nv : G[v]){
            if(nv==p) continue;
            self(self, nv, v);
        }
    };
    
    dfs(dfs, 0, -1);

    return 0;

}