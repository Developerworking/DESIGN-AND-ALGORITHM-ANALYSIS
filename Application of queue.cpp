#include <iostream>
#include <queue>

int main() {
    std::queue<int> q;

    // Push elements into the queue
    q.push(10);
    q.push(20);
    q.push(30);

    std::cout << "Queue size: " << q.size() << std::endl; // Output: 3

    // Access the front and back elements
    std::cout << "Front element: " << q.front() << std::endl; // Output: 10
    std::cout << "Back element: " << q.back() << std::endl;   // Output: 30

    // Pop elements from the queue
    q.pop();
    std::cout << "Front element after pop: " << q.front() << std::endl; // Output: 20

    // Check if the queue is empty
    if (q.empty()) {
        std::cout << "Queue is empty" << std::endl;
    } else {
        std::cout << "Queue is not empty" << std::endl; // Output: Queue is not empty
    }

    // Print remaining elements
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl; // Output: 20 30

    return 0;
}
