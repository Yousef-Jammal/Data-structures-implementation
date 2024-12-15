#include <iostream>
using namespace std;
const int MAX_SIZE = 100;
template <class t>

class stack
{
        int top;
        t item[MAX_SIZE];
    public: 
        stack():top (-1){}

        void push(t element)
        {
            if (top >= MAX_SIZE -1)
            {
                cout << "Stack is full";
            }else{
                top++ ;
                item[top] = element;
            }
        }
        void pop()
        {
            if (isEmpty())
            {
                cout << "Stack is empty";
            }else{
                top-- ;
            }
        }
        void pop(t&Element)
        {
            if (isEmpty())
            {
                cout << "Stack is empty";
            }else{
                Element = item[top];
                top-- ;
            }
        }
        void getTop(t&StackTop)
        {
            if (isEmpty())
            {
                cout << "Stack is empty";
            }else{
                StackTop = item[top];
            }
        }
        bool isEmpty()
        {
            return top < 0;
        }
        void print()
        {
            cout << "[";
            for (int i = top ; i >= 0 ; i--)
            {
                cout << item[i] << " ";
            }
            cout << "]";
            cout << endl;
        }
};



int main()
{
    stack<char>s;
    s.push('a');
    s.push('a');
    s.push('a');
    s.push('a');
    s.pop();
    s.push('T');
    s.print();
    return 0;
}