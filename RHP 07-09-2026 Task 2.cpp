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
        int n, m;
        cin >> n >> m;
        vector<int> freq(m + 1);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            freq[x]++;
        }
        vector<int> suf(m + 2, 0);
        for (int i = m; i >= 1; i--) {
            suf[i] = suf[i + 1] + freq[i];
        }
        int ans = 0;
        for (int x = 1; x <= m; x++) {
            int cur = suf[x];
            if (2 * x <= m)
                cur += freq[2 * x];
            ans = max(ans, cur);
        }
        cout << ans << '\n';
    }
    return 0;
}