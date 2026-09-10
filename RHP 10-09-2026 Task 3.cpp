#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long int
void solve(){
	int x,y;
	cin>>x>>y;
	int sum=x+y,rx=0,ry=0;
	for(int sh=30;sh>=0;sh--){
		if((sum&(1<<sh))!=0){
			if((rx|(1<<sh))<=x){
				rx=rx|(1<<sh);
			}else{
			    ry=ry|(1<<sh);
			}
		}
	}
	cout<<sum<<" "<<x-rx<<endl;
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