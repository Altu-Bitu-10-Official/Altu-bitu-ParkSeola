#include <iostream>
#include <vector>
//#include <algorithm>

using namespace std;

vector<int> merged;

void merge(vector<int>& arr, int left, int mid, int right) {
	int pl = left, pr = mid + 1, idx = left;

	while (pl <= mid && pr <= right) {
		if (arr[pl] < arr[pr]) {
			merged[idx++] = arr[pl++];
		}
		else {
			merged[idx++] = arr[pr++];
		}
	}
	while (pl <= mid)
	{
		merged[idx++] = arr[pl++];
	}
	while (pr <= right)
	{
		merged[idx++] = arr[pr++];
	}

	for (int i = left; i <= right; i++)
	{
		arr[i] = merged[i];
	}
}

void mergeSort(vector<int>& arr, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

int main()
{
	int n;
	cin >> n;

	vector<int> arr(n);
	merged.assign(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	mergeSort(arr, 0, n - 1);
	//sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}

	return 0;
}