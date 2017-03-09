#include <iostream>
using namespace std;


int main(void){

	int score=0;
	for(int i=0;i<5;i++){
		int n;
		cin>>n;
		if(n<40)
			score+=40;
		else
			score+=n;
	}
	cout<<score/5<<endl;
}