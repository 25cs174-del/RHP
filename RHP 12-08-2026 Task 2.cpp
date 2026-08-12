#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++){
    	int h,l;
    	cin>>h>>l;
    	arr[i]=make_pair(h,l);
    	}
    sort(arr.begin(),arr.end(),greater<>());
    int pre=0;
    vector<int> harr,larr;
    for(auto[h,l]:arr){
    	if(l>pre){
    		pre=l;
    		larr.push_back(l);
    		harr.push_back(h);
    	}
    }
    int q;
    cin>>q;
    while(q--){
    	int t;
    	cin>>t;
    	auto it=upper_bound(larr.begin(),larr.end(),t);
    	int idx=it-larr.begin();
    	cout<<harr[idx]<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}