class Solution:
    def replaceSpace(self, s: str) -> str:
        return s.replace(' ', "%20")

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
            
            ret = Solution().replaceSpace(s)

            out = (ret)
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()