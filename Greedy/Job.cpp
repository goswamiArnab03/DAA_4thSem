#include<bits/stdc++.h>
using namespace std;
#define MAX 100

class Job{
	public:
		int profit[MAX],deadline[MAX];
		void input(int n){
			cout<<"Enter profit of jobs one by one:"<<endl;;
			for(int i=0;i<n;i++){
				cin>>profit[i];
			}
			cout<<"Enter deadline of jobs one by one:"<<endl;;
			for(int i=0;i<n;i++){
				cin>>deadline[i];
			}
		}
		void bsort(int n){
			for(int i=0;i<n-1;i++){
				for(int j=0;j<n-i-1;j++){
					if(profit[j+1]>profit[j]){
						swap(profit[j+1],profit[j]);
						swap(deadline[j+1],deadline[j]);
					}
				}
			}
		}
		void jsd(int n){
			int x[n];
			bool slot[n];
			for(int i=0;i<n;i++){
				slot[i]=false;
				x[i]=-1;
			}
			bsort(n);
		
			for(int i=0;i<n;i++){
				for(int j=std :: min(deadline[i],n);j>=0;j--){
					if(slot[j]==false){
						slot[j]=true;
						x[j]=i;
						break;
					}
				}
			}
			cout<<"Solution vector: ";
			for(int i=0;i<n;i++){
				cout<<x[i]<<" ";
			}
			cout<<endl;
		}
};

int main(){
	Job j;
	int n;
	cout<<"Enter the no of items: ";
	cin>>n;
	j.input(n);
	j.jsd(n);
	return 0;
}
