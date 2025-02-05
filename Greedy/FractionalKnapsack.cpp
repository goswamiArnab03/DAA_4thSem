//fractional knapsack


#include<bits/stdc++.h>
using namespace std;
#define MAX 100
class FKnapsnack{
	public:
		int n,m; //n= no of items  and m=Knapsack capacity
		vector<int> profit;
		vector<int> weights;
		void input(){
			cout<<"Enter the no of items: ";
			cin>>n;
			cout<<"Enter the Knapsack capacity: ";
			cin>>m;
			cout<<"Enter profits one by one"<<endl;
			for(int i=0;i<n;i++){
				int p;
				cin>>p;
				profit.push_back(p);
			}
			cout<<"Enter corrosponding weights one by one"<<endl;
			for(int i=0;i<n;i++){
				int we;
				cin>>we;
				weights.push_back(we);
			}
		}
		
		void bubblesort(int n){
			for(int i=0;i<n;i++){
				for(int j=0;j<n-i-1;j++){
					if((profit[j]/weights[j])<(profit[j+1]/weights[j+1])){
						swap(profit[j],profit[j+1]);
						swap(weights[j],weights[j+1]);
					}
				}
			}
		}
		void fksack(){
			vector<double> x(n,0.0);
			bubblesort(n);
			double u=double(m);
			for(int i=0;i<n;i++){
				if(weights[i]>u){
					x[i]=u/weights[i];
					break;
				}
				x[i]=1.0;
				u=u-weights[i];
			}
			
			double sumo=0.0;
			
		
			for(int i=0;i<n;i++){
				sumo+=x[i]*profit[i];
			}
			cout<<"The total profit is: "<<sumo;
			
		}
};

int main(){
	FKnapsnack fk;
	fk.input();
	fk.fksack();
	return 0;
}
