#include <stdio.h>

#define MAX_TERMS 100
int Avail = 0;

typedef struct {
	float coeff;
	int expon;
} polynomial;

void FlushStdIn(void){
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void attach( polynomial terms[], float coeff, int expon) {
	terms[Avail].coeff = coeff;
	terms[Avail].expon = expon;
	Avail++;
	
}

void getPoly( polynomial terms[], int* start, int * end) {
	float coeff;
	int expon;
	char ch;
	
	*start = Avail;
	
	printf("Enter Polynomial in decreasing order of exponents:\n");
	do {
		printf("Coeff:");
		scanf("%f",&coeff);
		printf("Expon:");
		scanf("%d",&expon);
		
		attach(terms, coeff, expon);
		
		printf("More? (y/n):");
		FlushStdIn();
		scanf("%c",&ch);
	}while(ch=='y' || ch=='Y');
	
	*end = Avail - 1;
}

void printPoly( polynomial terms[], int start, int end) {
	while(start <= end) {
		printf("%f x^%d",terms[start].coeff, terms[start].expon);
		if(start < end)
			printf(" + ");
		else
			printf("\n");
		
		start++;
	}
}

int compareExpo(int a, int b) {
	if(a<b)
		return -1;
	else if(a == b)
		return 0;
	else
		return 1;
}

void addPoly(polynomial terms[] ,int startA, int endA, int startB, int endB, int *startSum, int *endSum) {
	float coefficient;
	*startSum = Avail;
	
	while( startA<=endA  && startB <= endB ) {
		switch( compareExpo( terms[startA].expon, terms[startB].expon ) ) {
			case -1: // a < b
				attach( terms, terms[startB].coeff, terms[startB].expon );
				startB++;
				break;
			case 1:  // a > b
				attach( terms, terms[startA].coeff, terms[startA].expon );
				startA++;
				break;
			case 0: // a == b
				coefficient = terms[startA].coeff + terms[startB].coeff;
				if( coefficient ) {
					attach( terms, coefficient, terms[startA].expon);
				}
				startA++;
				startB++;
				break;
		}
	}
	
	//if either still remains
	for(; startA <= endA; startA++) {
		attach(terms, terms[startA].coeff, terms[startA].expon);
	}
	for(; startB <= endB; startB++) {
		attach(terms, terms[startB].coeff, terms[startB].expon);
	}
	
	*endSum = Avail - 1;
}

int main() {
	polynomial terms[MAX_TERMS];
	int startA, endA, startB, endB, startSum, endSum;

	printf("Enter Polynomial A: \n");
	getPoly(terms, &startA, &endA);
	
	printf("Enter Polynomial B: \n");
	getPoly(terms, &startB, &endB);
	
	printf(" You Entered: \n");
	printf("Polynomial A: ");
	printPoly( terms, startA, endA);
	printf("Polynomial B: ");
	printPoly( terms, startB, endB);
	
	addPoly(terms, startA, endA, startB, endB, &startSum, &endSum);
	
	printf("Polynomial Sum: ");
	printPoly( terms, startSum, endSum);
}







