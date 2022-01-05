#include <stdio.h>
#include <math.h>

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
		printf("%0.2f x^%d",terms[start].coeff, terms[start].expon);
		if(start < end)
			printf(" + ");
		else
			printf("\n");
		
		start++;
	}
}


float evalPoly(polynomial terms[], int start, int end, float x) {
	float sum = 0;
	while(start <= end) {
		sum += terms[start].coeff * pow(x, terms[start].expon);
		start++;
	}
	
	return sum;
}


int main() {
	polynomial terms[MAX_TERMS];
	int start, end;
	float x, sum;

	printf("Enter a Polynomial : \n");
	getPoly(terms, &start, &end);
	
	printf(" You Entered: \n");
	printf("Polynomial A: ");
	printPoly( terms, start, end);
	
	printf("Enter an x to evaluate: ");
	scanf("%f",&x);
	
	sum = evalPoly(terms, start, end, x) ;
	
	printf("Polynomial Evaluated: %0.2f \n",sum);;
}







