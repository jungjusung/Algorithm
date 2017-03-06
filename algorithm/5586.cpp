#include <iostream>
#include <string>
using namespace std;

string joi="JOI";
string ioi="IOI";
int main(void){

	string str;
	int nJoi=0;
	int nIoi=0;
	int cntJ=0;
	int cntI=0;
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]==joi[cntJ]){
			cntJ++;
			if(cntJ==joi.size()){
				cntJ=0;
				nJoi++;
			}
			if(str[i+1]!=joi[cntJ])
				cntJ=0;

		}

		if(str[i]==ioi[cntI]){
			cntI++;
			if(cntI==ioi.size()){
				cntI=1;
				nIoi++;
			}
			if(str[i+1]!=ioi[cntI])
				cntI=0;						
		}		
	}
	cout<<nJoi<<endl;
	cout<<nIoi<<endl;

}