// This is DFS algorithm using recursion
#include<bits/stdc++.h>
#include<stdio.h>
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
		}
		void define_visited(){
			for(int i=0;i<n;i++){
				visited[i]=0;
			}
		}
		void dfs(int v){ // v is start vertex
			visited[v]=1;
			cout<<v<<" ";
			for(int w=0;w<n;w++){
				if(graph[v][w]==1 && visited[w]==0){
					dfs(w);
				}
			}
		}
		
};

int main(){
	DFS d;
	d.graph_input();
	d.define_visited();
	cout<<"Visited vertices: ";
	d.dfs(0);
	return 0;
}
