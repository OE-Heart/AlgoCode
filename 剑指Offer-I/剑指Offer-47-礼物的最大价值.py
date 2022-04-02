class Solution:
    def maxValue(self, grid) -> int:
        m = len(grid)
        if m == 0: return 0
        n = len(grid[0])
        for i in range(m):
            for j in range(n):
                if i > 0 and j > 0:
                    grid[i][j] = max(grid[i - 1][j], grid[i][j - 1]) + grid[i][j]
                elif i > 0 and j == 0:
                    grid[i][j] = grid[i - 1][j] + grid[i][j]
                elif i == 0 and j > 0:
                    grid[i][j] = grid[i][j - 1] + grid[i][j]
        return grid[m - 1][n - 1]