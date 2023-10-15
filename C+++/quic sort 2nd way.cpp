#include<iostream>
using namespace std;
int swap(int a[],int b,int c){
	int temp=a[b];
	a[b]=a[c];
	a[c]=temp;
}
int partition(int arr[],int lb,int ub){
	int pivot=arr[ub];
	int start=lb-1;
	for(int i =lb;i<ub;i++){
		if(arr[i]<pivot){
			start++;
			swap(arr,start,i);
		}
	}
	swap(arr,start+1,ub);
	return start+1;
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
