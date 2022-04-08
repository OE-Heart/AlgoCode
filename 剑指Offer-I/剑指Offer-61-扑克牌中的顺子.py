import json

class Solution:
    def isStraight(self, nums) -> bool:
        nums.sort()
        index = 0
        for i in range(4):
            if nums[i] == 0: index += 1
            elif nums[i] == nums[i + 1]: return False
        return nums[4] - nums[index] < 5


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
            nums = stringToIntegerList(line);
            
            ret = Solution().isStraight(nums)

            out = (ret)
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()