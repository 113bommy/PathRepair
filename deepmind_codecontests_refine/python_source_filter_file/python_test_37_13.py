import sys
input = lambda: sys.stdin.readline().rstrip()
import bisect
import itertools
import math
from collections import deque
from collections import Counter
import copy

def solve():
    n, m = map(int,input().split())
    blist = set()
    for i in range(m):
        a, b, c = map(int,input().split())
        blist.add(b)
    for i in range(1, n + 1):
        if i not in blist:
            for j in range(1, n + 1):
                if j + 1 == i:
                    continue
                print(i, j + 1)
            return
    return


    
t = int(input())
for _ in range(t):
    solve()

