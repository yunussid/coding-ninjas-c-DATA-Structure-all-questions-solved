/*
INORDER , PREORDER AND POSTORDER
*/
#include<iostream>
#include<queue>
using namespace std;

template <typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<T> *right;
    BinaryTreeNode<T> *left;

    BinaryTreeNode(T data){
        this->data=data;
        right=NULL;
        left=NULL;
    }
};

void inorder(BinaryTreeNode<int> *root){
    if(root=NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
BinaryTreeNode<int> *takeInput(){
    int rootData;
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild,rightChild;

        cin>>leftChild;
        if(leftChild!=-1){
            BinaryTreeNode<int>* leftNode=new BinaryTreeNode<int>(leftChild);
            currentNode->left=leftNode;
            q.push(leftNode);
        }
        cin>>rightChild;
        if(rightChild!=-1)[
            BinaryTreeNode<int>* rightNode=new BinaryTreeNode<int>(rightChild);
            currentNode->right=rightNode;
            q.push(rightNode);
        ]
    }
    return root;
}

void preorder(BinaryTreeNode<int> *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(BinaryTreeNode<int> *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    BinaryTreeNode<int>* root=takeInput();
    preorder(root);

}
