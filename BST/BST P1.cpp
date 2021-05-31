/*
Code: Search in BST
Given a BST and an integer k. Find if the integer k is present in given BST or not. You have to return true, if node with data k is present,
return false otherwise.
*/
#include<iostream>
#include<queue>
using namespace std;

template <typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

bool searchInBST(BinaryTreeNode<int> *root,int k){
    if(root==NULL){
        return false;
    }
    if(root->data==k){
        return true;
    }
    else if(k>root->data){
        return searchInBST(root->right,k);
    }
    else{
        return searchInBST(root->left,k);
    }
}

BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main(){
    BinaryTreeNode<int> *root=takeInput();
    int k;
    cin>>k;
    cout<<((searchInBST(root,k))?"true":"false");
    delete root;
}
