#include<iostream>
#include<stack>
using namespace std;
void reverseStack(stack<int> &input,stack<int> &extra){
 int x=input.top();
 input.pop();

 reverseStack(input,extra);
 if(input.size()>0){
 while(input.size()!=0){
  int y=input.top();
  input.pop();
  extra.push(y);
 }
 extra.push(x);
 while(extra.size()!=0){
  int z=extra.top();
  extra.pop();
  input.push(z);
 }
 }
}
int main(){
 stack<int> input,extra;
 int size;
 cin>>size;

 for(int i=0,val;i<size;i++){
  cin>>val;
  input.push(val);
 }
 reverseStack(input,extra);
 while(!input.empty()){
  cout<<input.top()<<endl;
  input.pop();
 }
}
