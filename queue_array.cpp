#include<iostream>
using namespace std;
int front= 0,rear=0;
#define size 4 //change as per requirements
int q[4];

void enqueue(int i){
	if(rear==size) 
		cout<<"Queue overflow."<<endl;
	else{
		q[rear]=i;
		rear++;
	}
}

void dequeue(){
	if(front==size)
		cout<<"Queue overflow."<<endl;
	else{
		cout<<"Element removed :"<<q[front]<<endl;
		front++;
	}
}

void print(){
	if(front==rear){
		cout<<"Queue is empty"<<endl;
	}
	else{
		for(int i =front;i<rear;i++){
		
			cout<<q[i]<<endl;
			
		}
		}
	}




int main(){
	int choice,value;
	while(1){
		cin>>choice;
		switch(choice){
			case 1:
				cin>>value;
				enqueue(value);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				print();
				break;
			case 4:
				printf("exiting");
				return 0;
			default:
				printf("Invalid Choice");	
		}
	}
}
