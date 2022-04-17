class Solution:
    def cuttingRope(self, n: int) -> int:
        if n <= 3: return n - 1
        a = n // 3
        b = n % 3
        if b == 0: ret = 3 ** a
        elif b == 1: ret = 4 * 3 ** (a - 1)
        else: ret = 2 * 3 ** a
        return ret % 1000000007

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
            
            ret = Solution().cuttingRope(n)

            out = str(ret)
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()