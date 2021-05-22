/*
Level order traversal

For a given a Binary Tree of type integer, print it in a level order fashion where each level will be printed on a new line. Elements on every level will be
printed in a linear fashion and a single space will separate them.
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

void printLevelWise(BinaryTreeNode<int> *root){
    if(root==NULL){
        return;
    }
    // Create an empty queue for level order tarversal
    queue<BinaryTreeNode<int>*> q;

    // Enqueue Root and initialize height
    q.push(root);

    while (q.empty() == false)
    {
        // nodeCount (queue size) indicates number
        // of nodes at current lelvel.
        int nodeCount = q.size();

        // Dequeue all nodes of current level and
        // Enqueue all nodes of next level
        while (nodeCount > 0)
        {
            BinaryTreeNode<int> *node = q.front();
            cout << node->data << " ";
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            nodeCount--;
        }
        cout << endl;
    }
}

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
};

int main(){
    BinaryTreeNode<int>* root=takeInput();
    printLevelWise(root);
}
