#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k, s;
	int r = 0;
	char c;
	cin >> n >> k;

	vector<char> alpa(n, '?');

	for (int i = 0; i < k; i++)
	{
		cin >> s >> c;

		r = (r + s) % n;

		if (alpa[r] != '?' && alpa[r] != c) {
			cout << "!";
			return 0;
		}

		for (int j = 0; j < n; j++)
		{
			if (j != r && alpa[j] == c) {
				cout << "!";
				return 0;
			}
		}

		alpa[r] = c;

	}

	for (int i = 0; i < n; i++)
	{
		cout << alpa[(r - i + n) % n];
	}


	return 0;
}

