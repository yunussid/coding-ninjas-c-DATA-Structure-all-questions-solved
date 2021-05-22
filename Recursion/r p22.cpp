#include<iostream>
#include<cstring>
using namespace std;
void removeConsecutiveDuplicates(char *input){
    if(input[0]=='\0'){
        return;
    }
    if(input[0]!=input[1]){
        removeConsecutiveDuplicates(input+1);
    }
    else{
        int i=1;
        for(;input[i]!='\0';i++){
            input[i-1]=input[i];
        }
        input[i-1]=input[i];
        removeConsecutiveDuplicates(input);
    }
}
int main(){
    char s[1000000];
    cin>>s;
    removeConsecutiveDuplicates(s);
    cout<<s<<endl;
}
