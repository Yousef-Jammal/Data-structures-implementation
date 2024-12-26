#include <iostream>
using namespace std;

class linkedList
{
    struct Node
    {
        int item;
        Node *next;
    };

    Node *head;
    Node *tail;
    int length;
    public:
        linkedList()
        {
            head = tail = NULL;
            length = 0;
        }

        bool isEmpty()
        {
            return length == 0;
        }

        void insertFirst(int element)
        {
            Node *newNodePtr = new Node;
            newNodePtr->item = element;
            if (length == 0)
            {
                head = tail = newNodePtr;
                newNodePtr->next = NULL;
            }else{
                newNodePtr->next = head;
                head = newNodePtr;
            }
            length++;
        }
        
        void insertEnd(int element)
        {
            Node *newNodePtr = new Node;
            newNodePtr->item = element;
            if (length == 0)
            {
                head = tail = newNodePtr;
                newNodePtr->next = NULL;
            }else{
                tail->next = newNodePtr;
                newNodePtr->next = NULL;
                tail = newNodePtr;
            }
            length++;
        }


        void insertAtPos(int pos, int element)
        {
            if(pos < 0 || pos > length){
                cout << "Out of range";
            }else if(pos == 0 ){
                insertFirst(element);
            }else if(pos == length){
                insertEnd(element);
            }else{
                Node *newNodePtr = new Node;
                newNodePtr->item = element;
                Node *cur =  head;
                for (size_t i = 0; i < (pos - 1); i++)
                {
                    cur = cur->next;
                }
                newNodePtr->next = cur->next;
                cur->next = newNodePtr;
                
            }
        }

        void print()
        {
            if (length == 0)
            {
                cout << "No element to show";
            }else{
                Node *cur = head;
                cout << "[";
                // for (size_t i = 0; i < length; i++)
                // {
                //     cout << cur->item << endl;
                //     cur = cur->next
                // }
                while (cur != NULL)
                {
                    cout << cur->item << " ";
                    cur = cur->next ;
                }
                
                cout << "]" << endl;
                
            }
            
        }

        void removeFirst()
        {
            if (isEmpty())
            {
                cout << "Linked list is empty";
            }else{
                if(length = 1){
                    delete head;
                    head = tail = NULL;
                }else{
                    Node *cur = head;
                    head = head->next;
                    delete cur;
                }
                length--;
            } 
        }
        
        void removeEnd()
        {
            if (isEmpty())
            {
                cout << "Linked list is empty";
            }else if(length = 1){
                removeFirst();
            }else{
                Node *cur = head->next;
                Node *prev = head;
                while (cur != tail)
                {
                    prev = cur;
                    cur = cur->next;
                }
                delete cur;
                prev->next = NULL;
                head = prev;
                length--;
            }
        }

        void remove(int element)
        {
            if (isEmpty())
            {
                cout << "Empty list can't remove";
                return;
            }

            if (head->item == element)
            {
                removeFirst();
            }else{
                Node *cur, *prev;
                cur = head->next;
                prev = head;
                while (cur != NULL)
                {
                    if (cur->item == element)
                    {
                        break;
                    }
                    prev = cur;
                    cur = cur->next;
                }

                if (cur == NULL)
                {
                    cout << "The element no found";
                }else{
                    prev->next = cur->next;
                    if (tail == cur) //delete the tail item
                        tail = prev;
                    delete cur;
                    length--;
                }
                
                
            }
        }

        void reverse()
        {
            Node *prev, *cur, *next;
            prev = NULL;
            cur = head;
            next = cur->next;
            
            while (next != NULL)
            {
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            head = prev;
        }
    
};



int main() {
    linkedList l1;
    l1.insertFirst(11);
    l1.insertFirst(22);
    l1.insertFirst(33);
    l1.insertEnd(44);
    l1.insertAtPos(1, 55);
    l1.print();
    l1.reverse();
    l1.print();
    return 0;
}