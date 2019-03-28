#include<bits/stdc++.h>
using namespace std;
void createTree(int in[], int ar[],int l,int h,int pos){
	if(l == h){
		ar[pos] = in[l];
		return;
	} 
	int mid = (l + h)/2;
	createTree(in,ar,l,mid,2*pos+1);
	createTree(in,ar,mid+1,h,2*pos+2);
	ar[pos] = max(ar[2*pos+1] , ar[2*pos+2]);
}
int rangeQuery(int ar[], int qlow, int qhigh, int low, int high, int pos){
	if(qlow <= low && qhigh >= high)
		return ar[pos];
	if(qlow > high || qhigh < low)
		return 0;
	int mid = (high + low)/2;
	return max(rangeQuery(ar,qlow,qhigh,low,mid,2*pos+1), rangeQuery(ar,qlow,qhigh,mid+1,high,2*pos*2));
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int in[n];
		for(int i=0;i<n;i++)
			cin>>in[i];
		int m = ceil(log2(n));
		int size = 2*(pow(2,m)) - 1;
		int ar[size + 1]={0};
		createTree(in,ar,0,n-1,0);
		for(int i=0;i<size;i++)
			cout<<ar[i]<<" ";
		cout<<endl;
		int x;
		cin>>x;
		while(x--){
			int a,b;
			cin>>a>>b;
			cout<<"Result : "<<rangeQuery(ar,a,b,0,n-1,0)<<endl;
		}
	}
	return 0;
}