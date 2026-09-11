#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
using namespace std;
#define ll long long int
void gi(vector<int> &arr,int N){
	for(int i=0;i<N;i++) cin>>arr[i];
	sort(arr.begin(),arr.end());
}
void solve(){
	int N; cin >> N;
	vector<int> u(N),m(N),l(N);
	gi(u,N);gi(m,N);gi(l,N);
	vector<ll> pmid(N,0);
	for(int i=0;i<N;i++){
		auto it=upper_bound(l.begin(),l.end(),m[i]);
		if(it!=l.end()){
			pmid[i]=l.end()-it;
		}
	}
	for(int i=1;i<N;i++) pmid[i]+=pmid[i-1];
	ll ans=0;
	for(int i=0;i<N;i++){
		auto it=upper_bound(m.begin(),m.end(),u[i]);
		if(it!=m.end()){
			int midx=it-m.begin();
			ans+=pmid[N-1]-(midx==0?0:pmid[midx-1]);
		}
	}
	cout<<ans<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc=1;
    while (tc--) {
        solve();
    }
    return 0;
}