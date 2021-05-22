/*
Code : Height of Binary Tree
Send Feedback
For a given Binary Tree of integers, find and return the height of the tree.
*/
#include<iostream>
#include<queue>
using namespace std;

template <typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;
    BinaryTreeNode(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

int height(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int lh=height(root->left);
    int lr=height(root->right);

    if(lr>lh){
        return lr+1;
    }
    return lh+1;
}
BinaryTreeNode<int>* takeInput(){
    int rootData;
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int>* currentNode=q.front();
        q.pop();
        int leftChild,rightChild;
        cin>>leftChild;
        if(leftChild!=-1){
            BinaryTreeNode<int>* leftNode=new BinaryTreeNode<int>(leftChild);
            currentNode->left=leftNode;
            q.push(leftNode);
        }
        if(rightChild!=-1){
            BinaryTreeNode<int>* rightNode=new BinaryTreeNode<int>(rightChild);
            currentNode->right=rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main(){
    BinaryTreeNode<int>* root=takeInput();
    cout << height(root);
}
