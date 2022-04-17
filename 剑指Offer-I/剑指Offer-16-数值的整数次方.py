class Solution:
    def myPow(self, x: float, n: int) -> float:
        if x == 0: return 0
        res = 1
        if n < 0: x, n = 1 / x, -n
        while n:
            if n & 1: res *= x
            x *= x
            n >>= 1
        return res

def main():
    x = int(input())
    n = int(input())
    
    ret = Solution().myPow(x, n)
    print(ret)

if __name__ == '__main__':
    main()