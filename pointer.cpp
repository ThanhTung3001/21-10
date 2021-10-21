#include<iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Queue
{
    Node *head;
    Node *tail;
    Node *prev;
    Node *temp;
    bool isEmpty()
    {
        return head == NULL;
    }
public:
    Queue()
    {
        head = NULL;
        tail = NULL;
    }

    void enqueue(int x)
    {
        temp = new Node;
        temp->data = x;
        temp->next = NULL;
        if(isEmpty())
        {
            head = temp;
            tail = temp;
        }
        else
        {
            prev = tail;
            tail->next = temp;
            tail = temp;
        }
    }

    void dequeue()
    {
        temp = head;
        head = head->next;
        delete temp;
    }

    void find(int x)
    {
        int i;
        for(i=1, temp = head;temp->next != NULL && temp->data != x;temp = temp->next, i++);
        if(temp->data == x)
        {
            cout << "Found at position:" << i << endl;
        }
        else if(temp->next == NULL)
        {
            cout << "Error: Number Not found..." << endl;
        }
    }

    void display()
    {
        if(!isEmpty())
        {
            for(temp = head; temp != NULL; temp=temp->next)
                cout << temp->data << " ";
            cout << endl;
        }
        else
        {
            cout << "Queue is Empty!" << endl;
        }
    }
};

int main()
{
    Queue q;
    q.display();
    q.enqueue(15);
    q.display();
    q.enqueue(25);
    q.display();
    q.enqueue(35);
    q.display();
    q.enqueue(45);
    q.display();
    q.find(15);
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
}
