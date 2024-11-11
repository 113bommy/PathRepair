import sys, math, cmath, time, collections
from collections import deque, Counter, OrderedDict, defaultdict
from heapq import nsmallest, nlargest, heapify, heappop, heappush, heapreplace
from math import ceil, floor, log, log2, sqrt, gcd, factorial, pow, pi
from bisect import bisect_left, bisect_right

start_time = time.time()


def solve(a, n):
    """
    The actual solution begins here
    c = a + b
    print(c)
    """
    cur = [0]
    for i in range(n):
        cur = cur + [x + a[i] for x in cur] + [x - a[i] for x in cur]
        # print(f"The current is: {cur}")
    print('YES' if sum(x == 0 for x in cur) > 1 else 'NO')

def main():
    """
    Main function dedicated to get the I/P
    a, b = map(int, input().split())
    solve(a, b)
    """
    n = int(input())
    arr = list(map(int, input().split()))
    solve(arr, n)


if __name__ == "__main__":
    testcases = int(input())
    for i in range(testcases):
        main()