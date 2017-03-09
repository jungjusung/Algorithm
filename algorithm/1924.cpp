#include <iostream>
#include <cstring>
using namespace std;

string day[]={"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
int month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(void){
	int x,y,num=0;
	cin>>x>>y;
	for(int i=0;i<x;i++){
		num+=month[i];
	}
	num+=y;
	cout<<day[num%7]<<endl;

}