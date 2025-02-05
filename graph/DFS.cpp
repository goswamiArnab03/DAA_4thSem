//This is DFS traversal
#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

class DFS{
	public:
		int graph[100][100];
		int visited[100];
		int n;
		
		void graph_input(){
			FILE* fp;
			fp=fopen("dfs.txt","r");
			if(!fp){
				cout<<"ERROR! Failed to open file"<<endl;
				exit(1);
			}
			fscanf(fp,"%d",&n);
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					fscanf(fp,"%d",&graph[i][j]);
				}
			}
			cout<<"The adjacency matrix is: "<<endl;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					cout<<graph[i][j]<<" ";
				}
				cout<<endl;
			}
			fclose(fp);
		}
		void define_visited(){
			for(int i=0;i<n;i++){
				visited[i]=0;
			}
		}
		void dfs(int st){
			stack<int> q;
			q.push(st);
			visited[st]=1;
			while(!q.empty()){
				int u=q.top();
				cout<<u<<" ";
				q.pop();
				for(int v=0;v<n;v++){
					if(graph[u][v]==1 && visited[v]==0){
						q.push(v);
						visited[v]=1;
					}
				}
			}
			
		}
		
};

int main(){
	DFS b;
	b.graph_input();
	b.define_visited();
	cout<<"Visited vertices: ";
	b.dfs(0);
	return 0;
}
