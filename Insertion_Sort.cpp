/*Code for insertion sort by Alla Sudhakar Reddy*/

#include <iostream>
#include <conio.h>
#include "Merge_Sort.h"
using namespace std;

int* insertion_sort(int *a, int n) {

	/*Function for insertion sort*/
	int temp = 0;
	for (int j = 1; j < n; j++) {
		for (int i = j; i > 0; i--) {
			temp = a[i];
			if (a[i] < a[i - 1])
			{
				a[i] = a[i - 1];
				a[i - 1] = temp;
			}
			else
				break;
		}
	}
	return a;
}

int main()
{
	/* Reading the size of array and array to be sorted*/
	int n;
	cout << "Enter the size of array\n";
	cin >> n;
	int * a;
	a = new int[n];
	cout << "Initialize the array";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	Merge_Sort(a, n);
	for (int i = 0; i < n; i++)
	{
		cout << a[i];
	}
	_getch();
	return 0;
}

