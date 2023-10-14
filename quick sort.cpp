#include<iostream>
using namespace std;
int swap(int a[],int b,int c){
	int temp=a[b];
	a[b]=a[c];
	a[c]=temp;
}
int partition(int arr[],int lb,int ub){
	int start=lb;
	int end=ub;
	int pivot=arr[start];
	while(start<end){
		while(arr[start]<=pivot)
			start++;
		while(arr[end]>pivot)
			end--;
		if(start<end){
			swap(arr,start,end);
		}
	}
	swap(arr,lb,end);
	return end;
}

void quicksort(int arr[],int lb,int ub){
	if(lb<ub){
		//cout<<"Yes";
		int	loc=partition(arr,lb,ub);
		quicksort(arr,lb,loc-1);
		quicksort(arr,loc+1,ub);
	}
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i =0;i<n;i++){
		cin>>a[i];
	}
	cout<<"Given array:";
	for(int i =0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	quicksort(a,0,n-1);
	cout<<endl<<"After sorting: ";
	for(int i =0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
