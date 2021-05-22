/*
Even after Odd LinkedList
Send Feedback
For a given singly linked list of integers, arrange the elements such that all the even numbers are placed after the odd numbers. The relative order of the
odd and even terms should remain unchanged.
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
Node* evenAfterOdd(Node* head)
{
    //write your code here
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node *oddH=NULL,*oddT=NULL,*evenH=NULL,*evenT=NULL;
    Node *tmp=head;
    while(tmp!=NULL){
        if(tmp->data%2!=0){
            if(oddH==NULL){
                oddH=tmp;
                oddT=tmp;
            }
            else{
            	oddT->next=tmp;
            	oddT=tmp;
            }
        }
        else{
            if(evenH==NULL){
                evenH=tmp;
                evenT=tmp;
            }
            else{
				evenT->next=tmp;
            	evenT=tmp;
            }
        }
        tmp=tmp->next;
    }
    if(oddH){
    	oddT->next=evenH;
    	return oddH;
    }
    if(evenT!=NULL)
    	evenT->next = NULL;


    return evenH;
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
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		head = evenAfterOdd(head);
		print(head);
	}
	return 0;
}
