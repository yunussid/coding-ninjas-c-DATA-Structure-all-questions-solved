/*
Code: Merge Sort
Send Feedback
 Given a singly linked list of integers, sort it using 'Merge Sort.'
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
Node *mergeSort(Node *head)
{
	//Write your code here
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    int mid=len/2;
    Node *h1=head;
    int i=0;
    while(i<mid-1){
        h1=h1->next;
        i++;
    }
    Node *t1=h1->next;
    h1->next=NULL;
    Node *t2=head;
    t2=mergeSort(t2);
    t1=mergeSort(t1);
    return mergeTwoSortedLinkedLists(t2,t1);
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
		head = mergeSort(head);
		print(head);
	}

	return 0;
}
