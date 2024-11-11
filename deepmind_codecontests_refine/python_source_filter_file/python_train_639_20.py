import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000)

def getN():
    return int(input())
def getList():
    return list(map(int, input().split()))
import math


def main():
    n, m, k = getList()
    nums = getList()

    tmp = nums[0]
    rem = 0
    ans = 0
    pile = 1
    for num in nums:
        if (tmp - rem - 1) // k == (num - rem - 1) // k:
            pile += 1
        else:
            ans += 1
            tmp = num
            rem += pile
            pile = 1

    ans += 1
    print(ans)
if __name__ == "__main__":
    main()

