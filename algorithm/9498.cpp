#include <iostream>
using namespace std;



char getScore(int score){
	if(90<=score&&score<=100){
		return 'A';
	}else if(80<=score&&score<90){
		return 'B';
	}else if(70<=score&&score<80){
		return 'C';
	}else if(60<=score&&score<70){
		return 'D';
	}else{
		return 'F';
	}
}

int main(void){

	int n;
	cin>>n;
	cout<<getScore(n)<<endl;
}