#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int n;
        cin >> n;
 
        vector<int> b(n);
        for (int i = 0; i < n; i++)
            cin >> b[i];
 
        vector<int> diff(n + 1, 0);
 
        for (int i = 0; i < n; i++) {
            if (b[i] > 0) {
                int l = max(0, i - b[i] + 1);
                int r = min(n, i + b[i]);
 
                diff[l]++;
                diff[r]--;
            }
        }
 
        vector<int> restricted(n);
        int cur = 0;
 
        for (int i = 0; i < n; i++) {
            cur += diff[i];
            restricted[i] = (cur > 0);
        }
 
        bool possible = true;
 
        for (int i = 0; i < n; i++) {
            if (b[i] >= 0) {
                bool ok = false;
 
                int left = i - b[i];
                int right = i + b[i];
 
                if (left >= 0 && !restricted[left])
                    ok = true;
 
                if (right < n && !restricted[right])
                    ok = true;
 
                if (!ok) {
                    possible = false;
                    break;
                }
            }
        }
 
        if (!possible) {
            cout << -1 << '\n';
        } else {
            for (int i = 0; i < n; i++) {
                cout << (!restricted[i]);
            }
            cout << '\n';
        }
    }
 
    return 0;
}