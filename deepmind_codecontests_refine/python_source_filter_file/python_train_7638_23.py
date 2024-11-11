from sys import stdin, stdout
import heapq
import cProfile
from collections import Counter, defaultdict, deque
from functools import reduce
import math
def get_int():
    return int(stdin.readline().strip())


def get_tuple():
    return map(int, stdin.readline().split())


def get_list():
    return list(map(int, stdin.readline().split()))

def solve():
    n, m, d = get_tuple()
    arr = []
    for _ in range(n):
        arr.extend(get_list())

    mod = arr[0] % d
    for val in arr:
        if val % d != mod: return -1

    arr.sort()
    median = arr[(n+1)//2]
    ans = 0
    for val in arr:
        ans += abs(val-median)
    #print(median,ans)
    return ans


def main():
    print(solve())










TestCases = False

if TestCases:
    for i in range(get_int()):
        main()
else:
    main()
