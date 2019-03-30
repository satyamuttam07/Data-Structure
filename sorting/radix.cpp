#include<bits/stdc++.h>
using namespace std;
void counting(vector<int> &A,int n ,int exp){
	vector<int> output(n,0);
	int count[10] = {0};
	for(int i=0;i<n;i++){
		count[(A[i]/exp)%10]++;
	}
	for(int i=1;i<10;i++){
		count[i] += count[i-1];
	}
	for(int i=0;i<n;i++){
		output[count[(A[i]/exp)%10] - 1] = A[i];
		count[A[-1]]--;
	}
	for(int i=0;i<n;i++){
		A[i] = output[i];
	}
}
int main(){
	int n;
	printf("Enter the length of array\n");
	scanf("%d",&n);
	vector<int> A(n);
	printf("Enter the elemets\n");
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	int m=0;
	for(int i=0;i<n;i++){
		if(A[i] > m)
			m = A[i];
	}
	int exp = 1;
	while(m){
		counting(A,n,exp);
		m = m/10;
		exp = exp*10;
	}
	printf("Sorted array : ");
	for(int i=0;i<n;i++){
		printf("%d ",A[i]);
	}
	printf("\n");
	return 0;
}