#include <iostream>
#include <vector>
#include <algorithm>
#include<map>
using namespace std;
#define ll long long int
void solve(){
	int N,sum=0;
	cin>>N;
	int arr[N];
	for(int i=0;i<N;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	cout<<sum-N<<endl;
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