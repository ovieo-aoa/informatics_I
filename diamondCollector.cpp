#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("diamond.in");
    ofstream fout("diamond.out");

    int N;
    long long K;
    if (!(fin >> N >> K)) return 0;

    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        fin >> A[i];
    }

    sort(A.begin(), A.end());

    vector<int> len(N);
    int j = 0;
    for (int i = 0; i < N; i++) {
        while (j < N && A[j] - A[i] <= K) {
            j++;
        }
        len[i] = j - i;
    }

    vector<int> max_after(N + 1, 0);
    for (int i = N - 1; i >= 0; i--) {
        max_after[i] = max(max_after[i + 1], len[i]);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, len[i] + max_after[i + len[i]]);
    }

    fout << ans << "\n";

    return 0;
}