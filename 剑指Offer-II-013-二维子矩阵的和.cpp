#include <vector>
#include <cstdlib>
#include <cstring>
using namespace std;

class NumMatrix {
public:
    int* sum;
    int n;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m > 0) {
            n = matrix.at(0).size();
            sum = (int*)malloc((m+1)*(n+1)*sizeof(int));
            memset(sum, 0, (m+1)*(n+1)*sizeof(int));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    sum[(i+1)*(n+1)+j+1] = sum[i*(n+1)+j+1]+sum[(i+1)*(n+1)+j]-sum[i*(n+1)+j]+matrix[i][j];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[(row2+1)*(n+1)+col2+1]-sum[(row2+1)*(n+1)+col1]-sum[row1*(n+1)+col2+1]+sum[row1*(n+1)+col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */