//
//  main.cpp
//  transpose
//
//  Created by Dan Park on 6/19/19.
//  Copyright © 2019 Dan Park. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void initMatrix(vector<vector<int>> &matrix) {
    long m = matrix.size();
    
    int count = 1;
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < m; col++) {
            matrix[row][col] = count;
            count++;
        }
    }
}

void printMatrix(const vector<vector<int>> &matrix) {
    long m = matrix.size();
    
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < m; col++) {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void transpose(vector<vector<int>>& matrix) {
    long length = matrix.size();

    for (int row = 0; row < length; row++) {
        for (int col = 0; col < length; col++) {
            if (row == col) {
                continue;
            }

            if (row > 0) {
                int lastRow = col;
                if (row > lastRow) {
//                    cout <<  "m[" << row << "][" << col << "] " << matrix[row][col] << " : m[" << col << "][" << row << "] " << matrix[col][row] << endl;
//                    cout << endl;
                    continue;
                }
            }
            
//            cout <<  "m[" << row << "][" << col << "] " << matrix[row][col] << " : m[" << col << "][" << row << "] " << matrix[col][row] << endl;
            
            int temp = matrix[col][row];
            matrix[col][row] = matrix[row][col];
            matrix[row][col] = temp;
            
//            cout <<  "m[" << row << "][" << col << "] " << matrix[row][col] << " : m[" << col << "][" << row << "] " << matrix[col][row] << endl;
//            cout << endl;
        }
    }

}

int main(int argc, const char * argv[]) {
    
    int m = 6, n = 6;
    vector<vector<int>> matrix(m, vector<int>(n,0));
    
    initMatrix(matrix);
    printMatrix(matrix);

    transpose(matrix);
    printMatrix(matrix);
    
    return 0;
}
