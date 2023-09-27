#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
 
struct UnionFind
{
    vector<int> par, siz;
 
    //初期化
    UnionFind(int n) : par(n, -1), siz(n, 1) {}
 
    //根を求める
    int root(int x){
        if(par[x]==-1) return x;
        else return par[x] = root(par[x]);
    }
 
    //xとyが同じグループに属するかどうか
    bool issame(int x, int y){
        return root(x)==root(y);
    }
 
    bool unite(int x, int y){
        x = root(x); y = root(y);
 
        //すでに同じグループの時は何もしない
        if(x==y) return false;
 
        // union by size
        if(siz[x] < siz[y]) swap(x,y);
 
        //yをxの子とする
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }
 
    //xを含むグループのサイズ
    int size(int x){
        return siz[root(x)];
    }
 
    //グループ分けしたmapを返す  キー：各グループの根, 値：各グループの配列
    map<int, vector<int>> all_group_members(){
        map<int, vector<int>> M;
        for(int i=0;i<(int)par.size();i++){
            M[root(i)].push_back(i);
        }
        return M;
    }
};

int main() {
    UnionFind uf(7); // {0}, {1}, {2}, {3}, {4}, {5}, {6}

    uf.unite(1, 2); // {0}, {1, 2}, {3}, {4}, {5}, {6}
    uf.unite(2, 3); // {0}, {1, 2, 3}, {4}, {5}, {6}
    uf.unite(5, 6); // {0}, {1, 2, 3}, {4}, {5, 6}
    cout << uf.issame(1, 3) << endl; // True
    cout << uf.issame(2, 5) << endl; // False

    uf.unite(1, 6); // {0}, {1, 2, 3, 5, 6}, {4}
    cout << uf.issame(2, 5) << endl; // True
}