#include <iostream>
#include <stack>
#include <string>

using namespace std;

string judge_balance(string s) {
	stack<char> str;


	for (char c : s)
	{
		if (c == '(') {
			str.push(c);
		}
		else if (c == '[') {
			str.push(c);
		}
		else if (c == ')') {
			if (str.empty()) {
				return "no";
			}
			else if (str.top() == '(') {
				str.pop();
			}
			else {
				return "no";
			}
		}
		else if (c == ']') {
			if (str.empty()) {
				return "no";
			}
			else if (str.top() == '[') {
				str.pop();
			}
			else {
				return "no";
			}
		}
	}

	if (str.size() == 0)
	{
		return "yes";
	}
	else {
		return "no";
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s = "start";
	while (true)
	{
		cin.ignore();
		getline(cin, s, '.');
		if (s.length() == 0)
		{
			return 0;
		}
		cout << judge_balance(s) << "\n";
	}


	return 0;
}