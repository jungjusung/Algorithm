#include <iostream>
#include <cstring>
#include <string>
#include <stack>
using namespace std;


bool chk[1000001];
int main(void){

	string str1;
	string str2;
	memset(chk,true,sizeof(chk));
	cin>>str1>>str2;
	if(str2.size()==1){
		for(int i=0;i<str1.size();i++){
			if(str1[i]==str2[0])
				chk[i]=false;
		}
	}else{

		stack<pair<int, int> > s;

		
		for(int i=0;i<str1.size();i++){
			if(str1[i]==str2[0]){
				s.push(make_pair(i,0));
				//cout<<s.top().second<<endl;
			}else{
				if(!s.empty()){
					if(str1[i]==str2[s.top().second+1]){
						s.push(make_pair(i,s.top().second+1));
						if(s.top().second+1==str2.size()){
							for(int j=0;j<str2.size();j++){
								chk[s.top().first]=false;
								s.pop();
							}
						}
					}else{
						while(!s.empty()){
							s.pop();
						}
						
					}
				}
			}
		}
	}
	bool isOk=false;
	for(int i=0;i<str1.size();i++){
		if(!chk[i])
			continue;
		cout<<str1[i];
		isOk=true;
	}
	if(!isOk)
		cout<<"FRULA";
	cout<<endl;
}