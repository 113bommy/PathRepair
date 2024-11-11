import math,sys,bisect,heapq
from collections import defaultdict,Counter,deque
from itertools import groupby,accumulate
#sys.setrecursionlimit(200000000)
int1 = lambda x: int(x) - 1
def input(): return sys.stdin.readline().strip()
ilele = lambda: map(int,input().split())
alele = lambda: list(map(int, input().split()))
ilelec = lambda: map(int1,input().split())
alelec = lambda: list(map(int1, input().split()))
def list2d(a, b, c): return [[c] * b for i in range(a)]
def list3d(a, b, c, d): return [[[d] * c for j in range(b)] for i in range(a)]
#MOD = 1000000000 + 7
def Y(c):  print(["NO","YES"][c])
def y(c):  print(["no","yes"][c])
def Yy(c):  print(["No","Yes"][c])
    
n,m = ilele()
A = alele()
B = alele()

def gcd(a,b):
    if b == 0:
        return a
    return gcd(b,a%b)

if n == 1:
    for i in range(m):
        print(gcd(A[0],B[i]),end = ' ')
else:
    A.sort()
    g = A[1] - A[0]
    for i in range(2,n):
        g = gcd(g,A[i] - A[i-1])
    for i in range(m):
        print(gcd(A[0] + B[i],g),end = ' ')
    
    
    