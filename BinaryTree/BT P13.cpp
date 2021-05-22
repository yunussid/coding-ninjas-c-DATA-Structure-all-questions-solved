/*
Check Balanced

Given a binary tree, check if it is balanced. Return true if given binary tree is balanced, false otherwise.
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

pair<int,int> isBalancedHelper(BinaryTreeNode<int> *root){
    if(root==NULL){
        pair<int,int>p;
        // p.first=0; mistake
        p.first = 1;
        p.second=0;
        // u did not return it
        return p;
    }
    pair<int,int> leftAns=isBalancedHelper(root->left);
    pair<int,int> rightAns=isBalancedHelper(root->right);
    int lb=leftAns.first;
    int lh=leftAns.second;
    int rb=rightAns.first;
    int rh=rightAns.second;

    int height=1+ max(lh,rh);
    int isBalanced=0;
    if(lb==0 || rb==0){
        isBalanced=0;
    }else if(lb==1 && rb==1){
        if(lh-rh>1 || rh-lh>1){
            isBalanced=0;
        }else{
            isBalanced=1;
        }
    }

    pair<int,int>p;
    p.first=isBalanced;
    p.second=height;
    // return p.first; Mistake, return pair itself
    return p;
}

bool isBalanced(BinaryTreeNode<int> *root) {
	// Write your code here
    pair<int,int> ans = isBalancedHelper(root);
    bool a;
    if(ans.first == 1){
        a = true;
    } else {
        a = false;
    }
    return a;

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
    cout<<(isBalanced(root)?"true":"false");
}
