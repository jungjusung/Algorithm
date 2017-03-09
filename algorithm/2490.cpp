#include <iostream>
using namespace std;

int main(void){

	int a,b,c,d;

	for(int t=0;t<3;t++){
		int cnt=0;
		for(int i=0;i<4;i++){
			int n;
			cin>>n;
			if(n==0)
				cnt++;
		}
		switch(cnt){
			case 1:
				cout<<"A"<<endl;
				break;
			case 2:
				cout<<"B"<<endl;
				break;
			case 3:
				cout<<"C"<<endl;
				break;
			case 4:
				cout<<"D"<<endl;
				break;
			default:
				cout<<"E"<<endl;
				break;
		}
	}
}