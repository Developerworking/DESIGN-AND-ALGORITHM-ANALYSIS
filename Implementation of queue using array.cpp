#include <iostream>

#define SIZE 5 // Size of the queue

class Queue {
private:
    int front, rear, capacity;
    int* array;

public:
    Queue(int size = SIZE); // Constructor
    ~Queue(); // Destructor

    void enqueue(int item);
    int dequeue();
    int peek();
    bool isEmpty();
    bool isFull();
};

Queue::Queue(int size) {
    capacity = size;
    front = rear = -1;
    array = new int[size];
}

Queue::~Queue() {
    delete[] array;
}

void Queue::enqueue(int item) {
    if (isFull()) {
        std::cout << "Queue is full. Cannot enqueue.\n";
        return;
    }

    if (isEmpty())
        front = 0;

    rear++;
    array[rear] = item;
    std::cout << item << " enqueued to the queue.\n";
}

int Queue::dequeue() {
    if (isEmpty()) {
        std::cout << "Queue is empty. Cannot dequeue.\n";
        return -1;
    }

    int item = array[front];
    front++;

    if (front > rear) // Reset front and rear when queue becomes empty
        front = rear = -1;

    return item;
}

int Queue::peek() {
    if (isEmpty()) {
        std::cout << "Queue is empty. No element to peek.\n";
        return -1;
    }

    return array[front];
}

bool Queue::isEmpty() {
    return front == -1 && rear == -1;
}

bool Queue::isFull() {
    return rear == capacity - 1;
}

int main() {
    Queue queue(5);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    queue.enqueue(60); // Queue is full. Cannot enqueue.

    std::cout << "Front element: " << queue.peek() << std::endl;

    std::cout << queue.dequeue() << " dequeued from queue.\n";
    std::cout << queue.dequeue() << " dequeued from queue.\n";

    std::cout << "Front element: " << queue.peek() << std::endl;

    queue.enqueue(60);
    std::cout << "Front element: " << queue.peek() << std::endl;

    return 0;
}
