#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int low,int high){
	int pivot=arr[high];
	int j=low-1;
	for(int i=low;i<=high;i++){
		if(arr[i]<pivot){
			j++;
			swap(arr[j],arr[i]);
		}
	}
	swap(arr[j+1],arr[high]);
	return j+1;
}

void qsort(int arr[],int low,int high){
	if(low<high){
		int j=partition(arr,low,high);
		qsort(arr,low,j-1);
		qsort(arr,j+1,high);
	}
}

int main(){
	int n;
	cout<<"Enter length: ";
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	cout<<"Sorted array: ";
	qsort(arr,0,n-1);
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
	return 0;
}
