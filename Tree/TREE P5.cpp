//MAX OF A TREE
#include<queue>
#include<vector>
#include<iostream>
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
TreeNode<int>* maxDataNode(TreeNode<int>* root){
 if(root==NULL){
  return NULL;
 }
 int max=root->data;
 TreeNode<int>* ans;
 TreeNode<int>* finalAns=root;
 for(int i=0;i<root->children.size();i++){
   ans=maxDataNode(root->children[i]);
   if(ans->data>max){
    max=ans->data;
    finalAns=ans;
   }
 }
 return finalAns;
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
      TreeNode<int>* child =  new TreeNode<int>(childData);
      front->children.push_back(child);
      pendingNodes.push(child);
     }
   }
   return root;
}
int main(){
 TreeNode<int>* root=takeInputLevelWise();
 TreeNode<int>* ans=maxDataNode(root);
 if(root!=NULL){
  cout<<ans->data;
 }
}
