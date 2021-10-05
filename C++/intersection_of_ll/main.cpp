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
Node* intersection(Node *first,Node *second){
    Node *temp = first;
    Node *dummy = NULL;
    Node *res = NULL;
    if(first==NULL)
        return dummy;
    if(second==NULL)
        return dummy;
    dummy = second;
    while(temp!=NULL){
        while(dummy!=NULL){
            if(dummy->data == temp->data){
                push(&res,dummy->data);
                //res = res->next;
            }
            dummy=dummy->next;
        }
        temp=temp->next;
    }
    //display(res);
    return res;
}
Node* sorted_intersect(Node *a, Node *b){    // 1 2a 3 4 5 6     2b 4 6 8 10 12
    if(a==NULL || b==NULL)
        return NULL;
    if(a->data < b->data)
        return sorted_intersect(a->next,b);
    if(a->data > b->data)
        return sorted_intersect(a,b->next);
    Node *temp = NULL;
    temp->data = a->data;
    //push(&temp,temp->data);
    temp->next = sorted_intersect(a->next,b->next);

    return temp;
}
int main()
{
    Node *head = NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);
    push(&head,5);
    push(&head,6);
    display(head);
    Node *second = NULL;
    push(&second,2);
    push(&second,4);
    push(&second,6);
    push(&second,8);
    push(&second,10);
    push(&second,12);
    display(second);
    cout<<"\nIntersection: ";
    //Node* intersection(Node *first,Node *second)
    Node *dummy = NULL;
    //dummy = sorted_intersect(head,second);
    dummy = intersection(head,second);
    display(dummy);
    return 0;
}
