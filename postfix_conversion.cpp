#include<iostream>
#include<stdlib.h>

#include<stack>
using namespace std;

int prec(char c){ //function to determine precedence of operators
	if(c=='^')
	return 3;
	if(c=='*'||c=='/')
	return 2;
	if(c=='+'||c=='-')
	return 1;	
	return 0;
}

void infixtopostfix(string exp){
	stack <char> st; //stack to store operands
	st.push('$');
	string ns; //postfix expression
	int l =exp.length();
	for(int i =0;i<l;i++){
		
		if((exp[i]>='a'&& exp[i]<='z')||(exp[i]>='A'&&exp[i]<='Z')) //to check for operands
			ns+=exp[i];
		
		else if(exp[i]=='(') //check for open bracket
			st.push('(');
		
		else if (exp[i]==')'){ // check for close bracket
			while(st.top()!='$'&&st.top()!='('){ //add all operators until u meet an opening bracket or a $
				ns+=st.top();
				st.pop();		
			}
			if(st.top()=='(') //removing the closing bracket
				st.pop();
		}
		
		else{ //when it is an operator
			while(st.top()!='$'&&prec(exp[i])<=prec(st.top())){
				ns+=st.top();
				st.pop();
			}
			st.push(exp[i]);
		}
	}
	
	while(st.top()!='$'){ // concatenate all the remaining operators in the stack
		ns+=st.top();
		st.pop();
	}
	cout<<ns;
}



int main(){
	string exp;
	cin>>exp;
	infixtopostfix(exp);
}
