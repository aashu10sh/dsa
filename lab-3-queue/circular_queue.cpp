#include<iostream>
#define MAX 3

class Queue {
private:
    int rear = 0;
    int front = 0;
    int data[MAX];

public:
    Queue() {}

    int enqueue(int _data) {
        if ((front + 1) % MAX == rear) {
            throw std::overflow_error("The Queue is Overflowing");
        }
        data[front] = _data;
        front = (front + 1) % MAX;
        return _data;
    }

    int dequeue() {
        if (rear == front) {
            throw std::underflow_error("The Queue is Underflowing");
        }
        int original = data[rear];
        data[rear] = 0;
        rear = (rear + 1) % MAX;
        return original;
    }

    void printQueue() {
        std::cout << "Printing Queue!" << std::endl;
        std::cout << "--------------" << std::endl;
        int i = rear;
        while (i != front) {
            std::cout << data[i] << std::endl;
            i = (i + 1) % MAX;
        }
        std::cout << "--------------" << std::endl;
    }
};

int main(void) {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.printQueue();
    // q.enqueue(3); // overflow here.
    // q.printQueue();
    q.dequeue();
    q.dequeue();
    q.printQueue();
    q.dequeue(); // should throw underflow error.
    return 0;
}
