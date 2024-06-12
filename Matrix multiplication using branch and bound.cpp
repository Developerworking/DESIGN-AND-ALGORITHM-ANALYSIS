#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to multiply matrices A and B
void multiplyMatrices(vector<vector<int>>& result, vector<vector<int>>& A, vector<vector<int>>& B) {
    int aRows = A.size();
    int aCols = A[0].size();
    int bCols = B[0].size();
    
    for (int i = 0; i < aRows; ++i) {
        for (int j = 0; j < bCols; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < aCols; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Utility function to print a matrix
void printMatrix(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to find the minimum number of multiplications needed
// to multiply the chain of matrices
int matrixChainOrder(vector<int>& p, int n) {
    // m[i, j] = Minimum number of scalar multiplications needed
    // to compute the matrix A[i]A[i+1]...A[j] = A[i..j] where
    // dimension of A[i] is p[i-1] x p[i]
    vector<vector<int>> m(n, vector<int>(n, 0));

    // L is the chain length
    for (int L = 2; L < n; ++L) {
        for (int i = 1; i < n - L + 1; ++i) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; ++k) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }

    return m[1][n - 1];
}

int main() {
    vector<int> p = {1, 2, 3, 4};  // Dimension array
    int n = p.size();

    cout << "Minimum number of multiplications is: " << matrixChainOrder(p, n) << endl;

    vector<vector<int>> A = {{1, 2}, {3, 4}};
    vector<vector<int>> B = {{5, 6}, {7, 8}};
    vector<vector<int>> C(2, vector<int>(2));

    multiplyMatrices(C, A, B);

    cout << "Result of matrix multiplication:" << endl;
    printMatrix(C);

    return 0;
}
