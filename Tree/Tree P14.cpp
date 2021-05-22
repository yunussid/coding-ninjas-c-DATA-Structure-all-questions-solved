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

TreeNode<int>* getNextLargerElement(TreeNode<int> *root,int n){
    if(root==NULL){
        return NULL;
    }
    TreeNode<int>* ans=NULL;

    if(root->data>n){
        ans=root;
    }
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>* temp=getNextLargerElement(root->children[i],n);
        if(ans==NULL){
            ans=temp;
        }
        if(temp!=NULL&&temp->data<ans->data){
            ans=temp;
        }
        return ans;
    }
}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
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
    TreeNode<int>*ans=getNextLargerElement(root,x);

    if(ans!=NULL){
        cout<<ans->data;
    }
}
