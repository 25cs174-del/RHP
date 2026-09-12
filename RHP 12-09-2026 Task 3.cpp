#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long int
void solve(){
    int N,Q;
    cin>>N>>Q;
    vector<pair<int,int>> arr(Q);
    for(int i=0;i<Q;i++){
        int lt,rt;
        cin>>lt>>rt;
        arr[i]=make_pair(rt,lt);
    }
    sort(arr.begin(),arr.end());
    int count=0,last=-1;
    for(auto [rt,lt]:arr){
        if(last<lt){
            count++;
            last=rt-1;
        }
    }
    cout<<count<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc=1;
    while(tc--){
        solve();
    }
    return 0;
}