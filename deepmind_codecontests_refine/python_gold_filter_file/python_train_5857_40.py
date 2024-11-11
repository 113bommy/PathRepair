from sys import stdin, stdout
import heapq
import cProfile
from collections import Counter, defaultdict, deque
from functools import reduce
import math
from bisect import bisect,bisect_right,bisect_left

def get_int():
    return int(stdin.readline().strip())


def get_tuple():
    return map(int, stdin.readline().split())


def get_list():
    return list(map(int, stdin.readline().split()))


def solve():
    n,r = get_tuple()
    if n>r:
        return (r*(r+1))//2
    else:
        ans = (n*(n+1))//2
        return ans-(n-1)


def main():
    print(solve())


TestCases = True

if TestCases:
    for i in range(get_int()):
        main()
else:
    main()
