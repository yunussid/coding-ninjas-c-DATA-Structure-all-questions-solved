/*
Delete Alternate Nodes
Send Feedback
Given a Singly Linked List of integers, delete all the alternate nodes in the list.
*/
#include <iostream>

class Node {
public:
    int data;
    Node * next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    ~Node() {
        if(next) {
            delete next;
        }
    }
};

using namespace std;


Node* takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}
void deleteAlternateNodes(Node *head) {
    //Write your code here
    if (head == NULL)
        return;

    /* Initialize prev and node to be deleted */
    Node *prev = head;
    Node *node = head->next;

    while (prev != NULL && node != NULL)
    {
        /* Change next link of previous node */
        prev->next = node->next;

        /* Free memory */
        free(node);

        /* Update prev and node */
        prev = prev->next;
        if (prev != NULL)
            node = prev->next;
    }
}

int main() {
    Node *head = takeinput();
    deleteAlternateNodes(head);
    print(head);
    delete head;
    return 0;
}
