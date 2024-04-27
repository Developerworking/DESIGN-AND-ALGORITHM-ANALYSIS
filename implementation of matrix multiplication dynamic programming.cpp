#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to multiply two matrices using dynamic programming
vector<vector<int>> matrixMultiplyDP(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int m = A.size(); // Rows in A
    int n = A[0].size(); // Columns in A and Rows in B
    int p = B[0].size(); // Columns in B

    // Create a result matrix of size (m x p) initialized with 0s
    vector<vector<int>> result(m, vector<int>(p, 0));

    // Dynamic programming approach to calculate each cell of the result matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                // Accumulate the result of multiplication
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

// Function to print a matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example matrices A and B
    vector<vector<int>> A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> B = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    cout << "Matrix A:" << endl;
    printMatrix(A);

    cout << "Matrix B:" << endl;
    printMatrix(B);

    // Multiply matrices A and B
    vector<vector<int>> result = matrixMultiplyDP(A, B);

    cout << "Result of Matrix Multiplication (A * B):" << endl;
    printMatrix(result);

    return 0;
}
