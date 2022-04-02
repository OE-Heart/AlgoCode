import json
import sys

class Solution:
    def maxProfit(self, prices) -> int:
        low = sys.maxsize
        profit = 0
        for i in range(len(prices)):
            low = min(low, prices[i])
            profit = max(profit, prices[i] - low)
        return profit

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
            prices = stringToIntegerList(line)
            
            ret = Solution().maxProfit(prices)

            out = str(ret)
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()