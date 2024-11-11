import math,sys,bisect,heapq
from collections import defaultdict,Counter,deque
from itertools import groupby,accumulate
from functools import lru_cache
from heapq import heapify,heappop,heappush
#sys.setrecursionlimit(200000000)
int1 = lambda x: int(x) - 1
#def input(): return sys.stdin.readline().strip()m
input = iter(sys.stdin.buffer.read().decode().splitlines()).__next__
aj = lambda: list(map(int, input().split()))
def list3d(a, b, c, d): return [[[d] * c for j in range(b)] for i in range(a)]
#MOD = 1000000000 + 7
def Y(c):  print(["NO","YES"][c])
def y(c):  print(["no","yes"][c])
def Yy(c):  print(["No","Yes"][c])

n, = aj()
A = aj()
if n == 1:
    print("1 1")
    print(0)
    print("1 1")
    print(0)
    print("1 1")
    print(-A[0])
else:    
    print("1 1")
    print(-A[0])
    A[0] = 0
    print("2",n)
    for ii,i in enumerate(A):
        if ii !=0:
            print(i*(n-1),end = ' ')
            A[ii] += i*(n-1)
    print()
    print(1,n)
    for i in A:
        print(-i,end = ' ')
    print()