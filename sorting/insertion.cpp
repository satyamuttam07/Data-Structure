#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	printf("Enter the length of aray\n");
	scanf("%d",&n);
	vector<int> A(n,0);
	printf("Enter the elements\n");
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	for(int i=1;i<n;i++){
		int j = i;
		while(j>0){
			if(A[j]<A[j-1])
				swap(A[j],A[j-1]);
			else
				break;
			j--;
		}
	}
	printf("sorted Array : ");
	for(int i=0;i<n;i++)
		printf("%d ",A[i]);
	printf("\n");
	return 0;
}