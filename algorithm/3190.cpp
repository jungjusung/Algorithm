#include <iostream>
#include <vector>


using namespace std;


class point{
public:
    int x;
    int y;
    point(){};
    point(int _y,int _x){
        x=_x;
        y=_y;
    }
};

int N,K,L;
int board[101][101];
vector<point> length;
vector<pair<int,char> > change;
char setDirect(char cur,char dir){
    char ret;

    if(cur=='R'){
        if(dir=='D'){
            ret='D';
        }
        if(dir=='L')
            ret='U';
    }else if(cur=='D'){
        if(dir=='D'){
            ret='L';
        }
        if(dir=='L')
            ret='R';
    }else if(cur=='L'){
        if(dir=='D'){
            ret='U';
        }
        if(dir=='L')
            ret='D';
    }else if(cur=='U'){
        if(dir=='D'){
            ret='R';
        }
        if(dir=='L')
            ret='L';
    }
    return ret;
};
int main(void){

    cin>>N>>K;

    for(int i=0;i<K;i++){
        int y,x;
        cin>>y>>x;
        board[y][x]=1;
    }
    int start=0;
    int dx=1;
    int dy=1;
    point p(dy,dx);
    length.push_back(p);
    cin>>L;
    char cur='R';
    for(int i=0;i<L;i++){
        int len;
        char dir;

        cin>>len>>dir;
        change.push_back(make_pair(len,dir));
    }
    /*for(int i=0;i<change.size();i++){
        cout<<change[i].first<<" "<<change[i].second<<endl;
    }*/
    int flag=0;
    while(start<=10000){

        for(int i=0;i<change.size();i++){
            if(change[i].first==start){
                cur=setDirect(cur,change[i].second);
                //cout<<cur<<endl;
            }
        }
        start++;
        if(cur=='R'){
            dx+=1;
            if(dx<1||dy<1||dx>N||dy>N)
            {
                cout<<start<<endl;
                break;
            }

            for(int i=0;i<length.size();i++){
                if(length[i].x==dx&&length[i].y==dy){
                    cout<<start<<endl;
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                break;

            point p(dy,dx);
            length.push_back(p);
            if(board[dy][dx]!=1){
                length.erase(length.begin());
            }else if(board[dy][dx]==1){
                board[dy][dx]=0;
            }



        }else if(cur=='L'){
          dx-=1;
            if(dx<1||dy<1||dx>N||dy>N)
            {
                cout<<start<<endl;
                break;
            }

            for(int i=0;i<length.size();i++){
                if(length[i].x==dx&&length[i].y==dy){
                    cout<<start<<endl;
                     flag=1;
                    break;
                }
            }
                        if(flag==1)
                break;
            point p(dy,dx);
            length.push_back(p);
            if(board[dy][dx]!=1){
                length.erase(length.begin());
            }else if(board[dy][dx]==1){
                board[dy][dx]=0;
            }
        }else if(cur=='D'){
          dy+=1;
            if(dx<1||dy<1||dx>N||dy>N)
            {
                cout<<start<<endl;
                break;
            }

            for(int i=0;i<length.size();i++){
                if(length[i].x==dx&&length[i].y==dy){
                    cout<<start<<endl;
                     flag=1;
                    break;
                }
            }
             if(flag==1)
                break;
            point p(dy,dx);
            length.push_back(p);
            if(board[dy][dx]!=1){
                length.erase(length.begin());
            }else if(board[dy][dx]==1){
                board[dy][dx]=0;
            }
        }else if(cur=='U'){
            dy-=1;
            if(dx<1||dy<1||dx>N||dy>N)
            {
                cout<<start<<endl;
                break;
            }

            for(int i=0;i<length.size();i++){
                if(length[i].x==dx&&length[i].y==dy){
                    cout<<start<<endl;
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                break;
            point p(dy,dx);
            length.push_back(p);
            if(board[dy][dx]!=1){
                length.erase(length.begin());
            }else if(board[dy][dx]==1){
                board[dy][dx]=0;
            }
        }


    }


}