#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#define ll long long int
#define INF 269
using namespace std;
void solve(){
   string a,b;
   cin>>a>>b;
   int R=a.length(),C=b.length();
   vector<int> pa(R+1,0),pb(C+1,0);
   for(int i=1;i<=R;i++){
       pa[i]=(pa[i-1]+(a[i-1]-'0'))%10;
   }
   for(int i=1;i<=C;i++){
       pb[i]=(pb[i-1]+(b[i-1]-'0'))%10;
   }
   if(pa[R]!=pb[C]){
       cout<<"-1"<<endl;
       return;
   }
   vector<vector<int>> dp(R+1,vector<int>(C+1,0));
   for(int row=1;row<=R;row++){
       for(int col=1;col<=C;col++){
           if(pa[row]==pb[col]){
               dp[row][col]=1+dp[row-1][col-1];
           }
           else{
               dp[row][col]=max(dp[row-1][col],dp[row][col-1]);
           }
       }
   }
   cout<<dp[R][C]<<endl;
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   int tc=1;
   while(tc--){
       solve();
   }
}