#include<iostream>
#include<stack>
#include<math.h>
#include<stdlib.h>
using namespace std;

int postfixtoinfix(string s){
	stack<char> st;
	int l =s.length();
	for(int i=0;i<l;i++){
		
		if(isdigit(s[i])){ //check for operand;
		cout<<int(s[i])-48<<endl;
		st.push(int(s[i])-48);
		}
		else{ //else its an operator
			int b =st.top();
			st.pop();
			int a=st.top();
			st.pop();
			switch(s[i]){
				case '+':
					cout<<a<<"+"<<b<<endl;
					st.push(a+b);
					break;
				case '-':
					cout<<a<<"-"<<b<<endl;
					st.push(a-b);
					break;
				case '*':
					cout<<a<<"*"<<b<<endl;
					st.push(a*b);
					break;
				case '/':
					cout<<a<<"/"<<b<<endl;
					st.push(a/b);
					break;
			}
		}
	}
	
	return st.top();
	
}

int main(){
	string exp;
	cin>>exp;
	cout<<postfixtoinfix(exp);
}
