/*
Dequeue
Send Feedback
You need to implement a class for Dequeue i.e. for double ended queue. In this queue, elements can be inserted and deleted from both the ends.
You don't need to double the capacity.
You need to implement the following functions -
1. constructor
You need to create the appropriate constructor. Size for the queue passed is 10.
2. insertFront -
This function takes an element as input and insert the element at the front of queue. Insert the element only if queue is not full. And if queue is full, print -1 and return.
3. insertRear -
This function takes an element as input and insert the element at the end of queue. Insert the element only if queue is not full. And if queue is full, print -1 and return.
4. deleteFront -
This function removes an element from the front of queue. Print -1 if queue is empty.
5. deleteRear -
This function removes an element from the end of queue. Print -1 if queue is empty.
6. getFront -
Returns the element which is at front of the queue. Return -1 if queue is empty.
7. getRear -
Returns the element which is at end of the queue. Return -1 if queue is empty.
*/
#include<iostream>
using namespace std;

#define MAX 100
class Deque {
    // Complete this class
    int  arr[MAX];
    int  front;
    int  rear;
    int  size;
public :
    Deque(int size)
    {
        front = -1;
        rear = 0;
        this->size = size;
    }

    // Operations on Deque:
    void  insertFront(int key);
    void  insertRear(int key);
    void  deleteFront();
    void  deleteRear();
    bool  isFull();
    bool  isEmpty();
    int  getFront();
    int  getRear();
};
bool Deque::isFull()
{
    return ((front == 0 && rear == size-1)||
            front == rear+1);
}

// Checks whether Deque is empty or not.
bool Deque::isEmpty ()
{
    return (front == -1);
}

// Inserts an element at front
void Deque::insertFront(int key)
{
    // check whether Deque if  full or not
    if (isFull())
    {
        cout<<"-1"<<endl;
        return;
    }

    // If queue is initially empty
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }

    // front is at first position of queue
    else if (front == 0)
        front = size - 1 ;

    else // decrement front end by '1'
        front = front-1;

    // insert current element into Deque
    arr[front] = key ;
}

// function to inset element at rear end
// of Deque.
void Deque ::insertRear(int key)
{
    if (isFull())
    {
        cout<<"-1"<<endl;
        return;
    }

    // If queue is initially empty
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }

    // rear is at last position of queue
    else if (rear == size-1)
        rear = 0;

    // increment rear end by '1'
    else
        rear = rear+1;

    // insert current element into Deque
    arr[rear] = key ;
}

// Deletes element at front end of Deque
void Deque ::deleteFront()
{
    // check whether Deque is empty or not
    if (isEmpty())
    {
        cout<<"-1"<<endl;
        return;
    }

    // Deque has only one element
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
        // back to initial position
        if (front == size -1)
            front = 0;

        else // increment front by '1' to remove current
            // front value from Deque
            front = front+1;
}

// Delete element at rear end of Deque
void Deque::deleteRear()
{
    if (isEmpty())
    {
        cout<<"-1"<<endl;
        return;
    }

    // Deque has only one element
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
        rear = size-1;
    else
        rear = rear-1;
}

// Returns front element of Deque
int Deque::getFront()
{
    // check whether Deque is empty or not
    if (isEmpty())
    {
        return -1 ;
    }
    return arr[front];
}
// function return rear element of Deque
int Deque::getRear()
{
    // check whether Deque is empty or not
    if(isEmpty() || rear < 0)
    {
        return -1 ;
    }
    return arr[rear];
}
// Driver program to test above function
int main()
{
    Deque dq(10);
    int choice,input;
    while(true) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                dq.insertFront(input);
                break;
            case 2:
                cin >> input;
                dq.insertRear(input);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                cout << dq.getFront() << "\n";
                break;
            case 6:
                cout << dq.getRear() << "\n";
                break;
            default:
                return 0;
        }
    }

    return 0;
}
