
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;

    vector<long long> prefix(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        prefix[i] = prefix[i - 1] + x;
    }

    deque<int> dq;
    long long ans = LLONG_MIN;

    for (int r = a; r <= n; r++) {

        int j = r - a;
        while (!dq.empty() &&
               prefix[dq.back()] >= prefix[j]) {
            dq.pop_back();
        }

        dq.push_back(j);

        while (!dq.empty() && dq.front() < r - b) {
            dq.pop_front();
        }

        ans = max(ans, prefix[r] - prefix[dq.front()]);
    }

    cout << ans << '\n';

    return 0;
}
