#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int> > &graph, bool visited[],int n){
	visited[n] = 1;
	cout<<n+1<<" ";
	for(int i=0;i<graph[n].size();i++){
		if(!visited[graph[n][i]]){
			dfs(graph,visited,graph[n][i]);
		}
	}
}														// using recursion
int main(){
	int n,e;
	cout<<"Enter the Number of Nodes in the Graph\n";
	cin>>n;
	vector<vector<int> > graph(n);
	cout<<"Enter the number of edges in the graph\n";
	cin>>e;
	cout<<"Enter the edges\n";
	for(int i=0;i<e;i++){
		int a,b;
		cin>>a>>b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}
	for(int i=0;i<n;i++){
		cout<<i+1;
		for(int j=0;j<graph[i].size();j++){
			cout<<"->"<<graph[i][j]+1;
		}
		cout<<endl;
	}
	bool visited[n]={0};
	dfs(graph,visited,0);
	cout<<endl;
	bool v[n]={0};
	stack<int> st;
	st.push(0);
	v[0] = 1;
	while(!st.empty()){									// using stack
		int temp = st.top();
		st.pop();
		cout<<temp+1<<" ";
		for(int i=0;i<graph[temp].size();i++){
			if(!v[graph[temp][i]]){
				v[graph[temp][i]] = 1;
				st.push(graph[temp][i]);
			}
		}
	}
	cout<<endl;
	return 0;
}