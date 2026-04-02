#include <iostream>
#include <vector>

using namespace std;

int findPrime(int n, int k) {
	int cnt = 0;
	vector<bool> is_prime(n + 1, true);

	for (int i = 2; i <= n; i++) {
		if (!is_prime[i]) {
			continue;
		}
		for (int j = i; j <= n; j += i) {
			if (!is_prime[j]) {
				continue;
			}
			is_prime[j] = false;

			if (++cnt == k) {
				return j;
			}

		}

	}

}

int main() {

	int n, k;
	cin >> n >> k;

	cout << findPrime(n, k);

	return 0;
}