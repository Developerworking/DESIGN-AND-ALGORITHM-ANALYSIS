#include <iostream>

// Define the Node structure
struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

// Define the Queue class
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to enqueue an element into the queue
    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Function to dequeue an element from the queue
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr; // If front becomes null, update rear too
        }
    }

    // Function to get the front element of the queue
    int peek() {
        if (isEmpty()) {
            std::cerr << "Queue is empty. No front element.\n";
            return -1; // Assuming -1 is not a valid element in the queue
        }
        return front->data;
    }

    // Function to display the elements in the queue
    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return;
        }
        Node* current = front;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Destructor to deallocate memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

// Main function to test the Queue implementation
int main() {
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    
    std::cout << "Queue elements: ";
    queue.display();

    std::cout << "Front element: " << queue.peek() << std::endl;

    queue.dequeue();
    std::cout << "After dequeue operation:\n";
    std::cout << "Queue elements: ";
    queue.display();

    return 0;
}
