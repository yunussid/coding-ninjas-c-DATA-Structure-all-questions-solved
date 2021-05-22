#include<iostream>
using namespace std;
int countZero(int n){
    if(n<10){
    return 0;
    }
    if(n==0){
    return 1;
    }
    int a;
    a=countZero(n/10);
    if(n%10==0){
    return a+1;
    }
    return a;
}
int main(){
    int n;
    cin>>n;
    cout<<countZero(n)<<endl;
}
