/*
Palindrome LinkedList
Send Feedback
You have been given a head to a singly linked list of integers. Write a function check to whether the list given is a 'Palindrome' or not.
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
 void reverse(Node *head)
    {
        // Initialize current, previous and
        // next pointers
        Node* current = head;
        Node *prev = NULL, *next = NULL;

        while (current != NULL) {
            // Store next
            next = current->next;

            // Reverse current node's pointer
            current->next = prev;

            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }
bool isPalindrome(Node *head)
{
    //Write your code here
    int length=0;
    Node *temp=head;
    Node *t2=head;
    if(head==NULL||head->next == NULL || head->data == NULL ){
        return true;
    }
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }
    int mid=(length+1)/2;
    int i=0;
    Node *t=head;
    while(i<mid){
        t=t->next;
        i++;
    }
    Node *h=t->next;
    t->next==NULL;
    reverse(h);
    while(head!=NULL && h!=NULL){
        if(head->data!=h->data){
            return false;
        }
        head=head->next;
        h=h->next;
    }
    return true;

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
int main(){
 int t;
 cin>>t;

 while(t--){
  Node *head=takeInput();
  bool ans=isPalindrome(head);
  if(ans)cout<<"true";
  else cout<<"false";

  cout<<endl;
 }
 return 0;
}
