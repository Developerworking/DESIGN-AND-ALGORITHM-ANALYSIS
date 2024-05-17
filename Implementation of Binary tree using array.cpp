#include <iostream>
#include <vector>
#include <stdexcept>

class BinaryTree {
private:
    std::vector<int> tree;
    int capacity;

public:
    BinaryTree(int size) {
        capacity = size;
        tree.resize(size, -1); // Initializing the tree with -1 (assuming -1 as empty)
    }

    void setRoot(int key) {
        tree[0] = key;
    }

    void setLeft(int parent, int key) {
        int leftChild = 2 * parent + 1;
        if (leftChild >= capacity) {
            throw std::out_of_range("Index out of bounds");
        }
        if (tree[parent] == -1) {
            throw std::invalid_argument("Parent does not exist");
        }
        tree[leftChild] = key;
    }

    void setRight(int parent, int key) {
        int rightChild = 2 * parent + 2;
        if (rightChild >= capacity) {
            throw std::out_of_range("Index out of bounds");
        }
        if (tree[parent] == -1) {
            throw std::invalid_argument("Parent does not exist");
        }
        tree[rightChild] = key;
    }

    void printTree() {
        for (int i = 0; i < capacity; ++i) {
            if (tree[i] != -1) {
                std::cout << tree[i] << " ";
            } else {
                std::cout << "- ";
            }
        }
        std::cout << std::endl;
    }

    int getParent(int i) {
        if (i == 0) {
            throw std::invalid_argument("Root does not have a parent");
        }
        return (i - 1) / 2;
    }

    int getLeftChild(int i) {
        int leftChild = 2 * i + 1;
        if (leftChild >= capacity || tree[leftChild] == -1) {
            throw std::out_of_range("Left child does not exist");
        }
        return leftChild;
    }

    int getRightChild(int i) {
        int rightChild = 2 * i + 2;
        if (rightChild >= capacity || tree[rightChild] == -1) {
            throw std::out_of_range("Right child does not exist");
        }
        return rightChild;
    }
};

int main() {
    BinaryTree bt(10); // Create a binary tree with a capacity of 10
    bt.setRoot(1);
    bt.setLeft(0, 2);
    bt.setRight(0, 3);
    bt.setLeft(1, 4);
    bt.setRight(1, 5);

    bt.printTree();

    try {
        std::cout << "Parent of node 1: " << bt.getParent(1) << std::endl;
        std::cout << "Left child of node 1: " << bt.getLeftChild(0) << std::endl;
        std::cout << "Right child of node 1: " << bt.getRightChild(0) << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
