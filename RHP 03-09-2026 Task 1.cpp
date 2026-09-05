#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int n, k;
        cin >> n >> k;
 
        map<int, int> mp;
        set<int> empty;
 
        for (int i = 0; i <= 3 * n + 5; i++)
            empty.insert(i);
 
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            mp[x]++;
            empty.erase(x);
        }
 
        int ans = 0;
 
        for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
            int x = it->first;
            int cnt = it->second - 1;
 
            while (cnt >= k) {
                auto p = empty.lower_bound(x);
                ans = max(ans, *p - x);
                empty.erase(p);
                cnt--;
            }
 
            while (cnt > 0) {
                auto p = empty.lower_bound(x);
                empty.erase(p);
                cnt--;
            }
        }
 
        cout << ans << '\n';
    }
 
    return 0;
}