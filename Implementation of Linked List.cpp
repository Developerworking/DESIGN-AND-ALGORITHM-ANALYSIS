#include <iostream>

// Node class to represent each element in the linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize a node with given data and next pointer
    Node(int value) : data(value), next(nullptr) {}
};

// Linked list class to manage the nodes
class LinkedList {
private:
    Node* head; // Pointer to the first node of the linked list

public:
    // Constructor to initialize an empty linked list
    LinkedList() : head(nullptr) {}

    // Destructor to free the memory allocated for the linked list
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // Method to insert a new node at the beginning of the linked list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Method to display the elements of the linked list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    // Creating a linked list object
    LinkedList myList;

    // Inserting elements into the linked list
    myList.insertAtBeginning(5);
    myList.insertAtBeginning(10);
    myList.insertAtBeginning(15);

    // Displaying the linked list
    std::cout << "Linked List: ";
    myList.display();

    return 0;
}
