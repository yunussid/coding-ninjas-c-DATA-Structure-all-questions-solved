/*
AppendLastNToFirst
You have been given a singly linked list of integers along with an integer 'N'. Write a function to append the last 'N' nodes
towards the front of the singly linked list and returns the new head to the list.
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
Node *appendLastNToFirst(Node *head,int n){
    if(n==0||head==NULL){
      return head;
    }
    Node *fast=head;
    Node *slow=head;
    Node *initialHead=head;
    for(int i=0;i<n;i++){
      fast=fast->next;
    }
    while(fast->next!=NULL){
      slow=slow->next;
      fast=fast->next;
    }
    Node *temp=slow->next;
    slow->next=NULL;
    fast->next=initialHead;
    head=temp;
    return head;
}
Node *takeInput(){
  int data;
  cin>>data;
  Node *head=NULL,*tail=NULL;
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
  Node *temp = head;
  while(temp !=NULL){
     cout<<temp->data;
     temp=temp->next;
  }
  cout<<endl;
}
int main(){
 int t;
 cin>>t;
 while(t--){
   Node *head = takeInput();
   int n;
   cin>>n;
   head=appendLastNToFirst(head,n);
   print(head);
 }
 return 0;
}
