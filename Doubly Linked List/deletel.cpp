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

void delete_position(Node* head,int pos)
{
    Node* temp = head;
    
    for(int i=1; i<pos-1; i++)
    {
        temp = temp->next;
    }

    Node* deleteNode = temp->next;
    temp->next = temp->next->next;
    temp->next->prev = temp;

    delete deleteNode;

}

void delete_tail(Node* &tail)
{
    Node* deleteNode = tail;
    tail = tail->prev;

    delete deleteNode;

    tail->next = NULL;
}

void delete_head(Node* &head)
{
    Node* deleteNode = head;

    head = head->next;
    delete deleteNode;
    head->prev = NULL;
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

    int pos; cin>>pos;

    print_normal(head);

    if(pos >= size(head)) cout<<"Invalid"<<endl;
    else if(pos == size(head)) delete_tail(tail);
    else if(pos == 1 or pos == 0) delete_head(head);
    else delete_position(head,pos);
  
    print_normal(head);

    print_reverse(tail);

    return 0;
}
