#include<iostream>
using namespace std;

void merge(int a[],int beg,int mid,int end){
	int lenb=mid-beg+1; //length of subarray 1
	int lenc=end-mid; // length of subarray 2
	int b[lenb];
	int c[lenc];
	//copy elements into subarrays
	printf("Subarray 1:\n");
//		if(lenb=0){
//			b[0]=a[beg];
//			cout<<b[0]<<" ";
//	}
	for(int i =0;i<lenb;i++){
		b[i]=a[beg+i];
		cout<<b[i]<<" ";
	}
	printf("\nSubarray 2:\n");
//	if(lenc=0){
//		c[0]=a[mid+1];
//		cout<<c[0]<<" ";
//	}
	for(int i =0;i<lenc;i++){
		c[i]=a[mid+1+i];
		cout<<c[i]<<" ";
	}
	int indm=beg; //index of merged array starts at beginning
	int indc=0;
	int indb=0; // indexings of two subarrays
	
	//comparing elements of two subarrays and putting them into the merged array
	while(indb<lenb && indc<lenc){
		if(b[indb]<=c[indc]){
			a[indm]=b[indb];
			indb++;
			indm++;
		}
		else{
			a[indm]=c[indc];
			indc++;
			indm++;
		}
		
	}
	
	//putting leftover elements if any from arrays into merged array
	while(indb<lenb){
		a[indm]=b[indb];
		indb++;
		indm++;
	}
	while(indc<lenc){
		a[indm]=c[indc];
		indc++;
		indm++;
	}
	printf("\nAfter merge and sort: \n");
	for(int i =0;i<end-beg;i++){
		cout<<a[beg+i]<<' ';
	}
	cout<<endl;
}

void mergesort(int A[],int beg,int end){
	if(beg<end){
		int mid=beg+(end-beg)/2;
		mergesort(A,beg,mid);
		mergesort(A,mid+1,end);
		merge(A,beg,mid,end);
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
	mergesort(a,0,n-1);
	cout<<endl<<"After sorting: ";
	for(int i =0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
