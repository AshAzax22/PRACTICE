#include<iostream>
#define size 5
using namespace std;
int stack[size],top=-1;
void push(int ele){
	if(top==size-1){
		cout<<"Stack overflow."<<endl;
		return ;
	}
	top++;
	stack[top]=ele;
}

void pop(){
	if(top==-1){
		cout<<"STcak underflow"<<endl;
		return ;
	}
	cout<<"Element removed: "<<stack[top]<<endl;
	top--;
}
void display(){
	if(top==-1){
		cout<<"Stack empty"<<endl;
		return;
	}
	for(int i =top;i>=0;i--)
	cout<<stack[i]<<endl;
}


int main(){
	int c,ele;
	while (true){
		cout<<"Enter :"<<endl<<"1 to push\n2 to pop\n3 to display\n4 to exit\n"<
		cin>>c;
		switch (c){
			case 1:
				cout<<"Enter element:";
				cin>>ele;
				push(ele);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				cout<<"exiting";
				return 0;
			default:
				cout<<"Invalid input."<<endl;
		}
	}
}
