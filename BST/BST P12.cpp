/*
Pair Sum Binary Tree
Send Feedback
Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.
*/
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
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

void convertToArray(BinaryTreeNode<int> *root,vector<int> &output){
    if(root==NULL){
        return;
    }
    output.push_back(root->data);
    convertToArray(root->left,output);
    convertToArray(root->right,output);
}
void pairSum(BinaryTreeNode<int> *root,int sum){
    vector<int> output;
    convertToArray(root,output);

    sort(output.begin(),output.end());

    int i=0,j=output.size()-1;
    while(i<j){
        if(output[i]+output[j]==sum){
            cout<<output[i]<<" "<<output[j]<<"\n";
            i++;
            j--;
        }else if(output[i]+output[j]>sum){
            j--;
        }else if(output[i]+output[j]<sum){
            i++;
        }
    }
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
        int leftChild,rightChild;
        cin>>leftChild;
        if(leftChild!=-1){
            BinaryTreeNode<int> *leftNode=new BinaryTreeNode<int>(leftChild);
            q.push(leftNode);
            front->left=leftNode;
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

int main(){
    BinaryTreeNode<int>* root=takeInput();
    int sum;
    cin>>sum;
    pairSum(root,sum);
    delete root;
}
