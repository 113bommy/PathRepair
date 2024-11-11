import sys, math
import io, os
#data = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
from bisect import bisect_left as bl, bisect_right as br, insort
from heapq import heapify, heappush, heappop
from collections import defaultdict as dd, deque, Counter
# from itertools import permutations,combinations
def data(): return sys.stdin.readline().strip()
def mdata(): return list(map(int, data().split()))
def outl(var): sys.stdout.write(' '.join(map(str, var)) + '\n')
def out(var): sys.stdout.write(str(var) + '\n')
from decimal import Decimal
# from fractions import Fraction
# sys.setrecursionlimit(100000)
mod = int(1e9) + 7
INF=100000

for t in range(int(data())):
    n,k=mdata()
    s=list(data())
    flag=True
    for i in range(n//k):
        s1=set()
        ind=i
        while ind<n:
            if s[ind]!='?':
                s1.add(s[ind])
            ind+=k
        if len(s1)>1:
            flag=False
            break
        if s1:
            a=s1.pop()
            ind=i
            while ind < n:
                s[ind] = a
                ind += k
    z1, o1 = 0, 0
    for i in s[:k]:
        if i == '1':
            o1 += 1
        elif i == '0':
            z1 += 1
        if o1 > k // 2 or z1 > k // 2:
            flag = False
            break

    for i in range(k, n):
        if s[i] == '1':
            o1 += 1
        elif s[i] == '0':
            z1 += 1
        if s[i - k] == '1':
            o1 -= 1
        elif s[i - k] == '0':
            z1 -= 1
        if o1 > k // 2 or z1 > k // 2:
            flag = False
            break
    if flag:
        out("YES")
    else:
        out("NO")

