#include <bits/stdc++.h>
using namespace std;

vector<bool> Eratosthenes(int N){
    vector<bool> isprime(N+1, true);

    isprime[0] = false;
    isprime[1] = false;
    for(int i=2;i*i<=N;i++){
        if(isprime[i]==false) continue;
        for(int j=2*i;j<=N;j+=i){
            isprime[j] = false;
        }
    }

    return isprime;
}

