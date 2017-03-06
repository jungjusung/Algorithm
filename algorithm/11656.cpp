#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<string> vec;
int main(void){

    string str;
    cin>>str;
    for(int i=0;i<str.size();i++){
        vec.push_back(str.substr(i,str.size()));
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++)
        cout<<vec[i]<<endl;
}