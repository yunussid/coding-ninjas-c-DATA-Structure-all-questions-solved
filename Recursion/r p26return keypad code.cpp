#include<iostream>
#include<string>
using namespace std;
string mapping[]={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
int keypad(int num,string output[]){
    if(num==0){
      output[0]="";
      return 1;
    }
    string o[500];
    int count=keypad(num/10,o);
    string c=mapping[num%10];
    int k=0;
    for(int i=0;i<c.size();i++){
       for(int j=0;j<count;j++){
          output[k++]=o[j]+c[i];
       }
    }
    return k;
}
int main(){
    int num;
    cin>>num;
    string output[10000];
    int count=keypad(num,output);
    for(int i=0;i<count && i<10000;i++){
       cout<<output[i]<<endl;
    }
    return 0;
}
