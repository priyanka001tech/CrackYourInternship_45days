#include <bits/stdc++.h>
using namespace std;

/* Function to print product array
for a given array arr[] of size n */

// USING PREFIX AND SUFFIX ARRAY...
//  TC O(N) 
//  SC O(N0

void productArray(int arr[], int n)
{

	// Base case
	if (n == 1) {
		cout << 0;
		return;
	}
	/* Allocate memory for temporary
arrays left[] and right[] */
	int* left = new int[sizeof(int) * n];
	int* right = new int[sizeof(int) * n];

	/* Allocate memory for the product array */
	int* prod = new int[sizeof(int) * n];

	int i, j;

	/* Left most element of left
array is always 1 */
	left[0] = 1;

	/* Right most element of right
array is always 1 */
	right[n - 1] = 1;

	/* Construct the left array */
	for (i = 1; i < n; i++)
		left[i] = arr[i - 1] * left[i - 1];

	/* Construct the right array */
	for (j = n - 2; j >= 0; j--)
		right[j] = arr[j + 1] * right[j + 1];
	for(int i=0;i<n;i++) cout << left[i] << " ";
  cout << endl;
  for(int i=0;i<n;i++) cout << right[i] << " ";
  cout << endl;
	/* Construct the product array using
		left[] and right[] */
	for (i = 0; i < n; i++)
		prod[i] = left[i] * right[i];

	/* print the constructed prod array */
	for (i = 0; i < n; i++)
		cout << prod[i] << " ";

	return;
}

/* Driver code*/
int main()
{
	int arr[] = { 10, 3, 5, 6, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "The product array is: \n";
	productArray(arr, n);
}

// O(N)
// SC O(1)
// C++ program for the above approach
#include <iostream>
using namespace std;

long* productExceptSelf(int a[], int n)
{
	long prod = 1;
	long flag = 0;

	// product of all elements
	for (int i = 0; i < n; i++) {

		// counting number of elements
		// which have value
		// 0
		if (a[i] == 0)
			flag++;
		else
			prod *= a[i];
	}

	// creating a new array of size n
	long* arr = new long[n];

	for (int i = 0; i < n; i++) {

		// if number of elements in
		// array with value 0
		// is more than 1 than each
		// value in new array
		// will be equal to 0
		if (flag > 1) {
			arr[i] = 0;
		}

		// if no element having value
		// 0 than we will
		// insert product/a[i] in new array
		else if (flag == 0)
			arr[i] = (prod / a[i]);

		// if 1 element of array having
		// value 0 than all
		// the elements except that index
		// value , will be
		// equal to 0
		else if (flag == 1 && a[i] != 0) {
			arr[i] = 0;
		}

		// if(flag == 1 && a[i] == 0)
		else
			arr[i] = prod;
	}
	return arr;
}

// Driver Code
int main()
{
	int n = 5;
	int array[] = { 10, 3, 5, 6, 2 };

	long* ans;
	ans = productExceptSelf(array, n);

	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	// cout<<"GFG!";
	return 0;
}

// This code is contributed by RohitOberoi.
