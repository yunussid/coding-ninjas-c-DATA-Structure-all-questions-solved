/*
Extract Unique characters
Send Feedback
Given a string S, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of
characters should remain same, as in the input string.
*/
#include<iostream>
#include<string>
#include<unordered_map>
#include<cstring>
using namespace std;

string uniqueChar(string str){
    unordered_map<char,int>m;
    string ans="";
    for(int i=0;i<str.size();i++){
        int key=str[i];
        if(m.count(key)==0){
            m[key]==1;
            ans =ans+str[i];
        }else{
        continue;
        }
    }
    return ans;
}

int main(){
    string str;
    cin>>str;
    cout<<uniqueChar(str);
}
