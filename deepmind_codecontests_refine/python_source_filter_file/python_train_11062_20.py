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


# input = sys.stdin.buffer.readline

def index(a, x):
    i = bisect.bisect_left(a, x)
    if i != len(a) and a[i] == x:
        return i
    return i


#############
# MAIN CODE #
#############

for i in range(int(input())):
    n = getN()
    arr = getList()[::-1]
    if n <= 2:
        print(0)
        continue
    decrease = 0
    increase = 0

    if arr[0] < arr[1]:
        increase = 1
    else:
        decrease = 1
    ans = 0
    for i in range(2, n):
        if increase:
            if arr[i] < arr[i - 1]:
                decrease = 1
                increase = 0
        if decrease:
            if arr[i] > arr[i - 1]:
                ans = n - i
                break

    arr = arr[:n - ans][::-1]
    m = min(arr)
    if arr[0] == m or arr[-1] == m:
        print(ans)
    else:
        print(ans + arr.index(m))
