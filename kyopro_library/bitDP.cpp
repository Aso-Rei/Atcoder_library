"""
ABC180Eの回答コード
"""

#include <bits/stdc++.h>
using namespace std;

const int INF = 101010110;

void chmin(int& x, int y){
    x = min(x, y);
}

int main(){
    int N;
    cin >> N;
    vector<int> X(N), Y(N), Z(N);
    for(int i=0;i<N;i++){
        cin >> X[i] >> Y[i] >> Z[i];
    }
    int N2 = 1 << N;

    vector<vector<int>> dp(N2, vector<int>(N, INF));
    vector<vector<int>> dist(N, vector<int>(N));
    //dist[i][j]:i → jの距離
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int now = abs(X[i]-X[j]);
            now += abs(Y[i]-Y[j]);
            now += max(0, Z[j]-Z[i]);
            dist[i][j] = now;
        }
    }
    //初期化(i==0をスタート地点とする)
    for(int i=0;i<N;i++){
        if(i==0) continue;
        dp[1<<i][i] = dist[0][i];
    }
    //遷移
    //N2の昇順にやっていけば、依存関係は問題ない
    for(int i=0;i<N2;i++){
        for(int j=0;j<N;j++){
            //iのj桁目が１ではない（集合に含まれない）とき、continue
            if(~i>>j&1) continue;
            for(int k=0;k<N;k++){
                if(i>>k&1) continue;
                chmin(dp[i|1<<k][k], dp[i][j]+dist[j][k]);
            }
        }
    }

    cout << dp[N2-1][0] << endl;
    return 0;
}