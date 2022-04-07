class Solution:
    def check(self, x, y, k) -> bool:
        i, j = x, y
        total = 0
        while i > 0:
            total += i % 10
            i //= 10
        while j > 0:
            total += j % 10
            j //= 10
        return total <= k

    def travel(self, visited, m, n, i, j, k):
        if visited[i][j]: return
        if self.check(i, j, k):
            visited[i][j] = 1
            if i < m - 1: self.travel(visited, m, n, i + 1, j, k)
            if j < n - 1: self.travel(visited, m, n, i, j + 1, k)

    def movingCount(self, m: int, n: int, k: int) -> int:
        visited = [[0 for _ in range(n)] for _ in range(m)]
        self.travel(visited, m, n, 0, 0, k)
        cnt = 0
        for i in range(m):
            cnt += visited[i].count(1)
        return cnt

def main():
    import sys
    import io
    def readlines():
        for line in io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8'):
            yield line.strip('\n')

    lines = readlines()
    while True:
        try:
            line = next(lines)
            m = int(line)
            line = next(lines)
            n = int(line)
            line = next(lines)
            k = int(line)
            
            ret = Solution().movingCount(m, n, k)

            out = str(ret)
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()