/*
Eliminate duplicates from LL
You have been given a singly linked list of integers where the elements are sorted in ascending order. Write a function that removes the consecutive
duplicate values such that the given list only contains unique elements and returns the head to the updated list.
*/
#include<iostream>
using namespace std;
class Node{
 public:
  int data;
  Node* next;
  Node(int data){
   this->data=data;
   this->next=NULL;
  }
};
Node *removeDuplicates(Node *head){
   if(head==NULL||head->next==NULL){
     return NULL;
   }
   Node *temp=head;
   while(temp!=NULL && temp->next!=NULL){
     if(temp->data==temp->next->data){
      temp->next=temp->next->next;
     }else{
       temp=temp->next;
     }
   }
   return head;
}
Node *takeInput(){
 int data;
 cin>>data;
 Node *head=NULL, *tail=NULL;
 while(data!=-1){
  Node *newNode=new Node(data);
  if(head==NULL){
    head=newNode;
    tail=newNode;
  }else{
    tail->next=newNode;
    tail=newNode;
  }
  cin>>data;
 }
  return head;
}
void print(Node *head){
  Node *temp=head;
  while(temp != NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<endl;
}
int main(){
 int t;
 cin>>t;
 while(t--){
   Node *head=takeInput();
   head=removeDuplicates(head);
   print(head);
 }
 return 0;
}
