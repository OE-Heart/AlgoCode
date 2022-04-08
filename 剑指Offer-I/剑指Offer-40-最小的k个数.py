import json

class Solution:
    def getLeastNumbers(self, arr, k: int):
        arr.sort()
        return arr[:k]

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
            arr = stringToIntegerList(line)
            line = next(lines)
            k = int(line)
            
            ret = Solution().getLeastNumbers(arr, k)

            out = integerListToString(ret)
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()