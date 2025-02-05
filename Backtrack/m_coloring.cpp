#include<bits/stdc++.h>
using namespace std;

int x[100];
int m;
int n;
int graph[100][100];


void nextvalue(int k){
	do{
		x[k]=(x[k]+1)%(m+1);
		if(x[k]==0) return;
		int j;
		for(j=1;j<k;j++){
			if(graph[k][j]==1 && x[j]==x[k]) break;
		}
		if(j==k) return;
	}while(true);
}

void mcolor(int k){
	do{
		nextvalue(k);
		if(x[k]==0) return;
		if(k==n){
			for(int i=1;i<=n;i++){
				cout<<x[i]<<" ";
			}
			cout<<endl;
		}
		else{
			mcolor(k+1);
		}
	}while(true);
}

int main(){
	cout<<"Enter no of verteces & no of colors: ";
	cin>>n>>m;
	cout<<"Enter the adjacency matrix of the graph: "<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>graph[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		x[i]=0;
	}
	cout<<"Color array: "<<endl;
	mcolor(1);
	return 0;
}
