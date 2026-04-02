#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

const int MAX = 5000000;

vector<int> getPrime() {
	vector<int> prime(MAX + 1, 0);

	for (int i = 2; i <= sqrt(MAX); i++) {
		if (prime[i] != 0) {
			continue;
		}

		for (int j = i * i; j <= MAX; j += i) {
			if (prime[j] == 0) {
				prime[j] = i;
			}
		}
	}

	return prime;
}

vector<int> getPrimeFactor(int k, vector<int>& prime) {
	vector<int> factors;

	while (prime[k] != 0) {
		factors.push_back(prime[k]);
		k /= prime[k];
	}

	factors.push_back(k);
	return factors;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n;

	vector<int> prime = getPrime();

	while (n--) {
		cin >> k;
		vector<int> factors = getPrimeFactor(k, prime);

		for (int factor : factors) {
			cout << factor << " ";
		}
		cout << "\n";

	}

	return 0;
}