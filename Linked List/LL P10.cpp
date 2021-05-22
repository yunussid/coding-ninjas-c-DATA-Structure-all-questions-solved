/*
Find a Node in Linked List
Send Feedback
You have been given a singly linked list of integers. Write a function that returns the index/position of an integer data denoted by 'N' (if it exists). Return -1 otherwise.
*/
#include<iostream>
using namespace std;
class Node{
 public:
  int data;
  Node *next;
  Node(int data){
   this->data=data;
   this->next=NULL;
  }
};
int findNode(Node *head,int n){
    Node *temp=head;
    int count=0;
    while(temp!=NULL && temp->data!=-1){
      if(temp->data==n){
        return count;
      }
      temp=temp->next;
      count++;
    }
    return -1;
}
Node *takeInput(){
  int data;
  cin>>data;
  Node *head=NULL,*tail=NULL;
  while(data!=-1){
    Node *newNode=new Node(data);
     if(head==NULL){
       head = newNode;
       tail = newNode;
     }else{
       tail->next=newNode;
       tail=newNode;
     }
     cin>>data;
    }
    return head;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    Node *head = takeInput();
    int val;
    cin>>val;
    cout<<findNode(head,val)<<endl;
  }
}
