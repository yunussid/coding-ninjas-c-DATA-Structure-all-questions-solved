/*
Code: Construct BST from a Sorted Array

Given a sorted integer array A of size n, which contains all unique elements. You need to construct a balanced BST from this input array. Return the root of
constructed BST.
Note: If array size is even, take first mid as root.
*/
#include<iostream>
#include<queue>
using namespace std;

template <typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode *left=NULL;
    BinaryTreeNode *right=NULL;
    BinaryTreeNode(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

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

BinaryTreeNode<int>* helperConstructTree(int *input,int si,int ei){
    if(si>ei){
        return NULL;
    }
    int mid=(si+ei)/2;
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(input[mid]);
    root->left=helperConstructTree(input,si,mid-1);
    root->right=helperConstructTree(input,mid+1,ei);

    return root;

}

BinaryTreeNode<int>* constructTree(int *input,int n){
    helperConstructTree(input,0,n-1);
}


void preOrder(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";

    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    int size;
    cin>>size;
    int *input=new int[size];

    for(int i=0;i<size;i++){
        cin>>input[i];
    }

    BinaryTreeNode<int>* root = constructTree(input, size);
    preOrder(root);
    delete[] input;
}
