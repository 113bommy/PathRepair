from collections import defaultdict, Counter,deque
from math import sqrt, log10, log, floor, factorial,gcd
from bisect import bisect_left, bisect_right
from itertools import permutations,combinations
import sys, io, os
input = sys.stdin.readline
# input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
# sys.setrecursionlimit(10000)
inf = float('inf')
mod = 10 ** 9 + 7
def yn(a): print("YES" if a else "NO")
ceil = lambda a, b: (a + b - 1) // b
t=int(input())
for i in range(t):
    n=int(input())
    l=[int(i) for i in input().strip()]

    m=[i for i in range(n) if l[i]==2]
    arr=[['=' for i in range(n)] for j in range(n)]
    for i in range(n):
        arr[i][i]='X'
    if len(m)==0:
        print("YES")
        for i in arr:
            print(*i,sep="")
    elif len(m)<=2:
        print("NO")
    else:
        print("YES")
        m+=[m[0]]
        # print(m)
        for i in range(len(m)-1):
            f=m[i]
            s=m[i+1]
            arr[f][s]='+'
            arr[s][f]='-'
        for i in arr:
            print(*i,sep="")
