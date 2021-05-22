/*
Structurally identical

Given two generic trees, return true if they are structurally identical. Otherwise return false.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;
    TreeNode(T data){
        this->data=data;
    }
    ~TreeNode(){
        for(int i=0;i<children.size();i++){
            delete children[i];
        }
    }
};

bool areIdentical(TreeNode<int> *root1,TreeNode<int> *root2){
    if(root1==NULL||root2==NULL){
        return 0;
    }
    if(root1->children.size()!=root2->children.size()){
        return 0;
    }
    for(int i=0;i<root1->children.size()&&i<root2->children.size();i++){
        if(root1->children[i]->data!=root2->children[i]->data){
            return 0;
        }
    }
    return 1;
}

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cin>>rootData;
    TreeNode<int>* root=new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

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
}

int main(){
    TreeNode<int>* root1 = takeInputLevelWise();
    TreeNode<int>* root2 = takeInputLevelWise();
    cout << (areIdentical(root1, root2) ? "true" : "false");
}
