#include <iostream>
#define ull unsigned long long
using namespace std;

int main(void){
	ull s;
	cin>>s;
	for(ull i=0;i<=s;i++){
		ull num=i*(i+1)/2;
		if(num>s){
			cout<<i-1<<endl;
			break;
		}
	} 
}