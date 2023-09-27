#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

vector<P> prime_factorize(ll N){
    vector<P> res;
    for(ll a=2;a*a<=N;a++){
        if(N%a!=0) continue;
        ll ex = 0; //指数
        while(N%a==0){
            ex++;
            N/=a;
        }
        res.push_back({a, ex});
    }

    if(N!=1) res.push_back({N,1});
    return res;
}