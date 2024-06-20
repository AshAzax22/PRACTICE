//BINARY TREE
//Height of tree= number of levels
//Number of children possible at a level n= 2^n
//Maximum number of nodes posible for height h = 2^(h+1)-1
//Minimum number of nodes for height h = h+1
//Minimum height of a tree that cotains n nodes= log²(n+1)-1 [base 2 of log]   [found via maximum nodes formula]
//Maximum height of a tress that contains n nodes= n-1		[found via minimum nodes formula]
//
//Types of Binary tree:
//	Full/Proper/Strict :
//		Every node as either 2 or 0 children
//	Complete Binary tree:
//		All level are completely filled, except the last level which is filled from the left.
//	Perfect binary tree:
//		All internal nodes have 2 children and all leaves are at same level [Every perfect binary tree is full and complete]
//	Degenerate tree:
//		Each internal node has only one child.
//		If every node has only left children: left degenerate tree
//		If every node has only right children: right degenerate tree
//
//Properties:
//			Maximum Height		Minimum Height		Maximum Nodes		Minimum Nodes
//	Binary 		n-1				 log²(n+1)-1	      2^(h+1)-1			 2^(h+1)-1
//	Full	   (n-1)/2			 log²(n+1)-1		  2^(h+1)-1			   2h+1
//	Complete	log n 			 log²(n+1)-1		  2^(h+1)-1			    2^h
//	



#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	struct node*left;
	struct node*right;
	int data;
};


void preorder(struct node *root){ // print the data then traverse the left , then traverse the right
	if(root==0)
		return ;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
	
}

void inorder(struct node *root){ // traverse the left , print the data, traverse the right
	if(root==0)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);	
	
}

int total_level=0;

void postorder(struct node*root){ //traverse the left, traverse the right, print the data
	if(root==0)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
	
}

struct node* create(int level,string pos="left",int parent=0){
 	node *newnode=new  node();  // or struct node *newnode=(struct node *)malloc(sizeof(structnode));
 	int x;
	total_level=max(level,total_level);
	if(level==0)
 		cout<<"Enter value of root node: "<<endl;
	else{
		cout<<"The value at current node :"<<parent<<endl;
		cout<<"Enter data for "<<pos<<" child"<<endl;
	}
	cout<<"Enter -1 for no node."<<endl;
	cin>>x;
	cout<<endl;
	if(x==-1)
		return 0;
 	newnode->data=x;
 	newnode->left=create(level+1,"left",x);
 	newnode->right=create(level+1,"right",x);
 	return newnode;
}

int main(){
	struct node * root;
	root=create(0);
	cout<<"Preorder: ";
	preorder(root);
	cout<<endl<<"Inorder: ";
	inorder(root);
	cout<<endl<<"Postorder: ";
	postorder(root);
	cout<<endl<<"LEVELS: "<<total_level;
	return 0;
	
}
