#include <iostream>
using namespace std;

char dial[10][4]={
	{},
	{},
	{'A','B','C'},
	{'D','E','F'},
	{'G','H','I'},
	{'J','K','L'},
	{'M','N','O'},
	{'P','Q','R','S'},
	{'T','U','V'},
	{'W','X','Y','Z'}
};
int main(void){

	string str;
	cin>>str;
	int result=0;
	for(int i=0;i<str.size();i++){
		for(int j=0;j<10;j++)
			for(int k=0;k<4;k++)
				if(str[i]==dial[j][k]){
					result+=j+1;
				}
	}
	cout<<result<<endl;
}