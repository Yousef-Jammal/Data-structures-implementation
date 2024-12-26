#include <iostream>
using namespace std;


class arrayList
{
    int *arr;
    int maxSize;
    int length;

    public:
        arrayList(int size = 10)
        {
            if (size < 0)
            {
                maxSize = 10;
            }else{
                maxSize = size;
            }
            length = 0;
            arr = new int[maxSize];
            
        }

        int isEmpty()
        {
            return length == 0;
        }

        int isFull()
        {
            return length == maxSize;
        }

        int getSize()
        {
            return length;
        }

        void print()
        {
            for (size_t i = 0; i < length; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        void push(int element)
        {

        }

        void insertAtPos(int pos, int element)
        {
            if (isFull()){
                cout << "Array is full";
            }else if(pos < 0 || pos > length){
                cout << "Out of range";
            }else{
                for (size_t i = length; i > pos; i--)
                {
                    arr[i] = arr[i - 1];
                }
                arr[pos] = element;
                length++;
            }
        }

        void insertAtEnd(int element)
        {
            if (isFull()){
                cout << "Array is full";
            }else{
                arr[length] = element;
                length++;
            }
        }

        void removeAtPos(int pos)
        {
            if (isEmpty()){
                cout << "Array is empty";
            }else if(pos < 0 || pos >= length){
                cout << "Out of range";
            }else{
                for (size_t i = pos; i < length; i++)
                {
                    arr[i] = arr[i + 1];
                }
                length--;
            }
        }

        int search(int element)
        {
            for (size_t i = 0; i < length; i++)
            {
                if(arr[i] ==  element){
                    return i;
                }
            }
            return -1;
        }

        void insertNotDuplicate(int element)
        {
            if(search(element) == -1)
                insertAtEnd(element);
            else
                cout << "Dupclicated element";
            
        }

        void updateAt(int pos, int element)
        {
            if (isEmpty()){
                cout << "Array is empty";
            }else if(pos < 0 || pos >= length){
                cout << "Out of range";
            }else{
                arr[pos] = element;
            }
        }

        ~arrayList()
        {
            delete[]arr; // Delete all element from momary in the end of this program
        }

};





int main() {
    arrayList ar(100);
    ar.insertAtEnd(11);
    ar.insertAtEnd(22);
    ar.insertAtEnd(33);
    ar.insertAtPos(1, 11111);
    ar.insertNotDuplicate(11111);
    // cout << ar.search(22);
    ar.updateAt(1, 44444444);
    ar.print();
    return 0;
}