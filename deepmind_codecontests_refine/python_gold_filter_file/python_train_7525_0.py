from sys import stdin, stdout
import heapq
import cProfile
from collections import Counter, defaultdict, deque
from functools import reduce
import math
import threading
import sys
import time


def get_int(): return int(stdin.readline().strip())
def get_tuple(): return map(int, stdin.readline().split())
def get_list(): return list(map(int, stdin.readline().split()))


def solve():
    n,k = get_tuple()
    if n==k:
        ans = [i for i in range(1,n+1)]
        print(*ans)
        return
    s,p = k,k
    ans = []
    while s<=n:
        ans.append(p)
        p -= 1
        s += 1
    ans = [i for i in range(1,p+1)]+ans
    print(*ans)

testcases = True
if testcases:
    t = get_int()
    for _ in range(t):
        solve()
else:
    solve()
