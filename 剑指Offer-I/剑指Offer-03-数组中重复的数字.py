import json

class Solution:
    def findRepeatNumber(self, nums) -> int:
        dic = set()
        for val in nums:
            if val in dic: return val
            else: dic.add(val)

def stringToIntegerList(input):
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
            nums = stringToIntegerList(line)
            
            ret = Solution().findRepeatNumber(nums)

            out = str(ret)
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()