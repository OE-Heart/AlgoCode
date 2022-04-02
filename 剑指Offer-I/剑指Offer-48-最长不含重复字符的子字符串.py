class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        hashTable = {}
        ret = sub = 0
        for j in range(len(s)):
            i = hashTable.get(s[j], -1)
            hashTable[s[j]] = j
            sub = sub + 1 if sub < j - i else j - i
            ret = max(ret, sub)
        return ret

def stringToString(input):
    import json

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
            s = stringToString(line)
            
            ret = Solution().lengthOfLongestSubstring(s)

            out = str(ret)
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()