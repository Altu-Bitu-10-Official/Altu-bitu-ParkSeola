#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s;
    cin >> n >> s;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans = gcd(ans, abs(x - s));
    }

    cout << ans;
    return 0;
}