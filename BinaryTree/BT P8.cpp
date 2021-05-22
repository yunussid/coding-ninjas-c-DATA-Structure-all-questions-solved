/*
Construct Tree from Postorder and Inorder
Send Feedback
For a given postorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists.
You just need to construct the tree and return the root.
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
    while(!q.empty()){
        BinaryTreeNode<int> *currentNode=q.front();
        q.pop();
        int leftChild,rightChild;
        cin>>leftChild;
        if(leftChild!=-1){
            BinaryTreeNode<int> *leftNode=new BinaryTreeNode<int>(leftChild);
            currentNode->left=leftNode;
            q.push(leftNode);
        }
        cin>>rightChild;
        if(rightChild!=-1){
            BinaryTreeNode<int> *rightNode=new BinaryTreeNode<int>(rightChild);
            currentNode->right=rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelAtNewLine(BinaryTreeNode<int> *root){
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        BinaryTreeNode<int> *first=q.front();
        q.pop();
        if(first==NULL){
            if(q.empty()){
                break;
            }
            cout<<endl;
            q.push(NULL);
            continue;
        }
        cout<<first->data<<" ";
        if(first->left!=NULL){
            q.push(first->left);
        }
        if(first->right!=NULL){
            q.push(first->right);
        }
    }
}

BinaryTreeNode<int>* buildTreeHelper(int *in,int *post,int inS,int inE,int postS,int postE){
    if(inS>inE){
        return NULL;
    }
    int rootData=post[postE];
    int rootIndex=-1;
    for(int i=inS;i<=inE;i++){
        if(in[i]==rootData){
            rootIndex=i;
            break;
        }
    }
    int lInS=inS;
    int lInE=rootIndex-1;
    int lPostS=postS;
    int lPostE=lInE-lInS+lPostS;
    int rPostE=postE-1;
    int rInS=rootIndex+1;
    int rInE=inE;
    int rPostS=lPostE+1;
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(rootData);
    root->left=buildTreeHelper(in,post,lInS,lInE,lPostS,lPostE);
    root->right=buildTreeHelper(in,post,rInS,rInE,rPostS,rPostE);
    return root;
}
BinaryTreeNode<int>* buildTree(int *postorder,int postLength,int *inorder,int inLength){
    return buildTreeHelper(inorder,postorder,0,postLength-1,0,postLength-1);
}

int main(){
    int size;
    cin>>size;
    int *post=new int[size];
    int *in=new int[size];
    for(int i=0;i<size;i++){
        cin>>post[i];
    }
    for(int i=0;i<size;i++){
        cin>>in[i];
    }
    BinaryTreeNode<int> *root=buildTree(post,size,in,size);
    printLevelAtNewLine(root);
}
