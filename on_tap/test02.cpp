#include<iostream>
#include<math.h>
using namespace std;
bool binary_search(int *a, int n, int l, int h)
{
	if (l > h) return 0;
	int mid = (l + h) / 2;
	if (n == mid) return 1;
	else if (n > mid) return binary_search(a, n, mid + 1, h);
	else return binary_search(a, n, 0, mid);
}
int main()
{
	int m, n;
	cin >> m >> n;
	int* array = new int[m];
	for (int i = 0; i < m; ++i)
	{
		cin >> array[i];
	}

	int* ans = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> ans[i];
	}
	for (int i = 0; i < n; ++i)
	{
		if (binary_search(array, ans[i], 0, m)) cout << "YES" << " ";
		else cout << "NO" << " ";
	}

	delete[] array;
	delete[] ans;
	return 0;
}