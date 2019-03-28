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
		int in = i;
		for(int j=i+1;j<n;j++){
			if(A[j] < A[in]){
				in = j;
			}
		}
		swap(A[i],A[in]);
	}
	printf("Sorted Array : ");
	for(int i=0;i<n;i++)
		printf("%d ",A[i]);
	printf("\n");
	return 0;
}