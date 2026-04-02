#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

const int MAX = 1000000;

vector<int> getPrime() {
	vector<int> primes(MAX + 1, 0);
	for (int i = 3; i < sqrt(MAX); i += 2)
	{
		if (primes[i] != 0) {
			continue;
		}
		for (int j = i * i; j <= MAX; j += i) {
			if (primes[j] == 0) {
				primes[j] = i;
			}
		}
	}
	return primes;
}

string findPrimesAdd(int input, const vector<int>& primes) {
	string s;
	for (int i = 3; i <= input; i += 2)
	{
		if (primes[i] != 0) {
			continue;
		}
		if (primes[input - i] == 0) {
			return to_string(input) + " = " + to_string(i) + " + " + to_string(input - i);
		}
	}
	return "Goldbach's conjecture is wrong.";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int input;

	vector<int> primes = getPrime();

	while (true)
	{
		cin >> input;
		if (input == 0) {
			break;
		}
		cout << findPrimesAdd(input, primes) << '\n';

	}


	return 0;
}