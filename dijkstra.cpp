#include<bits/stdc++.h>
using namespace std;
// void display(vector<vector<pair<int,int> > > &graph,int n){
// 	for(int i=0;i<n;i++){
// 		cout<<i+1;
// 		for(int j=0;j<graph[i].size();j++){
// 			cout<<"->"<<graph[i][j].first+1<<"("<<graph[i][j].second<<")";
// 		}
// 		cout<<endl;
// 	}
// }
int main(){
	int n,e,s,d;
	cout<<"Enter the Number of Nodes in the Graph\n";
	cin>>n;
	vector<vector<pair<int,int> > > graph(n);
	cout<<"Enter the number of edges in the graph\n";
	cin>>e;
	cout<<"Enter the edges\n";
	for(int i=0;i<e;i++){
		int a,b,w;
		cin>>a>>b>>w;
		graph[a-1].push_back(make_pair(b-1,w));
		graph[b-1].push_back(make_pair(a-1,w));
	}
	cout<<"Enter the source Node\n";
	cin>>s;
	vector<int> dist(n);
	for(int i=0;i<n;i++)
		dist[i] = INT_MAX;
	priority_queue<pair<int,int> > pq;
	pq.push(make_pair(0,s-1));
	dist[s-1] = 0;
	while(!pq.empty()){
		pair<int,int> temp = pq.top();
		pq.pop();
		int first = - temp.first;
		int second = temp.second;
		// cout<<temp.first<<temp.second;
		for(int i=0;i<graph[second].size();i++){
			if(dist[graph[second][i].first] > first + graph[second][i].second){
				dist[graph[second][i].first] = first + graph[second][i].second;
				pq.push(make_pair(-dist[graph[second][i].first],graph[second][i].first));
			}
		}
	}
	// cout<<endl;
	for(int i=0;i<n;i++){
		cout<<"Distance form "<<s<<" to "<<i+1<<" : "<<dist[i]<<"\n";
	}
	// display(graph,n);
	return 0;
}