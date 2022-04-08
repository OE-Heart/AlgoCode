import  json

class SmallerNumKey(str):
    def __lt__(x, y):
        return x+y < y+x

class Solution:
    def minNumber(self, nums) -> str:
        str_nums = sorted([str(num) for num in nums], key=SmallerNumKey)
        return "".join(str_nums)

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
            
            ret = Solution().minNumber(nums)

            out = (ret)
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()