#include<bits/stdc++.h>
using namespace std;
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
	bool visited[n]={0};
	queue<int> q;
	visited[0] = 1;
	q.push(0);
	while(!q.empty()){
		int temp = q.front();
		cout<<temp + 1<<" ";
		q.pop();
		for(int i=0;i<graph[temp].size();i++){
			if(!visited[graph[temp][i]]){
				q.push(graph[temp][i]);
				visited[graph[temp][i]] = 1;
			}
		}
	}
	cout<<endl;
	return 0;
}