#include <stdio.h>

int* radixSort(int *, int);
int* hollerithSort(int *, int);
void countSort(int *, int, int);
void printArray(int *, int);

int main(){
	
	int *S1, *S2, m=0, n=10, i, x;
	int G[n], A[n];
	char c = '%';

	for(i=0; i<n; i++){
		scanf("%d", &x);
		G[i] = x;
	}

	S1 = radixSort(G, n);
	for(i=0; i<n; i++){
		A[i] =* (S1+i);
	}
	
	S2 = hollerithSort(G, n);
	for(i=0; i<n; i++){
		if(A[i] != *(S2+i))
			m++;
	}
	
	printArray(S1, n);
	printf("\n");
	printArray(S2, n);
	
	m *= 10;
	printf("\n%c%d hata", c, m);
	
	return 0;
	
}

int* radixSort(int *A, int n){
	
	int exp;
	for(exp = 1; 100 / exp > 0; exp *= 10)
		countSort(A, n, exp);
	
	return &A[0];

}

int* hollerithSort(int *A, int n){
	
	int exp;
	for(exp = 100; exp > 0 ; exp /= 10)
		countSort(A, n, exp);
	
	return &A[0];

}

void countSort(int *A, int n, int exp){
	
	int tmp[n];
	int i, count[10] = { 0 };

	for(i = 0; i < n; i++)
		count[(A[i] / exp) % 10]++;
		
	for(i = 1; i < 10; i++)
		count[i] += count[i - 1];
		
	for(i = n - 1; i >= 0; i--){
		tmp[count[(A[i] / exp) % 10] - 1] = A[i];
		count[(A[i] / exp) % 10]--;
	}
	
	for(i = 0; i < n; i++)
		A[i] = tmp[i];

}

void printArray(int *A, int n){
	
	int i;
	
	for (i = 0; i < n; i++)
		printf("%d ", A[i]);

}
