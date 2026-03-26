#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct OpPriority
{
	char c;
	int pri;
};

stack<OpPriority> op_stack;
string ans = "";

void pushAndPop(OpPriority opp) {
	if (op_stack.empty()) {
		op_stack.push(opp);
	}
	else {
		if (opp.pri >= op_stack.top().pri) {
			ans.push_back(opp.c);
		}
		else {
			ans.push_back(op_stack.top().c);
			op_stack.pop();
			pushAndPop(opp);
		}
	}
}

string postExpress(string eq) {

	for (char c : eq) {
		if (c == '(') {
			pushAndPop(c, 0);
		}
		else if (c == ')') {
			pushAndPop(c, 3);
		}
		else if (c == '*' || c == '/') {
			pushAndPop(c, 2);
		}
		else if (c == '+' || c == '-') {
			pushAndPop(c, 1);
		}
		else {
			ans.push_back(c);
		}
	}

	return ans;
}


int main() {

	string eq;
	cin >> eq;

	cout << postExpress(eq);

	
	

	return 0;
}