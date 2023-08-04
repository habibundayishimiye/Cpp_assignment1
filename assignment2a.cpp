/*group members 1.NDAYISHIMIYE Habibu 222005474
                2.UWABABYEYI MBABAZI Aline 222009293
                3.IRADUKUNDA Bonheur 222005615
                */
                             //QUESTION
  /* 1. A square magic is square matrix such the sum of each row is equal to the
sum of each column, and equal to the sum of each of the diagonals. Write
a C++ function that takes a matrix (2 dimensional vector ) and return true if
the matrix is a magic square and false otherwise.*/ 
          //ANSWER
#include <iostream>
#include <vector>

bool isMagicSquare(const std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();

    // Calculate the sum of the first row (sumRow) and first column (sumCol)
    int sumRow = 0, sumCol = 0;
    for (int i = 0; i < n; ++i) {
        sumRow += matrix[0][i];
    }
    
    for (int j = 0; j < n; ++j) {
        sumCol += matrix[j][0];
    }

    // Calculate the sum of the main diagonal (sumDiag1) and secondary diagonal (sumDiag2)
    int sumDiag1 = 0, sumDiag2 = 0;
    for (int i = 0; i < n; ++i) {
        sumDiag1 += matrix[i][i];
        sumDiag2 += matrix[i][n - 1 - i];
    }

    // Check if the sums are equal for all rows, columns, and diagonals
    if (sumRow != sumCol || sumRow != sumDiag1 || sumRow != sumDiag2)
        return false;

    // Check if the sums are equal for each row and column
    for (int i = 1; i < n; ++i) {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < n; ++j) {
            rowSum += matrix[i][j];
            colSum += matrix[j][i];
        }

        if (rowSum != sumRow || colSum != sumRow)
            return false;
    }

    return true;
}

int main() {
    //vector initialisation
int n;
    std::cout << "Enter the size of the square matrix: ";
    std::cin >> n;

    // Create  vector to store the matrix
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));

    // here a user can allowed to enter value for the matrix
    std::cout << "Enter the elements of the matrix:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << "Enter element at position (" << i << ", " << j << "): ";
            std::cin >> matrix[i][j];
        }
    }
      //here we check if matrix is magic square or not
    if (isMagicSquare(matrix))
        std::cout << "The matrix is a magic square." << std::endl;
    else
        std::cout << "The matrix is not a magic square." << std::endl;

    return 0;
}
