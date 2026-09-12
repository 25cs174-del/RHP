#include <iostream>
#include <vector>
#include <algorithm>
#include<map>
#include<numeric>
#include<iomanip>
using namespace std;
#define ll long long int
struct bus{
    ll lt,rt;
    double time;
    friend bool operator<(bus a,bus b){
        if(a.lt!=b.lt){
            return a.lt<b.lt;
        }
        return a.time<b.time;
    }
}buses[200000];
void solve(){
    ll B,P,L,bspeed,pspeed,pos;
    cin>>B>>P>>L>>bspeed>>pspeed;
    for(int i=0;i<B;i++){
        cin>>buses[i].lt>>buses[i].rt;
        buses[i].time=(double)(buses[i].rt-buses[i].lt)/(double)bspeed+(double)(L-buses[i].rt)/(double)pspeed;
    }
    sort(buses,buses+B);
    for(int i=1;i<B;i++){
        buses[i].time=min(buses[i].time,buses[i-1].time);
    }
    double ans;
    for(int ctr=1;ctr<=P;ctr++){
        cin>>pos;
        ans=(double)(L-pos)/(double)pspeed;
        int bl=0,br=B;
        while(bl<br){
            int mid=(bl+br)/2;
            if(buses[mid].lt<=pos){
                bl=mid+1;
            }
            else{
                br=mid;
            }
        }
        if(bl>0){
            ans=min(ans,buses[bl-1].time);
        }
        cout<<fixed<<setprecision(10)<<ans<<endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc=1;
    while(tc--){
        solve();
    }
    return 0;
}