//Binary tree representation in array
//			A
//		   / \
//		  B   C
//		 / \ / \
//		D  E F  G
//	   /		 
//	   H
//
//Array m=[A,B,C,D,E,F,G,H]
//input elements into the array starting from top , moving level by level left to right
//if element adress is i
//adress of left child of i = (2*i)+1;
//adress of right child of i= (2*i)+2;
//and adress of parent = floor((i-1)/2);
//
//CONDITIONS:
//the tree should be a complete tree
//if not then fill the incomplete spaces with blanks in the array to make the formulae effective

#include<iostream>
#include<math.h>
using namespace std;

int total_level=0;
int occur=0,count=0;

int add(int arr[],int ele,int pos,int parent){
	arr[(parent*2)+pos]=ele;
	return parent*2+pos;
}
void create(int arr[],int level,int index,int pos=1){
	if(index==0){
		occur++;
		if(occur>2){
			return;
		}
	}
	if (index<0){
		return;
	}
	int x,child;
	total_level=max(level,total_level);
	cout<<endl;
	cout<<"Currently at node value: "<<arr[index]<<endl;
	if(pos==1)
		cout<<"Enter data for left child";
	else
		cout<<"Enter data for right child";
	//cout<<endl<<"You are at level "<<level<<endl;
	cout<<endl<<"Enter -1 for no node."<<endl;
	cin>>x;
	
	if(x==-1){
		add(arr,0,pos,index);
		if(pos==1){
		cout<<"getting back from left node."<<endl;
		create(arr,level,index,2);
		}
		else{
			cout<<"getting back from right node."<<endl;
			int parent_index=floor((index-1)/2);
			if(index==(parent_index*2+1))
			create(arr,level-1,parent_index,2);
			else{
				parent_index=floor((parent_index-1)/2);
				create(arr,level-2,parent_index,2);
			}	
		}
	}
	else{
		count++;
		child=add(arr,x,pos,index);
		create(arr,level+1,child,1);
	}
	
	
}
	
void display(int arr[]){
	//for(int i =0;i<pow(2,total_level)-1;i++){
	for(int i =0;i<count+1;i++){
		if(arr[i]==0)
			cout<<"element:  "<<" \tindex: "<<i<<endl;
		else
			cout<<"element: "<<arr[i]<<" \tindex: "<<i<<endl;
	}
}

int main(){
	int arr[128];
	cout<<"Enter root node: ";
	cin>>arr[0];
	create(arr,1,0,1);
	printf("Total Levels: %d\n",total_level);
	
	display(arr);
	return 0;
} 
