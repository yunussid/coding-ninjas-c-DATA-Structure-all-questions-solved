//print level wise
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

template <typename T>
class TreeNode{
  public:
   T data;
   vector<TreeNode<int>*> children;

   TreeNode(T data){
    this->data=data;
   }
};

TreeNode<int>* takeInputLevelWise(){
   int rootData;
   cout<<"Enter root Data"<<endl;
   cin>>rootData;
   TreeNode<int>* root=new TreeNode<int>(rootData);
   queue<TreeNode<int>*> pendingNodes;
   pendingNodes.push(root);
   while(pendingNodes.size()!=0){
    TreeNode<int>* front=pendingNodes.front();
    pendingNodes.pop();
    cout<<"Enter number of children"<<front->data<<endl;
    int numChild;
    cin>>numChild;
    for(int i=0;i<numChild;i++){
      int childData;
      cout<<"Enter"<<i<<"th child of"<<front->data<<endl;
      cin>>childData;
      TreeNode<int>* child=new TreeNode<int>(childData);
      front->children.push_back(child);
      pendingNodes.push(child);
    }
   }
   return root;
}

void printLevelWise(TreeNode<int>* root){
   if(root==NULL){
    return;
   }
   queue<TreeNode<int>*> pending_children;
   pending_children.push(root);

   while(!pending_children.empty()){
    TreeNode<int>*parent = pending_children.front();
        pending_children.pop();
        cout << parent->data << ":";

        for (int i = 0; i < parent->children.size(); i++)
        {
           // TreeNode<int>*child = new TreeNode<int>(parent->children[i]->data);
            cout << parent->children[i]->data;

            pending_children.push(parent->children[i]);

            if(i < parent->children.size() - 1)
            {
                cout << ",";
            }
        }
        cout << endl;
   }
}

int main(){
    TreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
}
