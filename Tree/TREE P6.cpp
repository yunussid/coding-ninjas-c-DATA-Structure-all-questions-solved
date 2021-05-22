//HEIGHT OF TREE
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

template<typename T>
class TreeNode{
  public:
   T data;
   vector<TreeNode<T>*> children;
   TreeNode(T data){
    this->data=data;
   }
};
int getHeight(TreeNode<int>* root){
 if(root==NULL){
  return 0;
 }
 int ans=0;
 for(int j=0;j<root->children.size();j++){
  int t=getHeight(root->children[j]);
  ans=max(t,ans);
 }
 return 1+ans;
}
TreeNode<int>* takeInputLevelWise(){
 int rootData;
 cin>>rootData;
 TreeNode<int>* root = new TreeNode<int>(rootData);

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
  cout<<getHeight(root)<<endl;
}
