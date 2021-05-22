#include<iostream>
using namespace std;
void removeX(char s[]){
     if(s[0]=='\0'){
        return;
     }
     if(s[0]!='x'){
        removeX(s+1);
     }else{
        int i;
        for(i=0;s[i]!='\0';i++){
            s[i-1]=s[i];
        }
        s[i-1]=s[i];
        removeX(s);
     }

}
int length(char input[]){
     if(input[0]=='\0'){
        return 0;
     }
     int smallLength=length(input+1);
     return 1+smallLength;
}
int main(){
    char str[100];
    cin>>str;
    int l=length(str);
    cout<<l<<endl;
    removeX(str);
    cout<<str<<endl;
    int l1=length(str);
    cout<<l1<<endl;
}
