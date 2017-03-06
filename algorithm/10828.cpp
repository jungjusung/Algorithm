#include <iostream>
#include <string>
#include <stack>
using namespace std;

int N;
int main(void){

		cin>>N;
		stack<int> s;
		for(int i=0;i<N;i++){
			string str;
			
			cin>>str;
			if(str=="push"){
				int n;
				cin>>n;
				s.push(n);
			}else if(str=="pop"){
				if(s.empty())
					cout<<"-1"<<endl;
				else{
					cout<<s.top()<<endl;
					s.pop();
				}
			}else if(str=="size"){
				cout<<s.size()<<endl;
			}else if(str=="empty"){
				if(s.empty())
					cout<<"1"<<endl;
				else
					cout<<"0"<<endl;
			}else if(str=="top"){
				if(s.empty())
					cout<<"-1"<<endl;
				else{
					cout<<s.top()<<endl;
				}				
			}
		}
}