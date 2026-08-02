#include<iostream>
#include<vector>
#define ll long long int
using namespace std;
void solve(){
  int N,M;
  cin>>N>>M;
  vector<int>psum(N+2,0);
  while(M--){
    int from,to;
    cin>>from>>to;
    psum[from]++;
    psum[to+1]--;
  }
  int minv=200003;
  for(int w=1;w<=N;w++){
    psum[w]+=psum[w-1];
    minv=min(minv,psum[w]);
  }
  cout<<minv<<endl;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc=1;
  while(tc--){
    solve();
  }
}