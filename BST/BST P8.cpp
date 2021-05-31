/*
Code: BST to Sorted LL
Send Feedback
Given a BST, convert it into a sorted linked list. You have to return the head of LL.
*/

#include<iostream>
#include<queue>
using namespace std;

template <typename T>
class Node{
    public:
    T data;
    Node<T>* next;
    Node(T data){
        this->data=data;
        this->next=NULL;
    }
};

template <typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<int> *left;
    BinaryTreeNode<int> *right;
    BinaryTreeNode(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

BinaryTreeNode<int> *takeInput(){
    int rootData;
    cin>>rootData;
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(q.size()!=0){
        BinaryTreeNode<int> *front=q.front();
        q.pop();
        int leftChild,rightChild;
        cin>>leftChild;
        if(leftChild!=-1){
            BinaryTreeNode<int> *leftNode=new BinaryTreeNode<int>(leftChild);
            front->left=leftNode;
            q.push(leftNode);
        }
        cin>>rightChild;
        if(rightChild!=-1){
            BinaryTreeNode<int> *rightNode=new BinaryTreeNode<int>(rightChild);
            front->right=rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

Node<int> *head=NULL;
Node<int> *tail=NULL;

void helperConstructLinkedList(BinaryTreeNode<int> *root){
    if(root==NULL ){
        return;
    }

    helperConstructLinkedList(root->left);
    Node<int> *node = new Node<int>(root->data);
    if(tail == NULL){
        head = node;
        tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
    helperConstructLinkedList(root->right);
}

Node<int>* constructLinkedList(BinaryTreeNode<int> *root){
    helperConstructLinkedList(root);
    return head;
}

int main(){
    BinaryTreeNode<int>* root=takeInput();
    Node<int>* head=constructLinkedList(root);

    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
