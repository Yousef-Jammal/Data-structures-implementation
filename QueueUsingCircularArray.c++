#include <iostream>
using namespace std;

const MAX_LENGTH = 100;

class arrayQueueType
{
        int rear;
        int front;
        int length;
        int arr[MAX_LENGTH];

    public:

        arrayQueueType(){
            front = 0;
            rear = MAX_LENGTH -1 ;
            length = 0;
        }

        int isEmpty()
        {
            return length == 0;
        }
}


int main() {

}