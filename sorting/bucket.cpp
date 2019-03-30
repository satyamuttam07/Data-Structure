#include<bits/stdc++.h>
#define M 1000000
using namespace std;
int main(){
	int n;
	printf("Enter the length of the array\n");
	scanf("%d",&n);
	vector<int> A(n);
	printf("Enter the elements\n");
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	vector<int> hash(M,0);
	for(int i=0;i<n;i++)
		hash[A[i]]++;
	int k = 0;
	printf("Sorted Array : ");
	for(int i=0;i<M;i++){
		while(hash[i] > 0){
			A[k++] = i;
			hash[i]--;
		}
	}
	for(int i=0;i<n;i++)
		printf("%d ",A[i]);
	printf("\n");
	return 0;
}