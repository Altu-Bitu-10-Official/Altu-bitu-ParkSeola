#include <iostream>

using namespace std;

int getGcdIter(int a, int b) {
	while (b != 0) {
		a %= b;
		swap(a, b);
	}
	return a;

}



int main() {

	int a, b;
	cin >> a >> b;
	int gcd = getGcdIter(a, b);
	int lcm = a * b / gcd;

	cout << gcd << "\n" << lcm;


	return 0;
}