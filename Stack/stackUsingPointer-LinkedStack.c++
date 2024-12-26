#include <iostream>
#include <string>
using namespace std;


template<class t>

class stack
{
        struct node
        {
            t item;
            node *next;
        };

        node *top, *cur;

    public:
        // stack():top Null{}
        stack()
        {
            top = nullptr;
        }

        void push(t newItem)
        {
            node *newItemPtr = new node;
            if (newItemPtr == nullptr)
            {
                cout << "Stack push cannot allocate memory";
            }else{
                newItemPtr->item  = newItem;
                newItemPtr->next = top;
                top = newItemPtr ;
                // cout << newItemPtr->item << endl;
            }
        }
        bool isEmpty()
        {
            return top == nullptr;
        }
        void pop()
        {
            if (isEmpty())
            {
                cout << "Stack empty on pop";
            }else{
                // node *temp = new node;
                // temp = top;  OR
                node *temp = top;
                top = top->next;
                temp = temp->next = nullptr;
                delete temp;
            }
        }
        void pop(t &stackTop)
        {
            if (isEmpty)
            {
                cout << "Stack empty on pop";
            }else{
                stackTop = top->item;
                node *temp = top;
                top = top->next;
                temp = temp->next = nullptr;
                delete temp;
            }
        }
        void getTop(t &stackTop)
        {
            if (isEmpty())
            {
                cout << "Stack empty on get top";
            }else{
                stackTop = top->item;
            }
        }
        void display()
        {
            if (isEmpty())
            {
                cout << "Stack empty on display";
            }else{
                cout << "[";
                cur = top;
                while (cur != nullptr)
                {
                    cout << cur->item << " ";
                    // cout << cur->item << " ";
                    cur = cur->next;
                }
                cout << "]";
            }
        }
};


int main()
{
    stack<int>s;
    s.push(100);
    s.push(200);
    s.pop();
    s.push(300);
    s.display();
    
    int y = 0;
    s.getTop(y);
    cout << y;
}