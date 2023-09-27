#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for(auto& i : A){
        cin >> i;
    }

    vector<ll> s;
    vector<ll> ord(N+1, -1);
    ll c = 1; //しゅうき
    ll l = 0; //しゅうきに入るまでの長さ
    ll now = 1;
    while(ord[now]==-1){
        ord[now] = (ll)s.size();
        s.push_back(now);
        now = A[now-1];
    }
    c = (ll)s.size() - ord[now];
    l = ord[now];

    if(K<l){
        cout << s[K] << endl;
    }else{
        K -= l;
        K %= c;
        cout << s[l+K] << endl;
    }
    return 0;
}