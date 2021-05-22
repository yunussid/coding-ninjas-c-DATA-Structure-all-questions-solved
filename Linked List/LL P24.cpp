/*
kReverse
Send Feedback
Given a singly linked list of integers, reverse the nodes of the linked list 'k' at a time and return its modified list.
 'k' is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of 'k,' then left-out nodes,
in the end, should be reversed as well.
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
Node* kReverse(Node*head,int n)
{
    //write your code here

    if(head == NULL || n == 0 || n == 1){
        return head;
    }

    Node *curr = head;
    Node *prev = NULL;
    Node *next;

    for(int i = 0; i < n && curr != NULL; i++) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    Node *smallAns = kReverse(curr, n);

    head->next = smallAns;
    head = prev;

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
		int k;
		cin >> k;
		head = kReverse(head, k);
		print(head);
	}

	return 0;
}
