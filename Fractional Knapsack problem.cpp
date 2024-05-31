#include <iostream>
#include <vector>
#include <algorithm>

// Structure for an item which stores weight and corresponding value
struct Item {
    int weight;
    int value;
};

// Comparison function to sort items according to value/weight ratio
bool cmp(struct Item a, struct Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Main function to solve the fractional knapsack problem
double fractionalKnapsack(int W, std::vector<Item> &items) {
    // Sort items by descending value/weight ratio
    std::sort(items.begin(), items.end(), cmp);

    double totalValue = 0.0; // Variable to store the final value

    for (auto &item : items) {
        if (W == 0) break; // If the knapsack is full, break

        if (item.weight <= W) {
            // If the item can be picked whole
            W -= item.weight;
            totalValue += item.value;
        } else {
            // If the item can't be picked whole, pick fractional part
            totalValue += item.value * ((double)W / item.weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int W = 50; // Knapsack capacity
    std::vector<Item> items = {{60, 10}, {100, 20}, {120, 30}}; // Items (value, weight)

    double maxValue = fractionalKnapsack(W, items);

    std::cout << "Maximum value in Knapsack = " << maxValue << std::endl;

    return 0;
}
