#include <iostream>
#include <vector>
#include <algorithm>
#include<map>
using namespace std;
#define ll long long int
void solve(){
	string s,t;
	cin>>s>>t;
	string dt=t+t;
	cout<<(dt.contains(s)?"Yes":"No")<<endl;
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