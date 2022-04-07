class Solution:
    def check(self, board, visited, m, n, i, j, word: str) -> bool:
        if visited[i][j]: return False
        if board[i][j] == word[0]:
            if len(word) == 1: return True
            visited[i][j] = True
            if i > 0 and self.check(board, visited, m, n, i - 1, j, word[1:]): return True
            if i < m - 1 and self.check(board, visited, m, n, i + 1, j, word[1:]): return True
            if j > 0 and self.check(board, visited, m, n, i, j - 1, word[1:]): return True
            if j < n - 1 and self.check(board, visited, m, n, i, j + 1, word[1:]): return True
            visited[i][j] = False
        return False

    def exist(self, board, word: str) -> bool:
        m, n = len(board), len(board[0])
        visited = [[False for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if self.check(board, visited, m, n, i, j, word): return True
        return False
