#include<iostream>
#include<vector>
#define ll long long int
using namespace std;
void solve(){
  int n;
  cin>>n;
  vector<int> a(n+1);
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  int same=0,exch=0;
  for(int i=1;i<=n;i++){
    if(i==a[i]) same++;
    else if(i==a[a[i]]) exch++;
  }
  exch=exch/2;
  ll b=1LL*same*(same-1)/2;
  cout<<exch+b;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc=1;
  while(tc--){
    solve();
  }
}