/*Floyd Warshall Algorithm Algorithm:

1.Initialize the solution matrix same as the input graph matrix as a first step. 
2.Then update the solution matrix by considering all vertices as an intermediate vertex. 
3.The idea is to pick all vertices one by one and updates all shortest paths which include the picked vertex as an intermediate vertex in the shortest path. 
4.When we pick vertex number k as an intermediate vertex, we already have considered vertices {0, 1, 2, .. k-1} as intermediate vertices. 
6.For every pair (i, j) of the source and destination vertices respectively, there are two possible cases. 
7.k is not an intermediate vertex in shortest path from i to j. We keep the value of dist[i][j] as it is. 
8.k is an intermediate vertex in shortest path from i to j. We update the value of dist[i][j] as dist[i][k] + dist[k][j], if dist[i][j] > dist[i][k] + dist[k][j]

*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 100
#define INF 9999
#define NIL -9999
class FloyedWarshall{
	public:
	int weight[MAX][MAX];
	int dist[MAX][MAX];
	int pred[MAX][MAX];
	int v,e;
	void input(){
		cout<<"Enter the no of vertex: ";
		cin>>v;
		cout<<"Enter the weighted matrix of the given graph"<<endl;
		cout<<"-------------------Enter 9999 for INF--------------------------"<<endl;
		for(int i=0;i<v;i++){
			for(int j=0;j<v;j++){
				cin>>weight[i][j];
			}
		}
		
	}
	void floyed_warshall(){
		for(int i=0;i<v;i++){
			for(int j=0;j<v;j++){
				dist[i][j]=weight[i][j];
				if(weight[i][j]==0 || weight[i][j]==INF){
					pred[i][j]=NIL;
				}
				else{
					pred[i][j]=i;
				}
			}
		}
		for(int k=0;k<v;k++){
			for(int i=0;i<v;i++){
				for(int j=0;j<v;j++){
					if(dist[i][k]+dist[k][j]<dist[i][j]){
						dist[i][j]=dist[i][k]+dist[k][j];
						pred[i][j]=pred[k][j];
					}
				}
			}
		}
		cout<<"The distance matrix is: "<<endl;
		for(int i=0;i<v;i++){
			for(int j=0;j<v;j++){
				if(dist[i][j]==INF){
					cout<<"INF ";
				}
				else{
					cout<<dist[i][j]<<" ";
				}
				
			}
			cout<<endl;
		}
		cout<<"The predi. matrix is: "<<endl;
		for(int i=0;i<v;i++){
			for(int j=0;j<v;j++){
				if(pred[i][j]==NIL){
					cout<<"N ";
				}
				else{
					cout<<pred[i][j]<<" ";
				}
				
			}
			cout<<endl;
		}
	}
	void apsp(int i,int j){ // all pair of shortest path
		if(i==j){
			cout<<i;
			return;
		}
		else if(pred[i][j]==NIL){
			cout<<"No path exists"<<endl;
			return;
		}
		else{
			apsp(i,pred[i][j]);
			cout<<"-->"<<j;
		}
	}
};

int main(){
	FloyedWarshall f;
	f.input();
	f.floyed_warshall();
	int i,j;
	cout<<"Enter pair(source,designation) to see sortest path: ";
	cin>>i>>j;
	f.apsp(i,j);
	return 0;
	
}
