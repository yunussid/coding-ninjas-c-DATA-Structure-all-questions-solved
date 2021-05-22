/*
Code: Construct Tree from Preorder and Inorder

For a given preorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists.
You just need to construct the tree and return the root.
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
        BinaryTreeNode<int> *right;
        BinaryTreeNode<int> *left;
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

BinaryTreeNode<int>* buildTreeHelper(int *inorder,int *preorder,int inS,int inE,int preS,int preE){
    if(inS>inE){
        return NULL;
    }
    int rootData=preorder[preS];
    int rootIndex=-1;
    for(int i=inS;i<=inE;i++){
        if(inorder[i]==rootData){
            rootIndex=i;
            break;
        }
    }
    int lInS=inS;
    int lInE=rootIndex-1;
    int lPreS=preS+1;
    int lPreE=lInE-lInS+lPreS;
    int rPreS=lPreE+1;
    int rPreE=preE;
    int rInS=rootIndex+1;
    int rInE=inE;

    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(rootData);
    root->left=buildTreeHelper(inorder,preorder,lInS,lInE,lPreS,lPreE);
    root->right=buildTreeHelper(inorder,preorder,rInS,rInE,rPreS,rPreE);
    return root;
}
BinaryTreeNode<int>* buildTree(int *preorder,int preLength,int *inorder,int inLength){
    return buildTreeHelper(inorder,preorder,0,preLength-1,0,preLength-1);
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

int main(){
    int size;
    cin>>size;
    int *pre=new int[size];
    int *in=new int[size];
    for (int i = 0; i < size; i++) cin >> pre[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(pre, size, in, size);
    printLevelAtNewLine(root);
}
