class Solution:
    def findNumberIn2DArray(self, matrix, target: int) -> bool:
        n = len(matrix)
        if n == 0: return False
        m = len(matrix[0])
        i, j = 0, len(matrix[0]) - 1
        while i < n and j >= 0:
            if matrix[i][j] > target: j -= 1
            elif  matrix[i][j] < target: i += 1
            else: return True
        return False