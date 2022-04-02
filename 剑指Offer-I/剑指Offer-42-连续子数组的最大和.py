import  json

class Solution:
    def maxSubArray(self, nums) -> int:
        sub, ret = nums[0], nums[0]
        for i in range(len(nums) - 1):
            sub = max(sub + nums[i + 1], nums[i + 1])
            ret = max(ret, sub)
        return ret

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
            
            ret = Solution().maxSubArray(nums)

            out = str(ret)
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()