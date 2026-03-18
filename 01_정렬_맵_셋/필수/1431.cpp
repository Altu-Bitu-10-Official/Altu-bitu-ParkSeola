#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int onlyNumber(string sn) {
	int sum = 0;
	for (char c : sn) {
		if (isdigit(c)) {
			sum += c - '0';
		}
	}
	return sum;
}

bool comp(string sn1, string sn2) {
	if (sn1.length() != sn2.length()) {
		return sn1.length() < sn2.length();
	}

	int sum1, sum2;
	sum1 = onlyNumber(sn1);
	sum2 = onlyNumber(sn2);

	if (sum1 != sum2) {
		return sum1 < sum2;
	}

	for (int i = 0; i < sn1.length(); i++) {
		if (sn1[i] != sn2[i]) {
			return sn1[i] < sn2[i];
		}

	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	string input;
	vector<string> sn;

	cin >> n;
	sn.assign(n, "");

	for (int i = 0; i < n; i++) {
		cin >> input;
		sn[i] = input;
	}

	sort(sn.begin(), sn.end(), comp);

	for (int i = 0; i < n; i++) {
		cout << sn[i] << '\n';
	}

	return 0;
}