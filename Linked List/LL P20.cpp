/*
Find a node in LL (recursive)
Send Feedback
Given a singly linked list of integers and an integer n, find and return the index for the first occurrence of 'n' in the linked list. -1 otherwise.
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
int findNode(Node *head,int n ,int i){
    if(head==NULL || head->next==NULL){
        return -1;
    }
    if(head->data==n){
        return i;
    }
    i++;
    findNode(head->next,n ,i);
}
int findNodeRec(Node *head, int n)
{
	//Write your code here
    if(head==NULL)
        return -1;

    int i=0;
    findNode(head,n,i);

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

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int val;
		cin >> val;
		cout << findNodeRec(head, val) << endl;
	}
}
