#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int shari[200000];
    int neta[200000];

    for (int i = 0; i < N; i++) {
        cin >> shari[i];
    }

    for (int i = 0; i < M; i++) {
        cin >> neta[i];
    }

    sort(shari, shari + N);
    sort(neta, neta + M);

    int i = 0, j = 0;
    int count = 0;

    while (i < N && j < M) {
        if (neta[j] <= 2 * shari[i]) {
            count++;
            i++;
            j++;
        } else {
            i++;
        }
    }

    cout << count;

    return 0;
}