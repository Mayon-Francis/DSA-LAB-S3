#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100

int linSearchRecur(int *, int , int , int);

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
	
	index = linSearchRecur(num, key, N, 0);
	
	if(index == -1) {
		printf("Element Not in the array! \n");
	}
	else {
		printf("Element found at position: %d \n",index + 1);
	}
	
}



// returns -1 if not found
// returns index if element is found
int linSearchRecur(int Arr[], int key, int N, int curr){
	// curr refers to the index being currently searched
	
	if(curr == N) {
		return -1;
	}
	else if(Arr[curr] == key) {
		return curr;
	}
	else
	{
		return linSearchRecur(Arr, key, N, curr+1);
	}
}
