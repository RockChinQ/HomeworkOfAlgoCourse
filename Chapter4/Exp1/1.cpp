#include<iostream>
 
using namespace std;

// 非递归实现折半查找
int binary_search(int arr[], int key, int n) 
{
	int low = 0, high = n - 1;

	while (low <= high) 
	{
		int mid = (low + high) / 2;
		if (arr[mid] == key) 
			return mid;
		else if (arr[mid] < key) 
			low = mid + 1;
		else 
			high = mid - 1;
	}
	return -1;
}

// 递归实现折半查找
int binary_search_recur(int arr[], int low, int high, int key)
{
	if (low <= high) 
	{
		int mid = (low + high) / 2;
		if (arr[mid] == key) 
			return mid;
		else if (arr[mid] < key)
			return binary_search_recur(arr, mid + 1, high, key);
		else 
			return binary_search_recur(arr, low, mid - 1, key);
	}
	return -1;
}

int main() 
{
	int n, m;
	cin >> n >> m;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	// 递归折半查找
	int result_2 = binary_search_recur(arr, 0, n - 1, m);
	cout << (result_2==-1?-1:result_2+1) << endl;
 
	return 0;
}