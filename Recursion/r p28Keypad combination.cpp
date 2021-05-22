#include<iostream>
#include<string>
using namespace std;
string mapping[]={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void pk(int num,string out){
     if(num==0){
        cout<<out<<endl;
        return;
     }
     string pd=mapping[num%10];
     for(int i=0;i<pd.size();i++){
        pk(num/10,pd[i]+out);
     }
}
void printKeypad(int num){
     pk(num,"");
}
int main(){
    int num;
    cin>>num;
    printKeypad(num);
    return 0;
}
