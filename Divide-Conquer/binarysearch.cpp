#include<bits/stdc++.h>
using namespace std;

int binarysearch(int arr[],int low,int high,int key){
	if(high>=low){
		int mid=(low+high)/2;
		if(arr[mid]==key) return mid;
		else if(arr[mid]<key) return binarysearch(arr,mid+1,high,key);
		else return binarysearch(arr,low,mid-1,key);
	}
	return -1;
}

int main(){
	int n;
	cout<<"Enter length: ";
	cin>>n;
	int arr[n];
	cout<<"Enter sorted array: ";
	for(int i=0;i<n;i++) cin>>arr[i];
	int key;
	cout<<"Enter key: ";cin>>key;
	int i=binarysearch(arr,0,n-1,key);
	if(i<0){
		cout<<"Element not exists: ";
	}
	else{
		cout<<"Element found at: "<<i;
	}
	return 0;
}
