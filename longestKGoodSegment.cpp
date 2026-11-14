#include <iostream>
#include <vector>

using namespace std;

const int MAXA = 1000000;
int freq[MAXA + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int l = 1;
    int distinct_count = 0;
    int max_len = 0;
    int best_l = 1, best_r = 1;

    for (int r = 1; r <= n; r++) {
        if (freq[a[r]] == 0) {
            distinct_count++;
        }
        freq[a[r]]++;

        while (distinct_count > k) {
            freq[a[l]]--;
            if (freq[a[l]] == 0) {
                distinct_count--;
            }
            l++;
        }

        if (r - l + 1 > max_len) {
            max_len = r - l + 1;
            best_l = l;
            best_r = r;
        }
    }

    cout << best_l << " " << best_r << "\n";

    return 0;
}