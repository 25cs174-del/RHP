#include<iostream>
#include<vector>
#define ll long long int
using namespace std;
int find(vector<int>&ldr, int node) {
  if (ldr[node] != node) {
     ldr[node] = find(ldr, ldr[node]); 
     }
  return ldr[node];
  }
void join(vector<int>& ldr,int rt,int lt){
    ldr[find(ldr,rt)]=find(ldr,lt);
     }
void solve(){
	int N, E; cin>>N>>E;
    vector<int> ldr(N+1);
    for (int node = 1; node<=N; node++) {
    	ldr[node] = node;
    	}
    vector<int> edges(E);
    for (int node=0; node<E; node++) {
        int a,b;
        cin>>a>>b;
        edges[node] = a;
        join(ldr, a, b);
    }
    vector<int> gcnt(N+1, 0), ecnt(N+1, 0);
    for (int node=1; node<=N; node++) {
        gcnt[find(ldr, node)]++;
    }
    for (int a : edges) {
        ecnt[find(ldr, a)]++;
    }
    ll ans = 0;
    for (int node = 1; node<=N; node++) {
        ll curr = (1LL*gcnt[node]*(gcnt[node]-1))/2 - ecnt[node];
        ans += curr;
    }
    cout<<ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc=1;
	while(tc--){
		solve();
	}
}