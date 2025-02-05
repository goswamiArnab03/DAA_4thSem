#include<bits/stdc++.h>
using namespace std;
#include<stdlib.h>
int *x;

bool canbeplaced(int k,int i){
	for(int j=0;j<k;j++){
		if(x[j]==i || abs(j-k)==abs(x[j]-i)){
			return false;
		}
	}
	return true;
}

void nQueen(int k,int n){
	for(int i=0;i<n;i++){
		if(canbeplaced(k,i)){
			x[k]=i;
			if(k==n-1){
				for(int j=0;j<n;j++){
					cout<<x[j]+1<<" ";
				}
				cout<<endl;
			}
			else{
				nQueen(k+1,n);
			}
		}	
	}
}

int main(){
	int n;
	cout<<"Enter the no of queens: ";
	cin>>n;
	x=(int *)malloc(n*sizeof(int));
	nQueen(0,n);
	return 0;
}
