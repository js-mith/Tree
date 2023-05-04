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

int main()
{
    //  TreeNode<int> *root = new TreeNode<int>(1);
    // TreeNode<int> *node1 = new TreeNode<int>(2);
    // TreeNode<int> *node2 = new TreeNode<int>(3);

    // root -> children.push_back(node1);
    // root -> children.push_back(node2);
    TreeNode<int> *root = takeinputlevelwise();
    printtree(root);
    return 0;
}