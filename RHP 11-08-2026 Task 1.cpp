#include <iostream>
#include <string>
#include <algorithm> 
#include <queue>
#include <set>
#include <map>
using namespace std;

void solve() {
    int R;
    cin>>R;
    map<int,vector<pair<int,int>>>g;
    set<int>vis;
    while(R--){
        int src,des,dis;
        cin>>src>>des>>dis;
        g[src].push_back(make_pair(des,dis));
        g[des].push_back(make_pair(src,dis));
    }
    int st,end;
    cin>>st>>end;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push(make_pair(0,st));
    while(!pq.empty()){
        pair<int,int> top = pq.top();
        int currdis = top.first;
        int city = top.second;
        pq.pop();
        if(vis.count(city)==0){
            vis.insert(city);
            if(city==end){
                cout<<currdis;
                return;
            }
            for(int i=0;i<(int)g[city].size();i++){
                int oc = g[city][i].first;
                int ocd = g[city][i].second;
                if(vis.count(oc)==0){
                    pq.push(make_pair(currdis+ocd,oc));
                }
            }
        }
    }
    cout<<"city "<<end<<" cant be reached from "<<st;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc=1;
	while(tc--){
		solve();
	}
}