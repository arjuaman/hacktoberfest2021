#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node *left,*right;
    int height;
};
int height(Node *n){
    if(n==NULL)
        return 0;
    return n->height;
}
Node *newNode(int key){
    Node *node = new Node();
    node->data=key;
    node->left=node->right=NULL;
    node->height=1;
    return (node);
}
Node *rightRotate(Node *y){
    Node *x = y->left;
    Node *t2 = x->right;
    x->right=y;
    y->left=t2;
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;
    return x;
}
Node *leftRotate(Node *root){
    Node *y = root->right;
    Node *L = y->left;
    y->left = root;
    root->right = L;
    root->height = max(height(root->left),height(root->right))+1;
    y->height = max(height(y->left),height(y->right))+1;
    return y;
}
int getBalance(Node *n){ //get balance factor of node n
    if(n==NULL)
        return 0;
    return height(n->left)-height(n->right);
}
Node *insert(Node *root,int val){
    //Step 1: normal insertion like bst
    if(root==NULL)
        return newNode(val);
    if(val<root->data)
        root->left = insert(root->left,val);
    else if(root->data<val)
        root->right = insert(root->right,val);
    else
        return root;
    //Step 2: update height after insertion
    root->height = 1+ max(height(root->left),height(root->right));
    //Step 3: get the balance factor
    int balance = getBalance(root);
    //there are 4 cases for unbalanced
    if(balance>1 && val < root->left->data)
        return rightRotate(root);
    if(balance<-1 && val > root->right->data)
        return leftRotate(root);
    if(balance>1 && val > root->left->data){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance<-1 && val<root->right->data){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
void preorder(Node *root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    Node *root = NULL;
    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,30);
    root = insert(root,40);
    root = insert(root,50);
    root = insert(root,25);
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    preorder(root);
    return 0;
}
