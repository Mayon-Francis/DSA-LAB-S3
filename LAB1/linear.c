#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100

int linSearch(int *, int , int );

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
	
	index = linSearch(num, key, N);
	
	if(index == -1) {
		printf("Element Not in the array! \n");
	}
	else {
		printf("Element found at position: %d \n",index + 1);
	}
	
}



// returns -1 if not found
// returns index if element is found
int linSearch(int Arr[], int key, int N){
	for (int i=0; i<N; i++) {
		if(Arr[i] == key) {
			return i;
		}
	}
	
	return -1;
}
