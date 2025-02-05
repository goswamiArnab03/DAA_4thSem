#include<bits/stdc++.h>
using namespace std;
#define INF 999
#define NIL -999
int w[100][100];
int n;
void graph_input(){
	FILE* fp;
	fp=fopen("dis.txt","r");
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
int dist[100];
bool sptset[100];
int pred[100];

int minindex(){
	int min=INF;
	int index=-1;
	for(int i=0;i<n;i++){
		if(sptset[i]==false && dist[i]<=min){
			min=dist[i];
			index=i;
		}
	}
	return index;
}

void diskatra(int st){ //v is start vertex
	for(int i=0;i<n;i++){
		dist[i]=INF;
		sptset[i]=false;
		pred[i]=NIL;
	}
	dist[st]=0;
	for(int i=0;i<n;i++){
		int u=minindex();
		sptset[u]=true;
		for(int v=0;v<n;v++){
			if(w[u][v]!=0 && w[u][v]!=INF){
				if(sptset[v]==false && (dist[u]+w[u][v]<dist[v])){
					dist[v]=dist[u]+w[u][v];
					pred[v]=u;
				}
			}
		}
	}
	cout<<"Distance vector is: ";
	for(int i=0;i<n;i++) cout<<dist[i]<<" ";
	cout<<endl;
	/*cout<<"Pred vector is: ";
	for(int i=0;i<n;i++) {
		if(pred[i]==NIL) cout<<"N ";
		else cout<<pred[i]<<" ";
	}
	cout<<endl;*/
}

void print_path(int v){
	if(pred[v]==NIL){
		cout<<"v";
		return;
	}
	print_path(pred[v]);
	cout<<"--> "<<v;
}

void print_all_path(int start){
	for(int i=0;i<n;i++){
		if(i!=start){
			if(dist[i]==INF){
				cout<<"No path from "<<start<<" to "<<i<<endl;
			}
			else{
				cout<<"Path from "<<start<<" to "<<i;
				print_path(i);
				cout<<"Cost: "<<dist[i]<<" "<<endl;
			}
		}
	}
}

int main(){
	graph_input();
	diskatra(0);
	print_all_path(0);
	return 0;
}
