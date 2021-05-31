/*
Print nodes at distance k from node
Send Feedback
You are given a Binary Tree of type integer, a target node, and an integer value K.
Print the data of all nodes that have a distance K from the target node. The order in which they would be printed will not matter.
*/
#include <iostream>
#include <queue>
using namespace std;

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

    ~BinaryTreeNode() {
    	if(left)
       		delete left;
    	if(right)
       		delete right;
    }
};

void print_depth(BinaryTreeNode<int> *root,int k)
{
    if(root == NULL)
        return;
    else if(k == 0)
        cout << root -> data << endl;

    print_depth(root -> left, k - 1);
    print_depth(root -> right, k - 1);
}
int helper(BinaryTreeNode<int> *root, int node, int k)
{
    if(root == NULL)
        return -1;
    if(root -> data == node)
    {
        print_depth(root,k);
        return 0;
    }
    int ld = helper(root -> left,node,k);
    if(ld != -1)
    {
        if(ld + 1 == k)
          cout << root -> data << endl;
        else
            print_depth(root -> right, k - ld - 2);
    }
    int rd = helper(root -> right, node, k);
    if(rd != -1)
    {
        if(rd + 1 == k)
          cout << root -> data << endl;
        else
            print_depth(root -> left,k - rd - 2);
    }
    if(rd == -1 && ld == -1)
        return -1;
    else
        return ld + rd + 2;

}
void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    int x = helper(root, node, k);
    if(x == NULL)
        return;
}

BinaryTreeNode<int>* takeInput() {
    int rootData;

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

        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}
