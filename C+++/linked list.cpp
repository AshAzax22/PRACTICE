p#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	int data;
	struct node* next;
};

void insert_into_linked_list_beginning(struct node **headref,int element){
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=element;
	newnode->next=*headref;
	*headref=newnode;
}

void insert_into_linked_list_end(struct node **headref,int element){
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	struct node *lastnode=*headref;
	newnode->data=element;
	newnode->next=NULL;
	
	if(*headref==NULL){
		*headref=newnode;
		
	}
	else{
		while(lastnode->next!=NULL){
			lastnode=lastnode->next;
		}
		lastnode->next=newnode;
	}
}

void print_linked_list(struct node *head){
	struct node* temp= head;
	while(temp!=NULL){
	cout<<temp->data<<" Address of next node: "<<temp->next<<"  Adress of current node: "<<&(temp->data)<<endl;
	temp=temp->next;
	}
}

void insertNode(struct node **head,int element,int index){
    int counter=0;
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    struct node* after=*head;
    
    while(counter!=index-1){
        after=after->next;
        counter++;
    }
    newnode->data=element;
    newnode->next=after;
    
    struct node *before=*head;
    while(before->next!=newnode->next){
        before=before->next;
    }
    before->next=newnode;
    
    
}

int main(){
	int n,element;
	struct node *head= NULL;
	cout<<"enter number of elements to be inserted: ";	
	cin>>n;
	cout<<endl;
	for(int  i =0;i<n;i++){
		cout<<"Enter the element to be inserted:";
		cin>>element;
		cout<<endl;
		insert_into_linked_list_end(&head,element);
	}
	
	print_linked_list(head);
	cout<<endl;
	//cout<<"address inside the head:"<<head<<endl;
	cout<<endl<<"enter number to be inserted: ";
	cin>>element;
	int index;
	cout<<endl<<"Enter index to be inserted in: ";
	cin>>index;
	
	if (index>n){
	insert_into_linked_list_end(&head,element);
	}
	else{
	insertNode(&head,element,index);  
	}
	cout<<endl<<"updated linked list: " <<endl;
	
	print_linked_list(head);
	return 0;
}



