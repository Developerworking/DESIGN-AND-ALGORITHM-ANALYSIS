#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> matrix;

// Function to add two matrices
matrix add(matrix &A, matrix &B) {
    int n = A.size();
    matrix C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// Function to subtract two matrices
matrix subtract(matrix &A, matrix &B) {
    int n = A.size();
    matrix C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// Strassen's algorithm for matrix multiplication
matrix strassen(matrix &A, matrix &B) {
    int n = A.size();
    matrix C(n, vector<int>(n));

    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
    } else {
        int k = n / 2;
        matrix A11(k, vector<int>(k)), A12(k, vector<int>(k)), A21(k, vector<int>(k)), A22(k, vector<int>(k));
        matrix B11(k, vector<int>(k)), B12(k, vector<int>(k)), B21(k, vector<int>(k)), B22(k, vector<int>(k));
        matrix C11(k, vector<int>(k)), C12(k, vector<int>(k)), C21(k, vector<int>(k)), C22(k, vector<int>(k));
        matrix M1(k, vector<int>(k)), M2(k, vector<int>(k)), M3(k, vector<int>(k)), M4(k, vector<int>(k));
        matrix M5(k, vector<int>(k)), M6(k, vector<int>(k)), M7(k, vector<int>(k));

        // Dividing the matrices into submatrices:
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + k];
                A21[i][j] = A[i + k][j];
                A22[i][j] = A[i + k][j + k];
                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + k];
                B21[i][j] = B[i + k][j];
                B22[i][j] = B[i + k][j + k];
            }
        }

        // Calculating M1 to M7:
        M1 = strassen(add(A11, A22), add(B11, B22));
        M2 = strassen(add(A21, A22), B11);
        M3 = strassen(A11, subtract(B12, B22));
        M4 = strassen(A22, subtract(B21, B11));
        M5 = strassen(add(A11, A12), B22);
        M6 = strassen(subtract(A21, A11), add(B11, B12));
        M7 = strassen(subtract(A12, A22), add(B21, B22));

        // Calculating C11, C12, C21, C22:
        C11 = add(subtract(add(M1, M4), M5), M7);
        C12 = add(M3, M5);
        C21 = add(M2, M4);
        C22 = add(subtract(add(M1, M3), M2), M6);

        // Combining the results into a single matrix:
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                C[i][j] = C11[i][j];
                C[i][j + k] = C12[i][j];
                C[i + k][j] = C21[i][j];
                C[i + k][j + k] = C22[i][j];
            }
        }
    }

    return C;
}

// Function to print a matrix
void printMatrix(matrix &M) {
    for (auto &row : M) {
        for (auto &val : row)
            cout << val << " ";
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the matrix (must be a power of 2): ";
    cin >> n;

    matrix A(n, vector<int>(n)), B(n, vector<int>(n));

    cout << "Enter elements of matrix A:" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter elements of matrix B:" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];

    matrix C = strassen(A, B);

    cout << "Resultant matrix C is:" << endl;
    printMatrix(C);

    return 0;
}
