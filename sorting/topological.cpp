#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,e;
	printf("Enter the number of nodes in the graph\n");
	scanf("%d",&n);
	printf("Enter the number of edges in the graph\n");
	scanf("%d",&e);
	printf("Enter the edges\n");
	vector<vector<int> > graph(n);
	for(int i=0;i<e;i++){
		int a,b;
		cin>>a>>b;
		graph[a].push_back(b);
	}
	vector<int> visited(n,0);
	stack<int> st;
	for(int i=0;i<n;i++){
		if(!visited[i]){
			visited[i]++;
			stack<int> temp;
			temp.push(i);
			while(!temp.empty()){
				int m = temp.top();
				int flag = 0;
				for(int j=0;j<graph[m].size();j++){
					if(!visited[graph[m][j]]){
						flag++;
						visited[graph[m][j]]++;
						temp.push(graph[m][j]);
					}
				}
				if(!flag){
					int t = temp.top();
					temp.pop();
					st.push(t);
				}
			}
		}
	}
	printf("Topoogical Sort : ");
	while(!st.empty()){
		printf("%d ",st.top());
		st.pop();
	}
	printf("\n");
	return 0;
}