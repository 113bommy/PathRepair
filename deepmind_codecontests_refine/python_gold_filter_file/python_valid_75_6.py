from collections import defaultdict, Counter,deque
from math import sqrt, log10, log, floor, factorial,gcd
from bisect import bisect_left, bisect_right
from itertools import permutations,combinations
import sys, io, os
input = sys.stdin.readline
input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
# sys.setrecursionlimit(10000)
inf = float('inf')
mod = 10 ** 9 + 7
def yn(a): print("YES" if a else "NO")
ceil = lambda a, b: (a + b - 1) // b
t=int(input())
for i in range(t):
    n=int(input())
    t=[]
    for i in range(n):
        l=[int(i) for i in input().split()]
        l=[l[i]-i+1 for i in range(1,len(l))]
        temp=[max(l)+1,len(l)]
        t.append(temp)
    t.sort(key=lambda a:[a[0],-a[1]])
    # print(t)
    maxa=t[0][0]
    adder=t[0][0]
    for i in range(n):
        if maxa<t[i][0]:
            adder+=t[i][0]-maxa
            maxa+=t[i][0]-maxa
        maxa+=t[i][1]
        # print(maxa,adder)
    print(adder)