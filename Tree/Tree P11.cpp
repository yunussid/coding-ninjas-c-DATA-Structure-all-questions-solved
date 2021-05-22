#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class TreeNode{
    public:
     T data;
     vector<TreeNode<int>*> children;
     TreeNode(T data){
     this->data=data;
     }
     ~TreeNode(){
      for(int i=0;i<children.size();i++){
       delete children[i];
      }
     }
};

int getLargeNodeCount(TreeNode<int>* root,int x){
    if(root==NULL){
    return 0;
    }
    int ans=0;
    if(root->data>x){
    ans=1;
    }
    for(int i=0;i<root->children.size();i++){
     ans+=getLargeNodeCount(root->children[i],x);
    }
    return ans;
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
    return root;
}
int main(){
    TreeNode<int>* root=takeInputLevelWise();
    int x;
    cin>>x;
    cout<<getLargeNodeCount(root,x);
}
