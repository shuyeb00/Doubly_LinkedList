#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define code() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

class Node
{
public:

    int value;
    Node *next;
    Node* prev;

    Node(int value)
    {
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};


void insert_tail(Node* &head,Node* &tail,int value)
{
    Node* newNode = new Node(value);

    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void print_normal(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout<<temp->value<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void print_reverse(Node* tail)
{
    Node* temp = tail;

    while(temp != NULL)
    {
        cout<<temp->value<<" ";
        temp = temp->prev;
    }
    cout<<endl;
}


int main()
{
    code();
    
    Node* head = NULL;
    Node* tail = NULL;

    while(1)
    {
        int val;
        cin>>val;

        if(val == -1) break;
        insert_tail(head,tail,val);
    }

    print_normal(head);
    print_reverse(tail);

    return 0;
}