#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define SCANF(i) int i;scanf("%d",&i)
using namespace std;
using P = pair<int,int>;
const long long INF = 1LL << 60;
const int IINF=100000000;
const int MOD = (int)1e9 + 7;
typedef long long ll;
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
    int n;scanf("%d",&n);
    int cnt = -1;
    FOR(i,0,n+1){
        if(i*(i+1)==n*2){
            cnt = i;
        }
    }
    if(cnt==-1)cout << "No" << endl,exit(0);
    cout << "Yes" << endl;
    cout << cnt+1 << endl;
    vector<int> list(n,0);
    int index = 0;int pre = 0;
    REP(i,cnt+1){
        index = pre;
        printf("%d",cnt);
        int output = 0;
        while(output<cnt){
            if(list[index]<2){
                printf(" %d",index+1);
                list[index]++;
                output++;
            }
            index++;
            if(index>n-1)index=0;
        }
        cout << endl;
        pre=index==0?n-1:index-1;
    }

}