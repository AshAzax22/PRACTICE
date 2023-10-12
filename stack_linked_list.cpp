#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
	int data;
	struct node* next;
};

void push(struct node**top,int ele){
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=ele;
	newnode->next=*top;
	*top=newnode;
}

int pop(struct node**top){
	if(*top==NULL){
		cout<<"Stack Underflow"<<endl;
		return 0;
	}
	struct node*temp=*top;
	*top=temp->next;
	return temp->data;
	free(temp);
}

void display(struct node *top){
	struct node*temp=top;
	
	while(temp!=NULL){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	cout<<"End of stack"<<endl;
}

int main(){
	int c,ele;
	struct node* top=NULL;
	while (true){
		cout<<"Enter :"<<endl<<"1 to push\n2 to pop\n3 to display\n4 to exit\n"<
		cin>>c;
	
		switch (c){
			case 1:
				cout<<"Enter element:";
				cin>>ele;
				push(&top,ele);
				break;
			case 2:
				cout<<"element:";
				ele=pop(&top);
				cout<<ele<<endl;
				break;
			case 3:
				display(top);
				break;
			case 4:
				cout<<"exiting";
				return 0;
			default:
				cout<<"Invalid input."<<endl;
		}
	}
}
