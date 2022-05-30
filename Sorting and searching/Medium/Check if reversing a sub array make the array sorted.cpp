O(N*LOGN)

// C++ program to check whether reversing a
// sub array make the array sorted or not
#include<bits/stdc++.h>
using namespace std;

// Return true, if reversing the subarray will
// sort the array, else return false.
bool checkReverse(int arr[], int n)
{
	// Copying the array.
	int temp[n];
	for (int i = 0; i < n; i++)
		temp[i] = arr[i];

	// Sort the copied array.
	sort(temp, temp + n);

	// Finding the first mismatch.
	int front;
	for (front = 0; front < n; front++)
		if (temp[front] != arr[front])
			break;

	// Finding the last mismatch.
	int back;
	for (back = n - 1; back >= 0; back--)
		if (temp[back] != arr[back])
			break;

	// If whole array is sorted
	if (front >= back)
		return true;

	// Checking subarray is decreasing or not.
	do
	{
		front++;
		if (arr[front - 1] < arr[front])
			return false;
	} while (front != back);

	return true;
}

// Driven Program
int main()
{
	int arr[] = { 1, 2, 5, 4, 3 };
	int n = sizeof(arr)/sizeof(arr[0]);

	checkReverse(arr, n)? (cout << "Yes" << endl):
						(cout << "No" << endl);
	return 0;
}

// O(N)

// C++ program to check whether reversing a sub array
// make the array sorted or not
#include<bits/stdc++.h>
using namespace std;

// Return true, if reversing the subarray will sort t
// he array, else return false.
bool checkReverse(int arr[], int n)
{
	if (n == 1)
		return true;

	// Find first increasing part
	int i;
	for (i=1; i < n && arr[i-1] < arr[i]; i++);
	if (i == n)
		return true;

	// Find reversed part
	int j = i;
	while (j < n && arr[j] < arr[j-1])
	{
		if (i > 1 && arr[j] < arr[i-2])
			return false;
		j++;
	}

	if (j == n)
		return true;

	// Find last increasing part
	int k = j;

	// To handle cases like {1,2,3,4,20,9,16,17}
	if (arr[k] < arr[i-1])
	return false;

	while (k > 1 && k < n)
	{
		if (arr[k] < arr[k-1])
			return false;
		k++;
	}
	return true;
}

// Driven Program
int main()
{
	int arr[] = {1, 3, 4, 10, 9, 8};
	int n = sizeof(arr)/sizeof(arr[0]);
	checkReverse(arr, n)? cout << "Yes" : cout << "No";
	return 0;
}
