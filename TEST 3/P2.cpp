/*
Longest Leaf to root path
Send Feedback
Given a binary tree, return the longest path from leaf to root. Longest means, a path which contain maximum number of nodes from leaf to root.
Input format :

Elements in level order form (separated by space)

(If any node does not have left or right child, take -1 in its place)

Line 1 : Binary Tree 1 (separated by space)
*/
#include <iostream>
#include <vector>
#include <queue>

template <typename T>
class BinaryTreeNode {
    public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;


BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
vector<int>* longestPath(BinaryTreeNode<int>* root) {
	// Write your code here
    if(root==NULL)
        return NULL;
    if(!root->left&&!root->right)
    {
        vector<int>* output=new vector<int>();
        output->push_back(root->data);
        return output;

    }
     vector<int>*leftans=longestPath(root->left);
         vector<int>*rightans=longestPath(root->right);
if(!leftans)
{
    rightans->push_back(root->data);
    return rightans;

}else if(!rightans)

{
    leftans->push_back(root->data);
    return leftans;
}

else{
    if(leftans->size()<rightans->size())
    {
        rightans->push_back(root->data);
        delete leftans;

        return rightans;

    }
    else{
       leftans->push_back(root->data);
        delete rightans;

        return leftans;
    }
}
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    vector<int> *output = longestPath(root);
    vector<int> :: iterator i = output -> begin();
    while(i != output -> end()) {
    	cout << *i << endl;
    	i++;
    }
}
