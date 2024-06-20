#include<iostream>
#include<stdlib.h>
using namespace std;

int linearSearch(int target, int array[],int size){
	for(int i=0;i<size;i++){
		if(array[i]==target){
			return i;
		}		
	}	
	cout<<"element not found";
	return -1;
}

int main(){
	int a[] = {1,2,3,4,5,6};
	int target = 4;
	int size = sizeof(a)/sizeof(a[0]);
	int index=linearSearch(target,a,size);
	if(index!=-1)
	cout<<"element found at: "<<index;
	return 0;
}
