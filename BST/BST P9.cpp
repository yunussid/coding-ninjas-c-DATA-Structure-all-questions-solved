/*
Find Path in BST
Send Feedback
Given a BST and an integer k. Find and return the path from the node with data k and root (if a node with data k is present in given BST) in a list.
Return empty list otherwise.
*/
#include <vector>
#include<iostream>
#include<queue>
using namespace std;

template <typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<int> *left;
    BinaryTreeNode<int> *right;
    BinaryTreeNode(T data){
        this->data=data;
        BinaryTreeNode<int> *left;
        BinaryTreeNode<int> *right;
    }
};

vector<int>* getPath(BinaryTreeNode<int> *root,int data){
    if(root==NULL){
        return NULL;
    }
    if(root->data==data){
        vector<int>* output=new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int>* ans;
    if(root->data>data){
        ans= getPath(root->left , data);
    }else{
         ans=getPath(root->right ,  data);
    }

    if(ans==NULL) return  NULL;
    ans->push_back(root->data);
    return ans;
}

BinaryTreeNode<int> *takeInput(){
    int rootData;
    cin>>rootData;
    if(rootData!=-1){
        return NULL;
    }
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    while(q.size()!=0){
        BinaryTreeNode<int> *front=q.front();
        q.push(front);
        int leftChild,rightChild;
        cin>>leftChild;
        if(leftChild!=-1){
            BinaryTreeNode<int> *leftNode=new BinaryTreeNode<int>(leftChild);
            front->left=leftNode;
            q.push(leftNode);
        }
        cin>>rightChild;
        if(rightChild){
            BinaryTreeNode<int> *rightNode=new BinaryTreeNode<int>(rightChild);
            front->right=rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main(){
    BinaryTreeNode<int> *root=takeInput();
    int k;
    cin>>k;
    vector<int> *output=getPath(root,k);

    if(output!=NULL){
        for(int i=0;i<output->size();i++){
            cout<< output->at(i)<<" ";
        }
    }
    delete root;
}
