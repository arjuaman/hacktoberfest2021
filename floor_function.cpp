#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node *left,*right;
};
Node *insert(Node *root,int val){
    Node *newnode = new Node();
    if(root==NULL){
        newnode->data = val;
        newnode->left=newnode->right=NULL;
        return newnode;
    }
    if(root->data>val)
        root->left = insert(root->left,val);
    else if(root->data<val)
        root->right=insert(root->right,val);
    return root;
}
void inorder(Node *root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int floor(Node *root,int findmyfloor){
    if(root==NULL)
        return INT_MAX;
    if(root->data==findmyfloor)
        return root->data;
    else if(findmyfloor<root->data)
        return floor(root->left,findmyfloor);

    int res = floor(root->right,findmyfloor);

    return (res<findmyfloor)?res:root->data;
}
int ceil(Node *root,int key){
    if(root==NULL)
        return -1;
    if(root->data==key)
        return root->data;
    if(root->data<key)
        return ceil(root->right,key);
    int res = ceil(root->left,key);
    return (res>key)?res:root->data;
}
int main()
{
    Node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    inorder(root);
    cout<<endl;
//    root = deleteNode(root,20);
//    inorder(root);
    cout<<endl;
    int res = floor(root,82);
    cout<<res<<endl;
    int res2 = ceil(root,21);
    cout<<res2;
    return 0;
}
