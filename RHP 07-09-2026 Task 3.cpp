#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve() {
    int N, M;
    cin >> N >> M;
    vector<long long> cnt(M + 1, 0);
    vector<long long> psum(M + 1, 0);
    for (int i = 1; i <= N; i++) {
        int curr;
        cin >> curr;
        cnt[curr]++;
    }
    for (int i = 1; i <= M; i++) {
        psum[i] = psum[i - 1] + cnt[i];
    }
    vector<long long> ans(M + 1, 0);
    for (int cut = 1; cut <= 18 && cut <= M; cut++) {
        long long maxc = 0;
        long long p = 1LL << cut;
        for (int x = 1; x <= M; x++) {
            long long currc = 0;
            for (long long mul = 1; mul * x <= M; mul++) {
                long long lt = mul * x;
                long long rt = lt + x - 1;
                if (rt > M)
                    rt = M;
                currc += min(mul, p - 1) *
                         (psum[rt] - psum[lt - 1]);
            }
            if (p * x <= M) {
                currc += cnt[p * x];
            }
            maxc = max(maxc, currc);
        }
        ans[cut] = maxc;
    }
    long long total = 0;
    for (int i = 1; i <= M; i++) {
        total += 1LL * i * cnt[i];
    }
    for (int cut = 19; cut <= M; cut++) {
        ans[cut] = total;
    }
    for (int i = 1; i <= M; i++) {
        cout << ans[i];
        if (i < M)
            cout << ' ';
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}