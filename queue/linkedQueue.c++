#include <iostream>
using namespace std;

class linkedQueue
{
    struct Node
    {
        int item;
        Node *next;
    };

    Node *front;
    Node *rear;
    int length;
    
    public:
        linkedQueue()
        {
            front = rear = NULL;
            length = 0;
        }

        bool isEmpty()
        {
            return length == 0;
        }

        void enqueue(int element)
        {
            if (isEmpty())
            {
                front = new Node;
                front->item = element;
                front->next = NULL;
                rear = front;
            }else{
                Node *newPtr = new Node;
                newPtr->item = element;
                newPtr->next = NULL;
                rear->next = newPtr;
                rear = newPtr;
            }
            length++;
            
        }
};

