#include<bits/stdc++.h>
using namespace std;

class Krushkal{
	public:
		int e,v;
		int parent[100];
		int mst[100][2];
		vector<vector<int> > edges;
		void input(){
			cout<<"Enter the no of vertex: ";
			cin>>v;
			cout<<"Enter the no of edges: ";
			cin>>e;
			cout<<"Start vertex,End vertex,weight: "<<endl;
			for(int i=0;i<e;i++){
				int u,v,w;
				cin>>u>>v>>w;
				edges.push_back({w,u,v});
			}
		}
		void makeset(int i){
			parent[i]=-1;
		}
		void simpleunion(int i,int j){
			parent[j]=i;
		}
		int find(int i) { 
        	if (parent[i] == -1) 
            	return i; 
  
        	return parent[i] = find(parent[i]); 
    	}
		void mstKrushkal(){
			sort(edges.begin(),edges.end());
			for(int i=0;i<e;i++){
				makeset(i);
			}
			int cost=0;
			cout<<"Added edges: ";
			for(auto e: edges){
				int u=find(e[1]);
				int v=find(e[2]);
				int w=e[0];
				if(u!=v){
					simpleunion(u,v);
					cost=cost+e[0];
					cout<<e[1]<<"---"<<e[2]<<"="<<w<<endl;
				}
			}
			cout<<"Minimum cost: "<<cost<<endl;
		}
};

int main(){
	Krushkal k;
	k.input();
	k.mstKrushkal();
	return 0;
}
