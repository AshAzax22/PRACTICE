// You are using GCC
#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    struct node* next;
};

void insert(struct node **head,int element){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    struct node *last=*head;
    newnode->data=element;
    newnode->next=NULL;
    if(*head==NULL){
        *head=newnode;
    }
    else{
        while(last->next!=NULL){
            last=last->next;
        }
        last->next=newnode;
    }
}

void printlist(struct node *head){
    struct node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


int main(){
    struct node *head1=NULL;
    struct node *head2=NULL;
    int n1,n2,element;
    cin>>n1;
    for(int i =0;i<n1;i++){
        cin>>element;
        insert(&head1,element);
    }
    cin>>n2;
    for(int i =0;i<n2;i++){
        cin>>element;
        insert(&head2,element);
    };
    struct node *head3=NULL;
    struct node *temp1=head1;
    struct node *temp2=head2;
    
    if(n1<=n2){
        for(int i=0;i<n1;i++){
            insert(&head3,temp2->data+temp1->data);
            temp2=temp2->next;
            temp1=temp1->next;
        }
        for(int i =n1;i<n2;i++){
            insert(&head3,temp2->data);
            temp2=temp2->next;
        }
    }
    else{
        for(int i=0;i<n2;i++){
            insert(&head3,temp1->data+temp2->data);
            temp1=temp1->next;
            temp2=temp2->next;
        }
        for(int i =n2;i<n1;i++){
            insert(&head3,temp1->data);
            temp1=temp1->next;
        }
        
    }
    cout<<"First linked list: ";
    printlist(head1);
    cout<<"Second linked list: ";
    printlist(head2);
    cout<<"Total sum: ";
    printlist(head3);
    return 3;
}
