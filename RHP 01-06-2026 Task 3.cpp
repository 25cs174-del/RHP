#include<iostream>
using namespace std;
int main(){
    string s;
    cin >> s; 
    int l = s.length();
    for(int ctr = 1; ctr < (1<<l); ctr++){
        string comb = "";
        for(int sh = 0; sh < l; sh++){
            if(ctr&(1<<sh)){
                comb += s[sh];
            }
        }
        cout << comb << endl;
    }
}