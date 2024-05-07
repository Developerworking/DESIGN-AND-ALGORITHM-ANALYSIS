#include <iostream>

// Define the structure of each node in the linked list
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

// Define the stack class using a linked list
class Stack {
private:
    Node* top; // Pointer to the top element of the stack
    
public:
    Stack() : top(nullptr) {} // Constructor to initialize an empty stack
    
    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
    
    // Function to push an element onto the stack
    void push(int val) {
        Node* newNode = new Node(val); // Create a new node with the given value
        newNode->next = top; // Set the next pointer of the new node to the current top
        top = newNode; // Update the top pointer to the new node
    }
    
    // Function to pop an element from the stack
    void pop() {
        if (isEmpty()) {
            std::cout << "Stack underflow!" << std::endl;
            return;
        }
        Node* temp = top; // Store the current top pointer
        top = top->next; // Move the top pointer to the next element
        delete temp; // Delete the previous top node
    }
    
    // Function to return the top element of the stack
    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty!" << std::endl;
            return -1;
        }
        return top->data; // Return the data of the top node
    }
};

int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Top element: " << stack.peek() << std::endl;
    
    stack.pop();
    stack.pop();

    std::cout << "Top element after popping: " << stack.peek() << std::endl;

    return 0;
}
