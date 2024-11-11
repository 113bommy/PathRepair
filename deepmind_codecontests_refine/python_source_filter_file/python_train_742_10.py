# python3

#===============================================================================
from collections import defaultdict, Counter
from functools import lru_cache
from heapq import heappush, heappop
from math import gcd, floor, ceil
from sys import stdin, stdout

def ilist():
    return [int(x) for x in stdin.readline().strip().split(" ")]
def iint():
    return int(stdin.readline().strip())
def istr():
    return stdin.readline().strip()
#===============================================================================


def solve(a, b):
    p = 998_244_353
    n = len(a)
    a = sorted([(a[i]*i*(n-i+1), i) for i in range(n)])
    b.sort(reverse = True)
    ans = 0
    for i in range(n):
        ans += a[i][0] * b[i]
        ans %= p
    return ans


if __name__ == '__main__':
    n = iint()
    a = ilist()
    b = ilist()
    print(solve(a, b))
