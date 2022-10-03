#include<iostream>
using namespace std;
class Queue
{
    int *arr;
    int front, rear, size;
public:
    Queue(int size)
    {
       size = size;
        arr = new int[size];//why is this important
        front = -1;
        rear = -1;
    }
    void enqueue(int x)
    {
        if (rear == size - 1)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (front == -1)
            front = 0;
        rear++;
        arr[rear] = x;
    }
    int dequeue()
    {
        if (front == -1)
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        int x = arr[front];
        front++;
        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
        return x;
    }
    void display()
    {
        if (front == -1)
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};
int main()
{
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.display();
    q.dequeue();
  
    q.display();
    return 0;
}
