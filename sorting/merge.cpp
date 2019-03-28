#include<bits/stdc++.h>
using namespace std;
void merge(vector<int> &A,int low,int mid,int high){
	vector<int> ar(high - low + 1);
	int i=low,j=mid,k=0;
	while(i < mid || j < high){
		if(i == mid){
			for(;j<high;j++)
				ar[k++] = A[j];
			break;
		}else if(j == high){
			for(;i<mid;i++)
				ar[k++] = A[i];
			break;
		}else if(A[i] < A[j]){
			ar[k++] = A[i++];
		}else{
			ar[k++] = A[j++];
		}
	}
	for(i=0;i<k;i++)
		A[low+i] = ar[i];
}
void merge_sort(vector<int> &A,int low,int high){
	if(low < high-1){
		int mid = low + (high-low)/2;
		merge_sort(A,low,mid);
		merge_sort(A,mid,high);
		merge(A,low,mid,high);
	}
}
int main(){
	int n;
	printf("Enter the length of array\n");
	scanf("%d",&n);
	vector<int> A(n);
	printf("Enter the elements\n");
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	merge_sort(A,0,A.size());
	printf("sorted array : ");
	for(int i=0;i<n;i++)
		printf("%d ",A[i]);
	printf("\n");
	return 0;
}