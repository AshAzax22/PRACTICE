#include<iostream>
#include<unistd.h>
#include<stdlib.h>
using namespace std;
struct node{
	int data;
	struct node *next;
}*front ,*rear;

void enqueue(int i){
	node *newnode=new node();
	newnode->data=i;
	newnode->next=NULL;
	if(front==NULL&&rear==NULL){
		front =rear=newnode;
	}
	else{
		rear->next=newnode;
		rear=newnode;
	}
}
void dequeue(){
	struct node*temp=front;
	if(front==NULL){
		printf("No elements in the queue.\n");
	}	
	else{
		printf("The deleted element is :%d\n",front->data);
		front=front->next;
		if(front==NULL){
			rear=NULL;
		}
		free(temp);
	}

}

void print(){
	struct node*temp=front;
	while(temp!=NULL){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	cout<<endl;
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
