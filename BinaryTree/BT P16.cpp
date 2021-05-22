/*
Level wise linkedlist

Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.
*/
#include<iostream>
#include<queue>
using namespace std;

template <typename T>
class Node {
   public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
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

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    q.push(NULL);
    Node<int>*head=NULL;
    Node<int>*prev=NULL ;
    vector<Node<int>*>v;
    if(root==NULL) return v;
    while(!q.empty())
    {
       BinaryTreeNode<int> *front=q.front();
        q.pop();
        if(front==NULL&&!q.empty())
        {
            q.push(NULL);
           v.push_back(head);
            head=NULL;
            prev=NULL;
            continue;
        }
        if(front==NULL&&q.empty())
        {v.push_back(head);
            break;}
        Node<int>*m=new Node<int>(front->data);
        if(prev==NULL)
        {
            head=m;
             prev=head;
        }
        else
        {
        prev->next=m;
        prev=m;
        }
        if(front->left!=NULL)
            q.push(front->left);
        if(front->right!=NULL)
            q.push(front->right);
    }
    return v;
}

BinaryTreeNode<int> *takeInput(){
    int rootData;
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(q.size()!=0){
        BinaryTreeNode<int> *front=q.front();
        q.pop();
        int leftData,rightData;
        cin>>leftData;
        if(leftData!=-1){
            BinaryTreeNode<int> *leftNode=new BinaryTreeNode<int>(leftData);
            front->left=leftNode;
            q.push(leftNode);
        }
        cin>>rightData;
        if(rightData!=-1){
            BinaryTreeNode<int> *rightNode=new BinaryTreeNode<int>(rightData);
            front->right=rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void print(Node<int> *head) {
    Node<int> *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    BinaryTreeNode<int> *root = takeInput();
    vector<Node<int> *> ans = constructLinkedListForEachLevel(root);

    for (int i = 0; i < ans.size(); i++) {
        print(ans[i]);
    }
}
