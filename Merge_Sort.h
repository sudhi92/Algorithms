/*This Algo is for merge sort*/
/*  PSEUDO CODE

Mergesort(A,p,r):
	q=(p+r)/2;
	if(p<q):
		Mergesort(A,p,q);
		Mergesort(A,q+1,r);
		Merge(A,p,q,r);
*/
#include <iostream>
using namespace std;
void merge(int *a, int p, int q, int r) {
	/*Create two arrays for flipping each*/
	int n1 = q - p + 1;
	int n2 = r - q;
	int *L1 = new int[n1];
	int *L2 = new int[n2];
	for (int i = 0; i < n1; i++)
		L1[i] = a[p + i];
	for (int i = 0; i < n2; i++)
		L2[i] = a[q + i + 1];

	int i = 0;
	int j = 0;
	int k = p;
	while (i < n1 && j < n2) {
		if (L1[i] < L2[j]) {
			a[k] = L1[i];
			k++;
			i++;
		}
		else {
			a[k] = L2[j];
			k++;
			j++;
		}
	}
	if (i >= n1)
	{
		while (j <n2)
		{
			a[k] = L2[j];
			k++;
			j++;
		}
	}
	if (j >= n2)
	{
		while (i <n1)
		{
			a[k] = L1[i];
			k++;
			i++;
		}
	}
}
void mergesort(int* a, int p, int r) {	
	if (p < r)
	{
		int q = (p + r) / 2;
		mergesort(a,p,q);
		mergesort(a, q + 1, r);
		merge(a, p, q, r);
	}
}


void Merge_Sort(int *a, int n) {
	mergesort(a, 0, n-1);
}

