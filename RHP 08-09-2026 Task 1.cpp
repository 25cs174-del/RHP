#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;
#define ll long long int
void solve() {
    int n,k;
    cin >> n>>k;
    string s;
    cin>>s;
    int F=n/k;
    vector<bool> own(F,false);
    for (unsigned int i = 0; i < s.size(); i++) {
    	if(s[i]=='0'){
    		int farmidx=i/k;
    		own[farmidx]=true;
    	}
    }
    int count=0;
    for(int f=0;f<F;f++){
    	if(!own[f]){
    		count++;
    	}
    }
    cout<<count<<endl;
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