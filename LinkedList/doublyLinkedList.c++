#include <iostream>
using namespace std;

class doublyLinkedList
{
    struct Node
    {
        int item;
        Node *next;
        Node *prev;
    };

    Node *first;
    Node *last;
    int length;
    public:
        doublyLinkedList()
        {
            first = last = NULL;
            length = 0;
        }
        bool isEmpty()
        {
            return first == NULL;
        }
    
        void insertFirst(int element)
        {
            Node *newNode = new Node;
            newNode->item = element;
            if(length == 0){
                newNode->next = newNode->prev = NULL;
                first = last = newNode;
            }else{
                newNode->next = first;
                newNode->prev = NULL;
                first->prev = newNode;
                first = newNode;
            }
                length++;
        }

        void insertEnd(int element)
        {
            Node *newNode = new Node;
            newNode->item = element;
            if(length == 0){
                newNode->next = newNode->prev = NULL;
                first = last = newNode;
            }else{
                newNode->next = NULL;
                newNode->prev = last;
                last->next = newNode;
                last = newNode;
            }
            length++;
        }
        
        void insertAt(int pos,int element)
        {
            if (pos < 0 || pos > length)
            {
                cout << "Out of range";
            }else if(pos == 0){
                insertFirst(element);
            }else if(pos == length){
                insertEnd(element);
            }else{
                Node *cur;
                cur = first;
                for (size_t i = 1; i < pos; i++)
                {
                    cur = cur->next;
                }

                Node *newNode = new Node;
                newNode->next = cur->next;
                newNode->prev = cur;
                cur->next->prev = newNode;
                cur->next = newNode;
                length++;
            }
        }


        // Removing
        void removeFirst(int element)
        {
            if(length == 0){
                cout << "Empty list";
            }else {
                if(length == 1){
                    delete first;
                    first = last = NULL;
                }else{
                    Node *cur = first;
                    first = first->next;
                    first->prev = NULL;
                    delete cur;
                }
                length--;
            }
        }
        void removeEnd(int element)
        {
            if(length == 0){
                cout << "Empty list";
            }else {
                if(length == 1){
                    delete first;
                    first = last = NULL;
                }else{
                    Node *cur = last;
                    last = last->prev;
                    last->next = NULL;
                    delete cur;
                }
                length--;
            }
        }
        void removeAt(int pos, int element)
        {
            if(length == 0){
                cout << "Empty list";
            }else if(pos < 0 || pos > length){
                cout << "Out of range";
            }
            
            else {
                if(length == 1){
                    delete first;
                    first = last = NULL;
                }else{
                    Node *cur = last;
                    last = last->prev;
                    last->next = NULL;
                    delete cur;
                }
                length--;
            }
        }
};



int main() {
    return 0;
}