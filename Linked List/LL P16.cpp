/*
Code: Merge Two Sorted LL
Send Feedback
You have been given two sorted(in ascending order) singly linked lists of integers.
Write a function to merge them in such a way that the resulting singly linked list is also sorted(in ascending order) and return the new head to the list.
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
Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
    Node *fH=NULL,*fT=NULL;
    if(head1==NULL)return head2;
    if(head2==NULL)return head1;
    if(head1->data<=head2->data){
        fH=head1;
        fT=head1;
        head1=head1->next;
    }else if(head1->data>head2->data){
        fH=head2;
        fT=head2;
        head2=head2->next;
    }
    while(head1!=NULL && head2!=NULL){
            if(head1->data<head2->data){
                fT->next=head1;
                fT=fT->next;
                head1=head1->next;
            }
            else{
                fT->next=head2;
                fT=fT->next;
                head2=head2->next;
            }
    }
        if(head1!=NULL){
             fT->next=head1;
            // head1=head1->next;
            // fT=fT->next;
        }
        if(head2!=NULL){
             fT->next=head2;
             //head2=head2->next;
             //fT=fT->next;
        }


    return fH;
}
Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
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
	int t;
	cin >> t;
	while (t--)
	{
		Node *head1 = takeinput();
		Node *head2 = takeinput();
		Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
		print(head3);
	}
	return 0;
}
