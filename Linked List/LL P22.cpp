/*
Delete every N nodes
Send Feedback
You have been given a singly linked list of integers along with two integers, 'M,' and 'N.' Traverse the linked list such that you retain the 'M' nodes, then delete the next 'N' nodes. Continue the same until the end of the linked list.
To put it in other words, in the given linked list, you need to delete N nodes after every M nodes.
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
Node* skipMdeleteN(Node  *head, int M, int N) {
    Node *curr = head, *t=NULL;
    head=curr;
    int count;
    while (curr!=NULL)
    {
        if(M==0){
            return NULL;
        }

        for (count = 1; count < M && curr!= NULL; count++)
        {curr = curr->next;}
        if(curr==NULL){
            return head;
        }
        t = curr->next;
        for (count = 1; count<=N &&t!= NULL; count++)
        {
            Node *temp = t;
            t = t->next;
            free(temp);
        }
        curr->next = t;
        curr = t;
    }
    return head;

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
		int m, n;
		cin >> m >> n;
		head = skipMdeleteN(head, m, n);
		print(head);
	}
	return 0;
}
