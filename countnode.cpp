#include <iostream>
#include "treenodeclass.h"
#include<queue>
using namespace std;
TreeNode<int> *takeinputlevelwise()
{
    int rootData;
    cout << "enter the data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "enter the num of chilren of" << front->data << endl;
        int numchild;
        cin >> numchild;

        for (int i = 0; i < numchild; i++)
        {
            int childData;
            cout << "enter" << i << "ith child of " << front->data << endl;
            cin >> childData;

            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
/*
TreeNode<int> *takeinput()
{
    int rootData;
    cout << "enter the data" << endl;
    cin >> rootData;

    TreeNode<int> *root = new TreeNode<int>(rootData);

    int n;
    cout << "enter the num of children of " << rootData << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeinput();
        root->children.push_back(child);
    }
    return root;
}
*/

void printtree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " : ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << " ,";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printtree(root->children[i]);
    }
}

int numNodes(TreeNode<int>* root){
    int ans = 1;
    for(int i = 0 ; i< root->children.size() ; i++){
        ans += numNodes(root->children[i]);
    }
    return ans;
}
void printatlevelk(TreeNode<int> *root , int k){
    if(k == 0){
        cout << root -> data << endl;
        return ;
    }
    for(int i =0 ; i< root -> children.size() ; i++){
        printatlevelk(root->children[i] , k-1);
    }

}
int getleafnodecount(TreeNode<int> *root){
    if(root == NULL){
        return 0;
    }
    int childcount = root ->children.size();
    if(childcount == 0){
        return 1;
    }
    int result = 0;
    for(int i =0 ; i< childcount ; i++){
        result += getleafnodecount(root -> children[i]);
        return result;
    }
}

// pre order traverse
void preorder(TreeNode<int> *root){
    cout << root -> data << ' ';
    for(int i =0 ; i< root -> children.size();i++){
        preorder(root->children[i]);
    }
}

// post order traverse

void postorder(TreeNode<int> *root){
    if(root == NULL){
        return ;
    }
    int result = root -> data;
     int childcount = root -> children.size();
    for(int i =0 ; i< childcount ; i++){
        postorder(root->children[i]);
        cout << root -> data << ' ';
    }
}

// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main()
{
    //  TreeNode<int> *root = new TreeNode<int>(1);
    // TreeNode<int> *node1 = new TreeNode<int>(2);
    // TreeNode<int> *node2 = new TreeNode<int>(3);

    // root -> children.push_back(node1);
    // root -> children.push_back(node2);
    TreeNode<int> *root = takeinputlevelwise();
    printtree(root);

    cout << "=========  counting the NODES =========" << endl;
    cout << numNodes(root) << endl;

    cout << "Level 2 : " << endl;
    printatlevelk(root , 2);
 
    cout << getleafnodecount(root) << endl;

    cout << "========= preorder traverse =======" << endl;

    preorder(root);
 
 cout << "======== postorder traverse =====" << endl;

    postorder(root);

    delete root;


    return 0;
}