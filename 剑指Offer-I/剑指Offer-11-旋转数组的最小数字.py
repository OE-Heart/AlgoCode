import json

class Solution:
    def minArray(self, numbers) -> int:
        left, right = 0, len(numbers) - 1
        while left < right:
            mid = (right - left) // 2 + left
            if numbers[mid] > numbers[right]: left = mid + 1
            elif numbers[mid] < numbers[right]: right = mid
            else: return min(numbers[left:right])
        return numbers[left]

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
            numbers = stringToIntegerList(line)
            
            ret = Solution().minArray(numbers)

            out = str(ret)
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()