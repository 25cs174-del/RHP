#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#define ll long long int
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    ll ans=0;
    for(int i=0;i<n-1;i++){
    	auto ub=upper_bound(arr.begin(),arr.end(),arr[i]);
    	int h=arr.end()-ub;
    	auto lb=lower_bound(arr.begin(),arr.end(),arr[i]);
    	int l=lb-arr.begin();
    	ans+=1LL*h*l;
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}