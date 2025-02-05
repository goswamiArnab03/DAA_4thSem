#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int low,int mid,int high){
	int i=low;
	int j=mid+1;
	int k=low;
	int b[1000];
	while(i<=mid && j<=high){
		if(arr[i]<=arr[j]) b[k++]=arr[i++];
		else b[k++]=arr[j++];
	}
	while(i<=mid) b[k++]=arr[i++];
	while(j<=high) b[k++]=arr[j++];
	for(int i=low;i<=high;i++){
		arr[i]=b[i];
	}
}

void msort(int arr[],int low,int high){
	if(low<high){
		int mid=(low+high)/2;
		msort(arr,low,mid);
		msort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}

int main(){
	int n;
	cout<<"Enter length: ";
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	cout<<"Sorted array: ";
	msort(arr,0,n-1);
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
	return 0;
}
