#include <iostream>
using namespace std;

int main(void){
	int n,x;
	cin>>n>>x;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		if(num<x)
			cout<<num<<" ";
	}
	cout<<endl;

}