#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define ll long long int
void solve(){
    int N;
    string s;
    cin>>N>>s;
    const int K=3;
    const int INF=1e9;
    vector<vector<int>> dp(N+1,vector<int>(2*K+1,INF));
    dp[0][K]=0;
    for(int i=0;i<N;i++){
        int l,r;
        if(s[i]=='0'){
            l=K;
            r=K;
        }else if(s[i]=='-'){
            l=0;
            r=K-1;
        }else{
            l=K+1;
            r=2*K;
        }
        for(int j=0;j<=2*K;j++){
            if(dp[i][j]==INF)
                continue;
            for(int k=l;k<=r;k++){
                if(k==j)
                    continue;
                dp[i+1][k]=min(dp[i+1][k],
                               max(dp[i][j],abs(k-j)));
            }
        }
    }
    int ans=*min_element(dp[N].begin(),dp[N].end());
    if(ans==INF)
        ans=-1;
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}