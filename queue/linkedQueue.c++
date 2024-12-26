#include <iostream>
#include <cassert>
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
            Node *newPtr = new Node;
                newPtr->item = element;
                newPtr->next = NULL;

            if (isEmpty())
            {
                rear = front = newPtr;
            }else{

                rear->next = newPtr;
                rear = newPtr;
            }
            length++;
            
        }

        void dequeue()
        {
            if (isEmpty())
            {
                cout << "Qeueue is empty";
            }else{
                Node *temp = front;
                if (front == rear)
                {
                    front = NULL;
                    rear = NULL;
                }else{
                    front = front->next;
                }
                temp->next = NULL;
                delete temp; // or free(temp) 
                length--;
            }
        }

        int getFront()
        {
            assert(!isEmpty());
            return front->item; 
        }

        int getRear()
        {
            assert(!isEmpty());
            return rear->item; 
        }

        int getSize()
        {
            return length; 
        }

        void display()
        {
            Node *cur = front;
            if (isEmpty())
            {
                cout << "Queue is empty";
            }else{
                cout << "[";
                while (cur != NULL)
                {
                    cout << cur->item << " ";
                    cur = cur->next;
                }
                cout << "]";
                
            }
            
        }
        void clear()
        {
            if (isEmpty())
            {
                cout << "Queue is empty";
            }else{
                Node *cur;
                while (front != NULL)
                {
                    cur = front;
                    front = front->next;
                    delete cur;
                }
                rear = NULL;
                length = 0;
                
            }
            
        }
};

int main()
{
    linkedQueue q1;
    q1.enqueue(11);
    q1.enqueue(22);
    // q1.dequeue();
    q1.enqueue(33);
    // // cout << q1.getFront() << endl;
    // // cout << q1.getRear() << endl;
    // // cout << q1.getSize() << endl; 
    q1.clear(); 
    q1.enqueue(333);
    q1.display(); 
    return 0;
}