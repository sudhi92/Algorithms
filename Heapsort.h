/*Algorithm for heapsort */
/*Pseudocode
1. BUILD-MAX-HEAP(A)
2. for i <-- length[A] downto 2
	 do exchange A[i] <-> A[1]
		heapsize[A] <-> heapsoze[A] - 1
		MAX-HEAPIFY(A,1)
*/
int parent(int i){

	return (i - 1) / 2;
}

int left_child(int i) {

	return (2 * i + 1);
}
int right_child(int i) {

	return (2 * i + 2);
}

void heapify(int *a, int i,int n) {
	int l = left_child(i);
	int r = right_child(i);
	int largest = i;
	if (l < n)
		if (a[l] > a[i])
			largest = l;
	if (r < n)
		if (a[r] > a[largest])
			largest = r;
	if (largest != i) {
		int temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		heapify(a, largest, n);
	}
}


void build_max_heap(int* a, int n) {
	for (int i = (n / 2 - 1); i >= 0; i--)
		heapify(a, i, n);
}

void heapsort(int *a, int n) {
	build_max_heap(a, n);
	for (int i = n - 1; i >= 1; i--) {
		int temp = a[i];
		a[i] = a[0];
		a[0] = temp;
		n = n - 1;
		heapify(a, 0, n);
	}
}