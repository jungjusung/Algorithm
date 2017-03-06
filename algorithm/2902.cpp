#include <iostream>
#include <cstring>
using namespace std;
char str[102]="-";
int main(void) {
    string temp;
    cin>>temp;
    for(int i=0;i<temp.size();i++)
        str[i+1]=temp[i];
    for (int i = 0; str[i]; i++)
        if (str[i] == '-')
            cout<<str[i+1];
    return 0;
}