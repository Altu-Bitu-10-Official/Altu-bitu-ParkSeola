#include <iostream>
#include <deque>

using namespace std;

int last_card(deque<int> dq) {
	int last = dq.back();
	while (dq.size() != 1) {
		dq.pop_front();
		dq.push_back(dq.front());
		dq.pop_front();
		last = dq.back();
	}

	return last;

}

int main() {
	int n, last;
	cin >> n;

	deque<int> dq;

	for (int i = 1; i <= n; i++)
	{
		dq.push_back(i);
	}

	last = last_card(dq);

	cout << last;


	return 0;
}