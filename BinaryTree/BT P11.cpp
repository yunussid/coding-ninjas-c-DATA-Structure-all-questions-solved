/*
Min and Max of Binary Tree
Send Feedback
For a given a Binary Tree of type integer, find and return the minimum and the maximum data values.
Return the output as an object of Pair class, which is already created.
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

pair<int,int>getMinAndMax(BinaryTreeNode<int> *root){
    int l=root->data;
    int s=root->data;
    if(root->left!=NULL){
        pair<int,int> p = getMinAndMax(root->left);
        if(p.second>l){
            l=p.second;
        }
        if(p.first<s){
            s=p.first;
        }
    }
    if(root->right!=NULL){
        pair<int,int> p=getMinAndMax(root->right);
        if(p.second>l){
            l=p.second;
        }
        if(p.first<s){
            s=p.first;
        }
    }
    pair<int,int> x;
    x.second=l;
    x.first=s;
    return x;
}

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
        int leftData,rightData;
        cin>>leftData;
        if(leftData!=-1){
            BinaryTreeNode<int> *leftNode=new BinaryTreeNode<int>(leftData);
            front->left=leftNode;
            q.push(leftNode);
        }
        cin>>rightData;
        if(rightData!=-1){
            BinaryTreeNode<int> *rightNode=new BinaryTreeNode<int>(rightData);
            front->right=rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main(){
    BinaryTreeNode<int>* root=takeInput();
    pair<int,int>ans=getMinAndMax(root);
    cout<<ans.first<<" "<<ans.second;
}
