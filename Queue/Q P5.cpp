#include<iostream>
#include<queue>
using namespace std;

void reverseQueue(queue<int> &q){
 if(q.empty()){
  return;
 }
 int x=q.front();
 q.pop();
 reverseQueue(q);
 q.push(x);
}
int main(){
   int t;
   cin>>t;

   while(t--){
    queue<int> q;
    int size;
    cin>>size;

    for(int i=0,val;i<size;i++){
     cin>>val;
     q.push(val);
    }
    reverseQueue(q);
    while(!q.empty()){
     cout<<q.front()<<endl;
     q.pop();
    }
    cout<<"\n";
   }
}
