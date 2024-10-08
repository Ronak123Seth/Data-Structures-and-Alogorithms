#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int size;
    int front;
    int rear;

public:
    Queue(int s) {
        size = s;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void push(int val) {
        if (rear == size) {
            cout << "The queue is full." << endl;
            return;
        }
        arr[rear] = val;
        ++rear;
    }

    void pop() {
        if (front == rear) {
            cout << "The queue is empty." << endl;
            return;
        }
        cout << "Deleted value is " << arr[front] << endl;
        ++front;
        if (front == rear) {
            // Space Optimization
            front = rear = 0;
        }
    }

    bool isEmpty() {
        return front == rear;
    }

    void getRear() { 
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << arr[rear - 1] << endl;
    }

    void getFront() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << arr[front] << endl;
    }
};

int main() {
    Queue q(100);
    q.push(5);
    q.push(4);
    q.getRear(); 
    q.getFront();
}
