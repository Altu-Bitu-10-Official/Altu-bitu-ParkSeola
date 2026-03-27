#include <iostream>
#include <stack>

using namespace std;



string plus_ab(stack<char> n1, stack<char> n2) {
	stack<char> ans;
	char zero = '0';
	int res;
	int round = 0;
	string result = "";

	while (not n1.empty() && not n2.empty())
	{
		res = n1.top() + n2.top() - zero * 2 + round;
		n1.pop();
		n2.pop();


		if (res >= 10) {
			round = 1;
			res -= 10;
			ans.push(res + zero);
		}
		else
		{
			round = 0;
			ans.push(res + zero);
		}

	}

	if (not n1.empty())
	{
		while (not n1.empty())
		{
			res = n1.top() - zero + round;
			n1.pop();


			if (res >= 10) {
				round = 1;
				res -= 10;
				ans.push(res + zero);
			}
			else
			{
				round = 0;
				ans.push(res + zero);
			}
		}

	}
	else if (not n2.empty())
	{
		while (not n2.empty())
		{
			res = n2.top() - zero + round;
			n2.pop();


			if (res >= 10) {
				round = 1;
				res -= 10;
				ans.push(res + zero);
			}
			else
			{
				round = 0;
				ans.push(res + zero);
			}
		}
	}

	if (round == 1)
	{
		result.push_back('1');
	}

	while (not ans.empty())
	{
		result.push_back(ans.top());
		ans.pop();
	}
	return result;
}

int main() {
	string num1, num2;
	cin >> num1 >> num2;

	stack<char> n1, n2;

	for (char c : num1) {
		n1.push(c);
	}
	for (char c : num2) {
		n2.push(c);
	}

	cout << plus_ab(n1, n2);

	return 0;
}