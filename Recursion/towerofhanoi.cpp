#include<iostream>
using namespace std;

void towerofHanoi(int n,char src,char dest,char hlp){
    if(n==0){
        return;
    }
    towerofHanoi(n-1,src,hlp,dest);
    cout<<"Move from "<<src<<" to "<<dest<<endl;
    towerofHanoi(n-1,hlp,dest,src);
}

int main(){
    towerofHanoi(9,'A','C','B');
    return 0;
}