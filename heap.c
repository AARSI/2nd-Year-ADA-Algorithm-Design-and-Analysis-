#include <stdio.h>

void display(int arr[], int size);
void heapSort(int arr[], int size);
void minHeap(int arr[], int size);

int main() {
	//unsorted elements
	//we are saving elements from index 1
	//so, index 0 is set to -1
	int arr[] = {-1,4,60,10,2000,50,30,3,6};

	//size of the array
	int n = sizeof(arr)/sizeof(arr[0]);
	//printf("%d",n);
   // n--;
	//output unsorted elements
	display(arr, n);

	//sort the elements
	heapSort(arr, n);

	//display sorted elements
	display(arr, n);

	return 0;
}

void display(int arr[], int size) {
	int i;
	for(i = 0; i < size; i++)
    {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void heapSort(int arr[], int size) {
	//variables
	int i, j, tmp, sorted[size];
	sorted[0] = -1;	//index 0 is not used so set to -1

	//sort
	for(i = size , j = 1; i >= 1; i--, j++) {
		minHeap(arr, i);
		sorted[j] = arr[1];
		arr[1] = arr[i-1 ];	//put last element to root node
	}

	//set the result
	for(i = 0; i < size; i++) {
		arr[i] = sorted[i];
	}
}

void minHeap(int arr[], int size) {
	int i, left, right, tmp, val;

	for(i = (size-1) / 2; i >= 1; i--)
    {

		//taking 1 as the start index
		//if parent node = i
		//so left child = 2i
		//and right child = 2i+1
		tmp = i;
		left = (2 * i);
		right = (2 * i) + 1;

		if(left < size && arr[left] < arr[tmp])
        {
			tmp = left;
		}

		if(right < size && arr[right] < arr[tmp])
        {
			tmp = right;
		}

		if(tmp != i)
        {
			val = arr[i];
			arr[i] = arr[tmp];
			arr[tmp] = val;

			minHeap(arr, size);
		}
	}
}
