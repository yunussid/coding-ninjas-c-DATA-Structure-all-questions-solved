/*
Print Reverse LinkedList
You have been given a singly linked list of integers. Write a function to print the list in a reverse order.
To explain it further, you need to start printing the data from the tail and move towards the head of the list, printing the head data at the end.
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
Node *takeInput(){
 int data;
 cin>>data;
 Node *head=NULL,*tail=NULL;
 while(data!=-1){
  Node *newNode=new Node(data);
  if(head==NULL){
   head=newNode;
   tail=newNode;
  }
  else{
   tail->next=newNode;
   tail=newNode;
  }
  cin>>data;
 }
 return head;
}
void print(Node *head){
 Node *temp=head;
 while(temp!=NULL){
  cout<<temp->data<<" ";
  temp=temp->next;
 }
 cout<<endl;
}
void printReverse(Node *head){
  if(head==NULL){
   return;
  }
  printReverse(head->next);
  cout<<head->data<<" ";
}
int main(){
 int t;
 cin>>t;
 while(t--){
  Node *head=takeInput();
  printReverse(head);
  cout<<endl;
 }
 return 0;
}
