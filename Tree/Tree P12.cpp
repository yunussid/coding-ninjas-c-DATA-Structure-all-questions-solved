/*
Node with maximum child sum

Given a generic tree, find and return the node for which sum of its data and data of all its child nodes is maximum. In the sum, data of the node and data
of its immediate child nodes has to be taken.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*>children;
    TreeNode(T data){
     this->data=data;
    }
    ~TreeNode(){
     for(int i=0;i<children.size();i++){
      delete children[i];
     }
    }
};

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cin>>rootData;
    TreeNode<int>* root=new TreeNode<int>(rootData);

    queue<TreeNode<int>*>pendingNodes;

    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        TreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin>>numChild;
        for(int i=0;i<numChild;i++){
            int childData;
            cin>>childData;
            TreeNode<int>* child=new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root){
    if(root==NULL){
        return root;
    }
    TreeNode<int>* max=root;
    int sum=root->data;
    for(int i=0;i<root->children.size();i++){
        sum +=root->children[i]->data;
    }
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>* tempNode=maxSumNode(root->children[i]);
        int tempsum=tempNode->data;
        for(int i=0;i<tempNode->children.size();i++){
            tempsum+=tempNode->children[i]->data;
        }
        if(tempsum>sum){
            sum=tempsum;
            max=tempNode;
        }
    }
    return max;
}

int main(){
    TreeNode<int>* root=takeInputLevelWise();

    TreeNode<int>* ans=maxSumNode(root);

    if(ans!=NULL){
        cout<<ans->data;
    }
}
