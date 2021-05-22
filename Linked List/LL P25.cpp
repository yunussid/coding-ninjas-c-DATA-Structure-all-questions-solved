/*
Bubble Sort (Iterative) LinkedList
Send Feedback
Given a singly linked list of integers, sort it using 'Bubble Sort.'
*/
#include <iostream>
class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;
Node *bubbleSort(Node *head){
	// Write your code here
    if(head==NULL || head->next==NULL){
        return head;
    }
    int len=0;
    Node *temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }

    int i=0;
    Node *new_head = head;
    for(i=0;i<len;i++){
        Node *c=new_head;
        Node *prev=NULL;
        Node *n=new_head->next;
        while(c->next!=NULL){
            if(c->data <= n->data){
                prev=c;
                c=n;
                n=n->next;
            } else {
                // Swapping is required, just change some pointers
                if(prev == NULL){
                    c->next = n->next;
                    n->next = c;
                    new_head = n;
                    prev = n;
                    n = c->next;
                } else {
                    c->next = n->next;
                    prev->next = n;
                    n->next = c;

                    // updations
                    prev = n;
                    n = c->next;
                }
            }
 }
    }
    return new_head;
}
Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}
void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
int main()
{
	Node *head = takeinput();
	head = bubbleSort(head);
	print(head);
}
