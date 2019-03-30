#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int> &A, int h){

	for(int i=(h-1)/2;i>=0;i--){
		int left = i*2 + 1;
		int right = i*2 + 2;
		if(left <= h && A[left] > A[i]){
			swap(A[left],A[i]);
		}
		if(right <= h && A[right] > A[i]){
			swap(A[right], A[i]);
		}
	}
}
void heap_sort(vector<int> &A){
	int h = A.size() - 1;
	for(int i=0; i<A.size() - 1; i++){
		heapify(A,h);
		swap(A[h],A[0]);
		h--;
	}
}
int main(){
	int n;
	printf("Enter the length of aray\n");
	scanf("%d",&n);
	vector<int> A(n,0);
	printf("Enter the elements\n");
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	heap_sort(A);
	printf("sorted Array : ");
	for(int i=0;i<n;i++)
		printf("%d ",A[i]);
	printf("\n");
	return 0;
}