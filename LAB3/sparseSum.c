#include <stdio.h>
#include <stdlib.h>
 
void printTriple(int A[100][3]);
void getTriple(int triple[100][3]);
void addTriple( int A[100][3], int B[100][3] , int sum[100][3]);
 
int main(){
	int A[100][3], B[100][3], sum[100][3];
	printf("\nMATRIX A:\n");
	getTriple(A);
	printf("\nMATRIX B:\n");
	getTriple(B);
 
	printf("\nMatrix A:");
	printTriple(A);
	printf("\nMatrix B:");
	printTriple(B);
	addTriple(A, B, sum);
 
	printf("\nMatrix Sum:");
	printTriple(sum);
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
 
void getTriple(int triple[100][3]){
	printf("Enter No. of rows in actual matrix: ");
	scanf("%d",&triple[0][0]);
	printf("Enter No. of columns in actual matrix: ");
	scanf("%d",&triple[0][1]);
	printf("Enter No. of Non-Zero Elements in actual matrix: ");
	scanf("%d",&triple[0][2]);
 
	printf("Enter Triple Representation: \n");
	for( int i=1; i<=triple[0][2]; i++ ) {
		for(int j=0; j<3; j++){
			scanf("%d",&triple[i][j]);
		}
	}
}
 
void addTriple( int A[100][3], int B[100][3] , int sum[100][3]) {
 
	if(A[0][0] != B[0][0]  || A[0][1] != B[0][1]) {
		printf("Matrix Can't be added!\n");
		exit(0);
	}
	int aPoint=1, bPoint=1, sumPoint=1, numOfElem = 0, tempSum;
	sum[0][0] = A[0][0];
	sum[0][1] = A[0][1];
 
	while( (aPoint<=A[0][2]) && (bPoint<=B[0][2]) ) {
		//printf("\n apoint:%d \n",aPoint);
		//printf("\n bpoint:%d \n",bPoint);
		//printf("\n A[0][2]:%d \n",A[0][2]);
		//printf("\n B[0][2]:%d \n",B[0][2]);
		//printf("\n A[aPoint][0]:%d \n",A[aPoint][0]);
		//printf("\n B[bPoint][0]:%d \n",B[bPoint][0]);
 
		if( A[aPoint][0] == B[bPoint][0] ) // row  equal
		{
			if(A[aPoint][1] == B[bPoint][1]) // col equal
			{
				tempSum = A[aPoint][2] + B[bPoint][2];
				if(tempSum) {
					sum[sumPoint][0] = A[aPoint][0]; // store row num
					sum[sumPoint][1] = A[aPoint][1]; // store col num
					sum[sumPoint][2] = tempSum;          // store value ie, sum
					sumPoint++;
					numOfElem++;
				}
				aPoint++;
				bPoint++;
 
			}
			else if(A[aPoint][1] < B[bPoint][1]) // col of A less
			{
				sum[sumPoint][0] = A[aPoint][0]; // store row num
				sum[sumPoint][1] = A[aPoint][1]; // store col num
				sum[sumPoint][2] = A[aPoint][2]; // store value
				sumPoint++;
				aPoint++;
				numOfElem++;
			}
			else if(A[aPoint][1] > B[bPoint][1]) // col of A more
			{
				sum[sumPoint][0] = B[bPoint][0]; // store row num
				sum[sumPoint][1] = B[bPoint][1]; // store col num
				sum[sumPoint][2] = B[bPoint][2]; // store value
				sumPoint++;
				bPoint++;
				numOfElem++;
			}
 
		}
		else if(A[aPoint][0] < B[bPoint][0]) // row num of A less than B
		{
			//printf("[DEBUG] In A ROW LESS THEN B");
			sum[sumPoint][0] = A[aPoint][0]; // store row num
			sum[sumPoint][1] = A[aPoint][1]; // store col num
			sum[sumPoint][2] = A[aPoint][2]; // store value
			//printf("[DEBUG] sum[sumPoint][0]:%d\n",sum[sumPoint][0]);
			//printf("[DEBUG] sum[sumPoint][1]:%d\n",sum[sumPoint][1]);
			//printf("[DEBUG] sum[sumPoint][2]:%d\n",sum[sumPoint][2]);
			sumPoint++;
			aPoint++;
			numOfElem++;
		}
		else //if(A[aPoint][0] > B[bPoint][0]) // row num of A more than B
		{
 
			sum[sumPoint][0] = B[bPoint][0]; // store row num
			sum[sumPoint][1] = B[bPoint][1]; // store col num
			sum[sumPoint][2] = B[bPoint][2]; // store value
			sumPoint++;
			bPoint++;
			numOfElem++;
		}
	}
 
	//Either one of follwing while will excecute
	while( aPoint<=A[0][2])
	{
		sum[sumPoint][0] = A[aPoint][0]; // store row num
		sum[sumPoint][1] = A[aPoint][1]; // store col num
		sum[sumPoint][2] = A[aPoint][2]; // store value
		sumPoint++;
		aPoint++;
		numOfElem++;
 
	}
	while( bPoint<=B[0][2] )
	{
		sum[sumPoint][0] = B[bPoint][0]; // store row num
		sum[sumPoint][1] = B[bPoint][1]; // store col num
		sum[sumPoint][2] = B[bPoint][2]; // store value
		sumPoint++;
		bPoint++;
		numOfElem++;
	}
 
	sum[0][2] = numOfElem;
}
