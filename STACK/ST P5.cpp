#include<iostream>
#include<string>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string expression){
     stack<char> s;
     char x;

     for(int i=0;i<expression.length();i++){
       if(expression[i]=='('||expression[i]=='['||expression[i]=='{'){
         s.push(expression[i]);
         continue;
       }
       if(s.empty()){
        return false;
       }
       switch(expression[i]){
        case ')':
         x=s.top();
         s.pop();
          if(x=='}'||x==']'){
           return false;
           break;
          }

          case ']':
         x=s.top();
         s.pop();
          if(x==')'||x=='}'){
           return false;
           break;
          }

          case '}':
         x=s.top();
         s.pop();
          if(x==']'||x==')'){
           return false;
           break;
          }
       }
       return (s.empty());
     }
}
int main(){
    string input;
    cin>>input;
    cout<<((isBalanced(input))?"true":"false");
}
