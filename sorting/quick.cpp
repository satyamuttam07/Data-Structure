#include<bits/stdc++.h>
using namespace std;
int partition(vector<int> &A,int low,int high){
	int left = low, right = high - 1, pivot = A[low];
	while(left < right){
		while(A[left] <= pivot)
			left++;
		while(A[right] > pivot)
			right--;
		if(left < right)
			swap(A[left],A[right]);
	}
	A[low] = A[right];
	A[right] = pivot;
	return right;
}
void quicksort(vector<int> &A,int low,int high){
	if(low < high - 1){
		int pivot = partition(A,low,high);
		quicksort(A,low,pivot);
		quicksort(A,pivot+1,high);
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
	quicksort(A,0,A.size());
	printf("sorted array : ");
	for(int i=0;i<n;i++)
		printf("%d ",A[i]);
	printf("\n");
	return 0;
}