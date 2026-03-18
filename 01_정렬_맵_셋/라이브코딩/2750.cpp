#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& arr) {
	int len = arr.size();

	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	bubbleSort(arr);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}

	return 0;
}