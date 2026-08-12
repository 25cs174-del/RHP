#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
void solve(){
	int L,Q;
	cin>>L>>Q;
	set<int> s;
	s.insert(0);
	s.insert(L);
	while(Q--){
		int c,x;
		cin>>c>>x;
		if(c==1){
			s.insert(x);
		}
		else{
			auto it=s.upper_bound(x);
			cout<<*it-*(prev(it))<<endl;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc=1;
	while(tc--){
		solve();
	}
}