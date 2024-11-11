import sys
import math
from functools import reduce
import bisect


def getN():
    return int(input())


def getNM():
    return map(int, input().split())


def getList():
    return list(map(int, input().split()))


def input():
    return sys.stdin.readline().rstrip()


def index(a, x):
    i = bisect.bisect_left(a, x)
    if i != len(a) and a[i] == x:
        return i
    return False


#############
# MAIN CODE #
#############
def solve():
    n = getN()
    for i in range(n % 7 + 1):
        for j in range(n - i * 7 + 1):
            a = (n - i * 7) - j * 5
            if a % 3 == 0 and a >= 0:
                print(a // 3, j, i)
                return
    print(-1)
    return


for _ in range(getN()):
    solve()
