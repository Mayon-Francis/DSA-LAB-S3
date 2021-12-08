#include <stdio.h>
 
void getMatrix(int A[100][100], int n, int m);
void printMatrix(int A[100][100], int n, int m);
void sparseToTriple(int A[100][100], int n, int m, int triple[100][3]);
void printTriple(int A[100][3]);
 
int main() {
	int sparseMatrix[100][100], n, m;
	int triple[100][3];
 
	printf("Enter No. of rows:");
	scanf("%d",&n);
	printf("Enter No. of columns:");
	scanf("%d",&m);
	getMatrix(sparseMatrix, n, m);
	printMatrix(sparseMatrix, n, m);
 
	sparseToTriple(sparseMatrix, n, m, triple);
	printTriple(triple);
	return 0;
}
 
void getMatrix(int A[100][100], int n, int m) {
	printf("\nEnter sparse matrix row-wise:\n");
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++) {
			printf("> ");
			scanf("%d",&A[i][j]);
		}
	}
}
void printMatrix(int A[100][100], int n, int m) {
	printf("Matrix:\n");
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++) {
			printf("%d\t",A[i][j]);
		}
		printf("\n");
	}
}
 
void printTriple(int A[100][3]) {
	printf("Triple:\n");
	printf("%d\t%d\t%d",A[0][0], A[0][1], A[0][2]);
	printf("\n-----------------\n");
	for(int i = 1; i<=A[0][2]; i++){
		for(int j = 0; j<3; j++) {
			printf("%d\t",A[i][j]);
		}
		printf("\n");
	}
}
void sparseToTriple(int A[100][100], int n, int m, int triple[100][3]) {
	triple[0][0] = n; // No. of rows
	triple[0][1] = m; // No. of columns
 
	int nextAvail = 1;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(A[i][j]!=0){
				triple[nextAvail][0] = i;
				triple[nextAvail][1] = j;
				triple[nextAvail][2] = A[i][j];
				nextAvail++;
			}
		}
	}
 
	triple[0][2] = nextAvail-1; // No. of elements
	float sparsity = (float)( m*n - (nextAvail-1))/(m*n);
	printf("\nSparsity = %0.2f\n",sparsity);
}
