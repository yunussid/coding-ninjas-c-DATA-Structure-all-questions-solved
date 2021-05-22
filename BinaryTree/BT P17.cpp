/*
ZigZag tree
Send Feedback
Given a binary tree, print the zig zag order. In zigzag order, level 1 is printed from left to right, level 2 from right to left and so on. This means odd
levels should get printed from left to right and even level right to left.
*/
#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;


BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
#include<stack>
void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL){
        return;
    }
    stack <BinaryTreeNode<int> *> currentlevel;
    stack <BinaryTreeNode<int> *> nextlevel;
    currentlevel.push(root);
    bool lefttoright=1;
    while(!currentlevel.empty()){
        BinaryTreeNode<int> *temp=currentlevel.top();
        currentlevel.pop();
        if(temp!=NULL){
            cout<<temp->data<<" ";
        }
        if(lefttoright){
            if(temp->left)
                nextlevel.push(temp->left);
            if(temp->right)
                nextlevel.push(temp->right);
        }else {
            if(temp->right)

                nextlevel.push(temp->right);
            if(temp->left){
                nextlevel.push(temp->left);
            }
        }
        if(currentlevel.empty()){
            lefttoright = !lefttoright;
            swap(currentlevel , nextlevel);
            cout<<endl;
        }
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    zigZagOrder(root);
}
