#include <bits/stdc++.h>
using namespace std;
using ll = long long;

"""
Atcoder Beginner Contest170 Eの問題です
"""
int main(){
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N), B(N);
    vector<multiset<ll>> S(200005);
    multiset<ll> maxS;

    auto getMax = [&](ll i){
        if(S[i].size()==0) return -1LL;
        else return *S[i].rbegin();
    };
    //maxSの集合に幼稚園iを追加
    auto addYochien = [&](ll i){
        ll x = getMax(i);
        if(x==-1) return;
        maxS.insert(x);
    };
    //maxSの集合から幼稚園iを削除
    auto delYochien = [&](ll i){
        ll x = getMax(i);
        if(x==-1) return;
        maxS.erase(maxS.find(x));
    };

    auto addEnji = [&](ll i, ll x) {
        delYochien(i);
        S[i].insert(x);
        addYochien(i);
    };

    auto delEnji = [&](ll i, ll x) {
        delYochien(i);
        S[i].erase(S[i].find(x));
        addYochien(i);
    };
    
    for(ll i=0;i<N;i++){
        cin >> A[i] >> B[i];
        addEnji(B[i], A[i]);
    }

    for(ll i=0;i<Q;i++){
        ll C, D;
        cin >> C >> D;
        --C;
        delEnji(B[C], A[C]);
        B[C] = D;
        addEnji(B[C], A[C]);
        ll ans = *maxS.begin();
        printf("%d\n", ans);
    }

    return 0;
}