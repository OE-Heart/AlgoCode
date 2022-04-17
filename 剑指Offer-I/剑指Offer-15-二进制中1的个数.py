class Solution:
    def hammingWeight(self, n: int) -> int:
        ret = 0
        while n > 0:
            ret += n & 1
            n >>= 1
        return ret

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
            
            ret = Solution().hammingWeight(n)

            out = str(ret)
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()