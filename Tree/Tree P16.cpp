/*
Replace with depth
Send Feedback
You are given a generic tree. You have to replace each node with its depth value. You just have to update the data of each node, there is no need to return
or print anything
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<int>*>children;
    TreeNode(T data){
    this->data=data;
    }
  ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

void helper(TreeNode<int>* root,
            int depth)
{

    // Replace the node data with
    // it's depth
    root->data = depth;
    for (int i = 0;
         i < root->children.size(); i++) {

        helper(root->children[i], depth + 1);
    }
}
void replaceWithDepthValue(TreeNode<int>* root) {
    // Write your code here
        helper(root,0);

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
        int numNode;
        cin>>numNode;
        for(int i=0;i<numNode;i++){
            int childData;
            cin>>childData;
            TreeNode<int>* child=new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void printLevelATNewLine(TreeNode<int>* root) {
    queue<TreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        TreeNode<int>* first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        for (int i = 0; i < first->children.size(); i++) {
            q.push(first->children[i]);
        }
    }
}

int main(){
     TreeNode<int>* root = takeInputLevelWise();
    replaceWithDepthValue(root);
    printLevelATNewLine(root);
}
