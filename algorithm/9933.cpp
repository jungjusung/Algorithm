#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<string> vec;
int main(void){

    cin>>N;
    string str;
    string result;
    for(int i=0;i<N;i++){
        cin>>str;
        vec.push_back(str);
    }
    for(int i=0;i<N;i++){
        string temp=vec[i];
        reverse(temp.begin(),temp.end());
        for(int j=0;j<N;j++){
            if(temp==vec[j]){
                result=temp;
                break;
            }
        }
    }

    int n=result.size();
    int n2=n/2;
    cout<<n<<" "<<result[n2]<<endl;
}