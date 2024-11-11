#import numpy as np
import sys, math
from itertools import permutations, combinations
from collections import defaultdict, Counter, deque
from math import factorial#, gcd
from bisect import bisect_left #bisect_left(list, value)
sys.setrecursionlimit(10**7)
enu = enumerate
MOD = 10**9+7
def input(): return sys.stdin.readline()[:-1]
pl = lambda x: print(*x, sep='\n')


def solve():
    a, b, c, d = map(int, input().split())
    a -= b
    if a <= 0:
        print(b)
        return
    if c <= d:
        print(-1)
        return
    if a%d == 0:
        cds = a//(c-d)
    else:
        cds = a//(c-d) + 1
    print(b + c*cds)
    return

T = int(input())
for t in range(T):
    solve()