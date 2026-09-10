#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long int
void solve(){
	ll x,y,k,ans=0,ctr=0;
	cin>>x>>y>>k;
	while(ctr<k){
	    ll rem=(y+ctr)%(x+ctr);
	    if(rem==y-x) break;
	    ans+=rem;
	    ctr++;
	}
	if(k>ctr){
		ans+=(k-ctr)*(y-x);
	}
	cout<<ans<<endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin>>tc;
    while (tc--) {
        solve();
    }
    return 0;
}