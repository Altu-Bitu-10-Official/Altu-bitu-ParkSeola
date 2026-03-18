#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	string input, ins;
	set<string> ans;
	cin >> input;
	int len = input.length();

	for (int i = 0; i < len; i++) {
		for (int j = 1; j <= len - i; j++) {
			ans.insert(input.substr(i, j));
		}
	}

	cout << ans.size();


	return 0;
}