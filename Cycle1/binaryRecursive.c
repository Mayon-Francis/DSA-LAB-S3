#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100

void bubbleSort(int * , int );

int binSearch(int *, int , int , int, int);

int main() {

	int num[MAX_TERMS], N, key, index;
	printf("How many Numbers would you like to insert? (MAX %d): ",MAX_TERMS);
	scanf("%d",&N);
	
	if(N > MAX_TERMS) {
		printf("Too many terms!");
		exit(0);
	}
	
	printf("Enter Numbers: \n");
	for(int i=0; i<N; i++) {
		printf(">");
		scanf("%d",&num[i]);
	}
	
	printf("Enter the number you would like to search for: ");
	scanf("%d", &key);
	
	bubbleSort(num, N);
	
	printf("sorted array:");

	for(int i = 0; i<N; i++) {
		printf("\n > %d",num[i]);
	}
	fflush(stdin);
	
	index = binSearch(num, key, N, 0, N-1);
	
	if(index == -1) {
		printf("\nElement Not in the array! \n");
	}
	else {
		printf("\nElement found at position: %d \n",index + 1);
	}
	
}

void bubbleSort(int Arr[], int N) {
	int swapDone;
	
	for(int i=0; i<N-1; i++) {
		swapDone = 0;
		for(int j=0; j<N-1-i; j++) {
			if(Arr[j] > Arr[j+1]){
				int temp = Arr[j+1];
				Arr[j+1] = Arr[j];
				Arr[j]   = temp;
				swapDone = 1;
			}
		}
		if(swapDone == 0) {
			// there was no swap in the previous iteration, thus arr is already sorted
			break;
		}
	}
}




// requires sorted array
// returns -1 if not found
// returns index if element is found
int binSearch(int Arr[], int key, int N, int left, int right){
	int mid;
	mid = (left + right) / 2;
	
	if(Arr[mid] == key) {
		return mid;
	}
	else if(left == right) {
		return -1;
	}
	else if (Arr[mid] > key) {
		right = mid - 1;
	}
	else {
		left = mid +1;
	}
	
	return binSearch(Arr, key, N, left, right);
}







