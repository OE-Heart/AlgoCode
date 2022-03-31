import json
from turtle import right

class Solution:
    def missingNumber(self, nums) -> int:
        left = 0
        right = len(nums) - 1
        print(right)
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == mid:
                left = mid + 1
            elif nums[mid] > mid:
                right = mid - 1
        return left

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
            
            ret = Solution().missingNumber(nums)

            out = str(ret)
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()