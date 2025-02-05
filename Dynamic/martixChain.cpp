#include<bits/stdc++.h>
using namespace std;
#define INF 99999999

int m[100][100]; //cost matrix
int s[100][100]; //split matrix

void pop(int i,int j){ // print optimal parentesis
	if(i==j){
		cout<<"A"<<i;
		return;
	}
	cout<<"(";
	pop(i,s[i][j]);
	pop(s[i][j]+1,j);
	cout<<")";
}

void matrix_chain(int p[],int n){
	for(int i=1;i<=n;i++) m[i][i]=0;
	for(int len=2;len<=n;len++){
		for(int i=1;i<=n-len+1;i++){
			int j=i+len-1;
			m[i][j]=INF;
			for(int k=i;k<j;k++){
				int cost=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(cost<m[i][j]){
					m[i][j]=cost;
					s[i][j]=k;
				}
			}
		}
	}
}

int main(){
	cout<<"Enter length of p-matrix: ";
	int n;cin>>n;
	int p[n];
	cout<<"Enter p matrix: ";
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			m[i][j]=0;
			s[i][j]=0;
		}
	}
	matrix_chain(p,n-1);
	cout<<"Parentesis: ";
	pop(1,n-1);
	cout<<endl;
	cout<<"optimal cost: "<<m[1][n-1]<<endl;
	cout<<"cost matrix: "<<endl;
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=n-1;j++){
			if(i<=j) cout<<m[i][j]<<" ";
			else cout<<"0 ";
		}
		cout<<endl;
	}
	cout<<"split matrix: "<<endl;
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=n-1;j++){
			if(i<=j) cout<<s[i][j]<<" ";
			else cout<<"0 ";
		}
		cout<<endl;
	}
	return 0;
}
