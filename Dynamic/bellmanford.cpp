/* bellman-ford algo find sortest path from a source to any other edge containing no negative edge cycle*/

#include<bits/stdc++.h>
#include<vector>
using namespace std;

#define INF 9999

/*struct Edge{
	int source,destiny,weight;
};*/

class bellmanford{
	public:
		//struct Edge ed;
		vector<vector<int> > edges;
		int v,e;// v is no of vertex,e is npo of edges
		void input(){
			cout<<"Enter the no of vertex";
			cin>>v;
			cout<<endl;
			cout<<"Enter the no of edges";
			cin>>e;
			cout<<endl;
			cout<<"Enter edges as sequence: source destiny weight"<<endl;
			for(int i=0;i<e;i++){
				int s,d,w;
				edges.push_back({s,d,w});
			}
		}
		
		void BellmanFord(int src){
			int dist[v]={INF};
			dist[src]=0;
			for(int i=1;i<=v-1;i++){
				for(auto e: edges){
					int we=e[2];
					if((dist[e[0]]+we)<dist[e[1]]){
						dist[e[1]]=dist[e[0]]+we;
					}
				}
			}
			cout<<"Final path: ";
			for(int i=0;i<v;i++){
				cout<<dist[i];
			}
			cout<<endl;
			
		}
};

int main(){
	bellmanford bd;
	bd.input();
	bd.BellmanFord(0);
	return 0;
}
