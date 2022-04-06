import json
        
class Solution:
    def exchange(self, nums):
        left, right = 0, len(nums) - 1
        while left < right:
            while left < right and nums[left] & 1 == 1: left += 1
            while left < right and nums[right] & 1 == 0: right -= 1
            nums[left], nums[right] = nums[right], nums[left]
        return nums

def stringToIntegerList(input):
    return json.loads(input)

def integerListToString(nums, len_of_list=None):
    if not len_of_list:
        len_of_list = len(nums)
    return json.dumps(nums[:len_of_list])

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
            
            ret = Solution().exchange(nums)

            out = integerListToString(ret)
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()