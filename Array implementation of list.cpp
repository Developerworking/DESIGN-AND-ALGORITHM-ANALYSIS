#include <iostream>

class ArrayList {
private:
    int *arr;
    int capacity;
    int size;

public:
    ArrayList(int initial_capacity = 10) {
        capacity = initial_capacity;
        arr = new int[capacity];
        size = 0;
    }

    ~ArrayList() {
        delete[] arr;
    }

    void push_back(int value) {
        if (size >= capacity) {
            // If array is full, double its capacity
            int *temp = new int[2 * capacity];
            for (int i = 0; i < size; ++i) {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
            capacity *= 2;
        }
        arr[size++] = value;
    }

    void pop_back() {
        if (size > 0) {
            size--;
        } else {
            std::cout << "List is empty. Cannot pop." << std::endl;
        }
    }

    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

    int getSize() const {
        return size;
    }
};

int main() {
    ArrayList list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    for (int i = 0; i < list.getSize(); ++i) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;

    list.pop_back();
    list.pop_back();

    for (int i = 0; i < list.getSize(); ++i) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
