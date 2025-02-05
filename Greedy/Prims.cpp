#include<bits/stdc++.h>
using namespace std;
#define INF 999

int w[100][100];
int n;

void graph_input(){
	FILE* fp;
	fp=fopen("prims.txt","r");
	if(!fp){
		cout<<"ERROR! Failed to open file"<<endl;
		exit(1);
	}
	fscanf(fp,"%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			fscanf(fp,"%d",&w[i][j]);
		}
	}

	fclose(fp);
}

int parent[100];
bool mstset[100];
int key[100];



int minindex(){
	int min=INF;
	int index=-1;
	for(int i=0;i<n;i++){
		if(mstset[i]==false && key[i]<min){
			min=key[i];
			index=i;
		}
	}
	return index;
}

void mstPrims(int v){ // v is start vertex
	for(int i=0;i<n;i++){
		parent[i]=-1;
		mstset[i]=false;
		key[i]=INF;
	}
	key[v]=0;
	for(int i=0;i<n;i++){
		int u=minindex();
		mstset[u]=true;
		for(int j=0;j<n;j++){
			if(w[u][j]!=0 && w[u][j]!=INF){
				if(mstset[j]==false && key[j]>w[u][j]){
					key[j]=w[u][j];
					parent[j]=u;
				}
			}
		}
	}
	int cost=0;
	cout<<"Edge\tweights"<<endl;
	for(int i=1;i<n;i++){
		cost+=key[i];
		cout<<parent[i]<<"----"<<i<<"\t"<<w[i][parent[i]]<<endl;
	}
	cout<<"Total cost is: "<<cost;
}

int main(){
	graph_input();
	mstPrims(0);
	return 0;
}
