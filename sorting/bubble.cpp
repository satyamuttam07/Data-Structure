#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	printf("Enter the number of elements in array\n");
	scanf("%d",&n);
	vector<int> A(n,0);
	printf("Enter the elements\n");
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if(A[j] > A[j+1]){
				int t = A[j];
				A[j] = A[j+1];
				A[j+1] = t;
			}
		}
	}
	printf("Sorted Array : ");
	for(int i=0;i<n;i++)
		printf("%d ",A[i]);
	printf("\n");
	return 0;
}