#include<bits/stdc++.h>
using namespace std;
#define M 100000
void counting(vector<int> &A, int n){
	vector<int> hash(M,0);
	vector<int> B(n);
	for(int i=0;i<n;i++){
		hash[A[i]]++;
		B[i] = A[i];
	}
	for(int i=1;i<M;i++){
		hash[i] = hash[i] + hash[i-1];
	}
	for(int i=0;i<n;i++){
		A[hash[B[i]]-1] = B[i];
		hash[B[i]]--;
	}
}
int main(){
	int n;
	printf("Enter the length of the array\n");
	scanf("%d",&n);
	vector<int> A(n);
	printf("Enter the elements of the array\n");
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	counting(A,n);
	printf("Sorted Arrray : ");
	for(int i=0;i<n;i++){
		printf("%d ",A[i]);
	}
	printf("\n");
	return 0;
}