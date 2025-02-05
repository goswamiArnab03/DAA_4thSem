#include<iostream>
#include<stdlib.h>
using namespace std;

void MaxMin(int arr[],int left,int right,int &maxval,int &minval){
	if(left==right){
		maxval=arr[left];
		minval=arr[left];
		return;
	}
	else if(left+1==right){
		if(arr[left]>arr[right]){
			maxval=arr[left];
			minval=arr[right];
		}
		else{
			maxval=arr[right];
			minval=arr[left];
		}
	}
	else{
		int mid=(left+right)/2;
		int lmax,lmin,rmax,rmin;
		MaxMin(arr,left,mid,lmax,lmin);
		MaxMin(arr,mid+1,right,rmax,rmin);
		maxval = (lmax > rmax) ? lmax : rmax;
		minval = (lmin < rmin) ? lmin : rmin;
	}
	
}

int main(){
	int n;
	cout<<"Enter the length";
	cin>>n;
	int arr[n];
	cout<<"Enter the array"<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int maxval,minval;
	MaxMin(arr,0,n-1,maxval,minval);
	cout<<"The maximum element is"<<maxval;
	cout<<"The minimum element is"<<minval;
	return 0;
}
