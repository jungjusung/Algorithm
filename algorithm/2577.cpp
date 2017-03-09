#include <iostream>
#include <cstring>
#include <cstdlib>
#define ull unsigned long long
using namespace std;


int arr[10];
int main(void){
	int a,b,c;
	cin>>a>>b>>c;
	ull ans=a*b*c;
	string temp=to_string(ans);
	for(int i=0;i<temp.size();i++){
		arr[(int)temp[i]-'0']++;
	}
	for(int i=0;i<10;i++)
		cout<<arr[i]<<endl;
}