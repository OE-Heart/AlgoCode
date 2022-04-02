class Solution:
    def translateNum(self, num: int) -> int:
        s = str(num)
        n = len(s)
        if n <= 1: return n
        before, pre = 1, 1
        for i in range(n - 1):
            if "10" <= s[i: i+2] <= "25":
                before, pre = pre, before + pre
            else: before = pre
        return pre

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
            num = int(line)
            
            ret = Solution().translateNum(num)

            out = str(ret)
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()