#include <iostream>

using namespace std;


class Node
{
public:
    Node(int d)
    {
        data = d;
        link = NULL;
    }
    int data;
    Node *link;

};

class Queue
{
public:
    Node *Rear;
    Node *Front;
    Queue()
    {
        Rear = Front = NULL;
    }
    void Enqueue(int data)
    {
        Node *newNode = new Node(data);
        if (Rear == NULL)
        {
            Front = Rear = newNode;
        }
        else
        {
            Rear->link = newNode;
            Rear = newNode;
        }
    }
    void Dequeue()
    {
        Node *newNode;
        if (Front == NULL)
        {
            cout<<"Queue is Empty\n";
        }
        else
        {
            newNode = Front;
            Front = Front->link;
            if(Front == NULL)
            {
                Rear = NULL;
            }
            delete(newNode);
        }
    }
    void display()
    {
        Node *current = Front;
        int i=1;
        if(Front == NULL)
        {
            cout<<"The Queue is Empty!\n";
        }
        else
        {
            while(current != NULL)
            {
                cout<<"The Value of the index "<<i<<" of the Queue is: "<<current->data<<endl;
                current = current->link;
                i++;
            }
        }
    }

};

int main()
{
    Queue q;
    q.Enqueue(5);
    q.Enqueue(10);
    q.Enqueue(15);
    q.Enqueue(20);
    q.display();
    cout<<endl;
    q.Dequeue();
    q.Dequeue();
    q.display();

//    cout << "Hello world!" << endl;
    return 0;
}
