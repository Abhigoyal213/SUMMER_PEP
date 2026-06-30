#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<long long> prefF(n + 1, 0), prefB(n + 2, 0);

 
    for (int i = 2; i <= n; i++) {
        prefF[i] = prefF[i - 1] + max(0LL, a[i - 1] - a[i]);
    }

   
    for (int i = n - 1; i >= 1; i--) {
        prefB[i] = prefB[i + 1] + max(0LL, a[i + 1] - a[i]);
    }

    while (m--) {
        int s, t;
        cin >> s >> t;

        if (s < t)
            cout << prefF[t] - prefF[s] << '\n';
        else
            cout << prefB[t] - prefB[s] << '\n';
    }

    return 0;
}