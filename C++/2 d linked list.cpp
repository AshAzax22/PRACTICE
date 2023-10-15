// You are using GCC
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
    int data;
    struct node* next;
};

void insert(struct node**head,int data){
    struct node * newnode=(struct node*)malloc(sizeof(struct node));
    struct node *last=*head;
    newnode->data=data;
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

void print(struct node *head){
    struct node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    int r,c,ele;
    cin>>r>>c;
    struct node *head[r];
    for(int i=0;i<r;i++){
        head[i]=NULL;
        for(int j =0;j<c;j++){
            cin>>ele;
            insert(&head[i],ele);
        }
    }
    
    for(int i =0;i<r;i++){
        print(head[i]);
    }
    return 0;
    
}
