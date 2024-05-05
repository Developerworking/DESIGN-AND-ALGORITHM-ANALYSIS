#include <iostream>
#define MAX_SIZE 100

using namespace std;

class StackArray {
private:
    int top;
    int arr[MAX_SIZE];

public:
    StackArray() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }
};

int main() {
    StackArray stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << stack.pop() << endl; // 3
    cout << stack.peek() << endl; // 2
    cout << stack.pop() << endl; // 2
    cout << stack.pop() << endl; // 1
    cout << stack.pop() << endl; // Stack Underflow
    return 0;
}
