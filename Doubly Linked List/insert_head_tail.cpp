#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define code() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

class Node
{
public:
    int value;
    Node *next;
    Node *prev;

    Node(int value)
    {
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

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

int size(Node* head)
{
    Node* temp = head;
    int count = 0;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
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

void insert_position(Node* head,int value,int pos)
{
    Node* newNode = new Node(value);
    Node* temp = head;

    for(int i=1; i<=pos-1; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    newNode->next->prev = newNode;
    newNode->prev = temp;
}

void insert_head(Node* &head,Node* &tail,int value)
{
    Node* newNode = new Node(value);
    
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    
}

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

int main()
{
    code();
    
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* tail = c;

    head->next = a;
    a->prev = head;
    a->next = b;
    b->prev = a;
    b->next = c;
    c->prev = b;

    int val,pos;
    cin>>val>>pos;

    if(pos == 0)
    {
        insert_head(head,tail,val);
    }
    else if(pos == size(head))
    {
        insert_tail(head,tail,val);
    }
    else if(pos >= size(head))
    {
        cout<<"Invalid Index"<<endl;
    }
    else
    {
        insert_position(head,val,pos);
    }

    print_normal(head);
    print_reverse(tail);

    return 0;
}
