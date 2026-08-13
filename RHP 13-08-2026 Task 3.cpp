#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long int
using namespace std;
int find(vector<int>& ldr, int node) {
  if (ldr[node] != node) {
     ldr[node] = find(ldr, ldr[node]); 
     }
  return ldr[node];
  }
void join(vector<int>& ldr,int rt,int lt){
    ldr[find(ldr,rt)]=find(ldr,lt);
     }
void solve(){
	int N, E; 
	cin>>N>>E;
    vector<int> ldr(N+1);
    vector<pair<int,pair<int,int>>> edges;
    for(int node=0;node<=N;node++){
    	ldr[node]=node;
    }
    while(E--){
    	int a,b,cost;
    	cin>>a>>b>>cost;
    	if(cost<=0){
    		join(ldr,a,b);
    	}
    	else{
    		edges.push_back(make_pair(cost,make_pair(a,b)));
    	}
    }
    	ll rewards=0;
    	sort(edges.begin(),edges.end());
    	for(auto p:edges){
    		int cost=p.first;
    		int a=p.second.first,b=p.second.second;
    		if(find(ldr,a)!=find(ldr,b)){
    			join(ldr,a,b);
    		}else{
    		    rewards+=cost;	
    		}
    	}
    	cout<<rewards;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc=1;
	while(tc--){
		solve();
	}
}