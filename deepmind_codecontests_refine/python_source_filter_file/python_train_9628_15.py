import math,sys,bisect,heapq
from collections import defaultdict,Counter,deque
from itertools import groupby,accumulate
from functools import lru_cache
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

n,k = aj()
A = [['S']*n for i in range(n)]
for i in range(n):
    for j in range(n):
        if k == 0:
            break
        if i%2 == 0:
            if j%2 == 0:
                A[i][j] = 'L'
                k-=1
        else:
            if j%2:
                A[i][j] = 'L'
                k-=1
Y(k == 0)
if k == 0:
    for i in A:
        print(*i)