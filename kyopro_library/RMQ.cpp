#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    public:
    int dat[300000], siz = 1;

    void init(int N) {
        siz = 1;
        while(siz<N){
            siz *= 2; //2^kの形に
        }
        for(int i=1;i<siz*2;i++) dat[i] = 0;
    }

    void update(int pos, int x){
        pos = pos + siz - 1;
        dat[pos] = x;
        while(pos>=2){
            pos /= 2;
            dat[pos] = max(dat[2*pos], dat[2*pos+1]);
        }
    }

    int query(int l, int r, int a, int b, int u){
        if(r<=a || b<=l) return -101010101;
        if(l<=a && b<=r) return dat[u];
        int m = (a+b) / 2;
        int AnswerL = query(l, r, a, m, 2*u);
        int AnswerR = query(l, r, m, b, 2*u+1);
        return max(AnswerL, AnswerR);
    }
};


int main(){
    int N, Q;
    cin >> N >> Q;
    SegmentTree Z;
    Z.init(N);
    for(int i=0;i<Q;i++){
        int query;
        cin >> query;
        if(query==1){
            int pos, x;
            cin >> pos >> x;
            Z.update(pos, x);
        }else{
            int l, r;
            cin >> l >> r;
            int ans = Z.query(l, r, 1, Z.siz+1, 1); //開区間だからZ.siz+1
            cout << ans << endl;
        }
    }
    return 0;
}