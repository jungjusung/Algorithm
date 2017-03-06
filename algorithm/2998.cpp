#include <iostream>
using namespace std;

string s[8]={"000","001","010","011","100","101","110","111"};
int main(void){

	string str;
	string result;
	cin>>str;
	
	while( str.length() % 3 != 0 ) str = "0" + str;
	result=str;
	for(int i=0;i<result.size();i=i+3){
		for(int j=0;j<8;j++){
			bool isOk=true;
			for(int k=0;k<3;k++){
				if(result[i+k]==s[j][k])
					continue;
				isOk=false;
			}
			if(isOk){
				cout<<j;
			}
		}
	}
	cout<<endl;
}