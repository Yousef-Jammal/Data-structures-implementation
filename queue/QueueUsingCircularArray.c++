#include <iostream>
#include <cassert>
using namespace std;

// const int MAX_LENGTH = 100;
template<class t>

class arrayQueueType
{
        int rear;
        int front;
        int length;
        // t arr[MAX_LENGTH];
        t *arr;
        int maxSize;

    public:

        arrayQueueType(int size){
            if(size <= 0){
                maxSize = 100;
            }else{
                maxSize = size;
            }
            front = 0;
            rear = maxSize -1 ;
            length = 0;
            arr = new t[maxSize];        
        }

        int isEmpty()
        {
            return length == 0;
        }
        int isFull()
        {
            return length == maxSize;
        }
        void enqueue(t Element)
        {
            if (isFull())
            {
                cout << "Queue is full";
            }else{
                rear = (rear + 1) % maxSize;
                arr[rear] = Element;
                length++;
            }
        }
        void dequeue(t &Element)
        {
            if (isEmpty())
            {
                cout << "Queue is empty";
            }else{
                Element = arr[front];
                front = (front + 1) % maxSize;
                length--;
            }
        }
        int getLength()
        {
            return length;
        }
        void dequeue()
        {
            if (isEmpty())
            {
                cout << "Queue is empty";
            }else{
                front = (front + 1) % maxSize;
                length--;
            }
        }
        int peek()
        {
            assert(!isEmpty());
            return arr[front];
        }
        int getRear()
        {
            assert(!isEmpty());
            return arr[rear];
        }
        void print()
        {
            if (isEmpty())
            {
                cout << "Queue is empty";
            }else{
                cout << "[";
                for (size_t i = front; i != rear ; i = (i + 1) % maxSize)
                {
                    cout << arr[i] << " ";
                }
                cout << arr[rear] << " ";
                cout << "]";
            }
        }

        int search(t element)
        {
            int pos = -1;
            if (!isEmpty())
            {
                for (size_t i = front; i != rear ; i = (i + 1) % maxSize)
                {
                    if (arr[i] == element)
                    {
                        pos = i;
                        break;
                    }
                    
                }
                if (pos == -1)
                {
                    if (arr[rear] == element)
                    {
                        pos = rear;
                    }
                    
                }
                
                
            }else{
                cout << "Queue is empty" << endl;
            }
            return pos;
        }
};


int main() {
    arrayQueueType<char>q(5);
    q.enqueue('1');
    q.enqueue('2');
    q.enqueue('3');
    q.enqueue('4');
    q.enqueue('5');
    q.enqueue('6');
    q.enqueue('7');
    q.dequeue();
    q.dequeue();
    q.print();
    cout << endl;
    cout << q.search('3');
    // cout << q.peek();
    // cout << q.getRear();
    return 0;

}