/*
Remove Leaf nodes

Given a binary tree, remove all leaf nodes from it. Leaf nodes are those nodes, which don't have any children.
*/
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
        left=NULL;
        right=NULL;
    }
};

BinaryTreeNode<int>* takeInput(){
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
BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        return NULL;
    }
    root->left=removeLeafNodes(root->left);
    root->right=removeLeafNodes(root->right);

    return root;
}
void printLevelAtNewLine(BinaryTreeNode<int>* root){
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    q.push(NULL);
    while(q.empty()){
        BinaryTreeNode<int>* first=q.front();
        q.pop();
        if(first==NULL){
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
         cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    root = removeLeafNodes(root);
    printLevelAtNewLine(root);
}
