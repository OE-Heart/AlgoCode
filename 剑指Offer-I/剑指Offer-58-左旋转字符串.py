class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        return s[n:]+s[0:n]

def stringToString(input):
    import json

    return json.loads(input)

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
            s = stringToString(line)
            line = next(lines)
            n = int(line)
            
            ret = Solution().reverseLeftWords(s, n)

            out = (ret)
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()