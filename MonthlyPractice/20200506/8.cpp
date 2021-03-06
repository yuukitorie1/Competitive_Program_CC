#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define SCANF(i) int i;scanf("%d",&i)
typedef long long ll;
using namespace std;
using P = pair<int,int>;
const long long INF = 1LL << 60;
const int IINF=100000000;
const int MOD = (int)1e9 + 7;
//約数列挙
vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    //sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}
vector<int> dx={1,0,-1,0};vector<int> dy={0,-1,0,1};

signed main () {
    ll n;cin >> n;
    vector<vector<int>> paircnt(10,vector<int>(10,0));
    for(ll i=1;i<=n;i++){
        int keta = to_string(i).length();
        ll basenum=1;ll cnt=1;
        while(cnt<keta){
            basenum*=10;
            cnt++;
        }
        int first=(keta==1)?i:(i/basenum);int last=(keta==1)?i:(i%10);
        paircnt[first][last]++;
    }
    ll ans = 0;
    FOR(i,1,10)FOR(j,1,10){
        ans+=paircnt[i][j]*paircnt[j][i];
    }
    cout << ans << endl;
}//https://atcoder.jp/contests/abc152/tasks/abc152_d