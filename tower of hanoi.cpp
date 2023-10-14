
#include<iostream>
using namespace std;
void TOH(int n, char a,char b,char c){ // transfer from a to c using b
	if(n>1){
		TOH(n-1,a,c,b);
		printf("Transfer a disc from %c to %c.\n",a,c);
		TOH(n-1,b,a,c);
	}
	
}
int main(){
	TOH(10,'A','B','C');
	return 0;
}
