import json

class Solution:
    def twoSum(self, nums, target: int):
        left, right = 0, len(nums) - 1
        while left < right and nums[left] + nums[right] != target:
            while left < right and nums[left] + nums[right] < target: left += 1
            while left < right and nums[left] + nums[right] > target: right -= 1
        if left < right: return [nums[left], nums[right]]
        else: return []

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
            line = next(lines)
            target = int(line)
            
            ret = Solution().twoSum(nums, target)

            out = integerListToString(ret)
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()