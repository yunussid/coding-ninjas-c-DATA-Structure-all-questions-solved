#include<iostream>
#include<stack>
using namespace std;

int main(){
 stack<int> p;
 p.push(10);
 p.push(20);
 p.push(30);
 p.push(40);
 p.push(50);
 p.push(60);
 p.push(70);

 cout<<p.top()<<endl;
 p.pop();
 cout<<p.top()<<endl;
 cout<<p.size()<<endl;
 cout<<p.empty()<<endl;

}
