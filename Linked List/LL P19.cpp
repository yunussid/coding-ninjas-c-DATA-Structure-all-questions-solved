/*
Code: Reverse LL (Iterative)
Send Feedback
Given a singly linked list of integers, reverse it iteratively and return the head to the modified list.
*/
#include <iostream>

class Node {
   public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

using namespace std;
Node *reverseLinkedList(Node *head) {
    // Write your code here
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *prev=NULL;
    Node *cur=head;
    Node *n=NULL;
    while(cur!=NULL){
        n=cur->next;
        cur->next=prev;
        prev=cur;
        cur=n;
     //   n==n->next;
    }
    return prev;
}

Node *takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1) {
        Node *newnode = new Node(data);
        if (head == NULL) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        Node *head = takeinput();
        head = reverseLinkedList(head);
        print(head);
    }

    return 0;
}
