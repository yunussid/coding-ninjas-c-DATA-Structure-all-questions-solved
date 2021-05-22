#include<iostream>
using namespace std;
int sumOfDigits(int n){
    if(n<10){
    return n;
    }
    int a=(n%10)+sumOfDigits(n/10);
    return a;
}
int main(){
    int n;
    cin>>n;
    cout<<sumOfDigits(n)<<endl;
}
