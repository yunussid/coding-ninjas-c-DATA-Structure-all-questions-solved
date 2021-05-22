#include<iostream>
using namespace std;
bool checkNumber(int input[],int n,int x){
    if(n==0){
    return 0;
    }
    if(x==input[0]){
    return 1;
    }
    return checkNumber(input+1,n-1,x);
}
int main(){
    int n;
    cin>>n;
    int *input=new int[n];
    for(int i=0;i<n;i++){
       cin>>input[i];
    }
    int x;
    cin>>x;
    if(checkNumber(input,n,x)){
        cout<<"true";
    }else{
    cout<<"false";
    }
}
