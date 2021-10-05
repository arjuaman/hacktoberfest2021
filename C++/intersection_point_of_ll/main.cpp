#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
};
void display(Node *n){
    if(n==NULL){
        return;
    }
    cout<<endl;
    while(n!=NULL){
        cout<<n->data<<" ";
        n=n->next;
    }
}
void push(Node **n,int value){
    Node *new_node = new Node();
    new_node->data = value;
    new_node->next = (*n);
    (*n) = new_node;
}
int getLength(Node *n){
    if(n==NULL)
        return 0;
    return 1 + getLength(n->next);
}
int getIntersectionNode(Node *first,Node *second){
    int len1 = getLength(first);
    int len2 = getLength(second);
    int diff = (len1>len2)?(len1-len2):(len2-len1);
    int bcount = 0;
    Node *one = second;
    Node *two = first;
    //let 2nd is bigger
    while(diff!=bcount){
        one = one->next;
        bcount++;
    }
    while(one!=NULL && two!=NULL){
        if(one==two){
            return one->data;
        }
        one = one->next;
        two = two->next;
    }
}
int main()
{
    Node *head = NULL;
    Node *head1 = new Node();
    head1->data=10;

    Node *head2 = new Node();
    head1->data=3;

    Node *newNode = new Node();
    newNode->data = 6;
    head2->next=newNode;

    newNode = new Node();
    newNode->data = 9;
    head2->next->next=newNode;

    newNode = new Node();
    newNode->data = 15;
    head1->next=newNode;
    head2->next->next->next=newNode;

    newNode = new Node();
    newNode->data = 30;
    head1->next->next=newNode;

    head1->next->next->next=NULL;

    display(head1);
    display(head2);

    cout<<"\nIntersection point: "<<getIntersectionNode(head1,head2);


    return 0;
}
