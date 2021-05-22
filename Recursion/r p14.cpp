#include<iostream>
using namespace std;
int length(char input[]){
    int len=0;
    for(int i=0;input[i]!='\0';i++){
    len++;
    }
    return len++;
}
int checkPalindromeHelper(char input[],int start ,int end){
    if(input[0]=='\0'||input[1]=='\0'){
    return 1;
    }
    if(start>=end){
    return 1;
    }
    if(input[start]==input[end]){
    return checkPalindromeHelper(input,start+1,end-1);
    }
    else{
    return 0;
    }
}
int checkPalindrome(char input[]){
    int len=length(input);
    return checkPalindromeHelper(input,0,len-1);
}
int main(){
    char input[50];
    cin>>input;
     if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
