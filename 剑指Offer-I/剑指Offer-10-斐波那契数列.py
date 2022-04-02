class Solution:
    def fib(self, n: int) -> int:
        if n <= 1: return n
        before, pre = 0, 1
        for _ in range(n - 1):
            before, pre = pre, before + pre
        return pre % 1000000007

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
            n = int(line)
            
            ret = Solution().fib(n)

            out = str(ret)
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()