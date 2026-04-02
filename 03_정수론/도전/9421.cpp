#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> getPrime(int n) {
	vector<bool> prime(n + 1, true);
	for (int i = 2; i < sqrt(n); i++)
	{
		if (prime[i] == false) {
			continue;
		}
		for (int j = i * i; j <= n; j += i) {
			if (prime[j] == true) {
				prime[j] = false;
			}
		}
	}
	return prime;
}

int getSum(int i) {

	int r;
	int sum = 0;
	while (true) {
		r = i % 10;
		i /= 10;
		sum += r * r;
		if (i == 0) {
			return sum;
		}

	}
}

vector<int> getPrimeRootSum(vector<bool> prime, int n) {
	int sum;
	vector<int> prime_root_sum;

	for (int i = 3; i <= n; i++)
	{
		if (!prime[i]) continue;
		sum = i;
		vector<bool>visited(1000, false);
		while (true)
		{
			sum = getSum(sum);
			if (sum == 1)
			{
				prime_root_sum.push_back(i);
				break;
			}
			if (visited[sum] == true) {
				break;
			}
			visited[sum] = true;
		}


	}

	return prime_root_sum;
}



int main() {
	int n;
	cin >> n;

	vector <bool> prime = getPrime(n);
	vector <int> prime_root_sum = getPrimeRootSum(prime, n);

	for (int i : prime_root_sum) {
		cout << i << '\n';
	}

	return 0;
}