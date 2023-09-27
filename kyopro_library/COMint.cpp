#include <bits/stdc++.h>
using namespace std;
// AtCoder の modint を使う
#include <atcoder/modint>
using mint = atcoder::modint1000000007;

const int MAX = 510000;
mint fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    const int MOD = mint::mod();
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i;
        inv[i] = MOD - inv[MOD%i] * (MOD / i);
        finv[i] = finv[i - 1] * inv[i];
    }
}

// 二項係数計算
mint COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * finv[k] * finv[n - k];
}

int main() {
    // 前処理
    COMinit();

    // 計算例
    cout << COM(100000, 50000).val() << endl;
    return 0;
}