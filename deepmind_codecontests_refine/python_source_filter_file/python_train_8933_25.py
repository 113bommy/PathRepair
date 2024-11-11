###==================================================
### import
#import bisect
#from collections import Counter, deque, defaultdict
#from copy import deepcopy
#from functools import reduce, lru_cache
#from heapq import heappush, heappop
#import itertools
#import math
#import string
import sys
### stdin
def input(): return sys.stdin.readline()
def iIn(): return int(input())
def iInM(): return map(int, input().split())
def iInM1(): return map(int1, input().split())
def iInLH(): return list(map(int, input().split()))
def iInLH1(): return list(map(int1, input().split()))
def iInLV(n): return [iIn() for _ in range(n)]
def iInLV1(n): return [iIn()-1 for _ in range(n)]
def iInLD(n): return [iInLH() for _ in range(n)]
def iInLD1(n): return [iInLH1() for _ in range(n)]
def sInLH(): return list(input().split())
def sInLV(n): return [input().rstrip("\n") for _ in range(n)]
def sInLD(n): return [sInLH() for _ in range(n)]
### stdout
def OutH(lst): print(*lst)
def OutV(lst): print(*lst, sep="\n")
### setting
sys.setrecursionlimit(10 ** 6)
### utils
int1 = lambda x: int(x) - 1
### constants
INF = int(1e9)
MOD = 1000000007
dx = (-1, 0, 1, 0)
dy = (0, -1, 0, 1)
###---------------------------------------------------

## factorial library
## 

## begin library factorial here
## usage: fac = Factorial()
## usage: nCr = fac.comb(n, r)
## usage: nPr = fac.perm(n, r)
class Factorial:

    def __init__(self, N):
        self.fact = [0] * (N+1)
        self.fact_inv = [0] * (N+1)
        self.calc_factorial(N)
        self.calc_inv_factorial(N)

    def calc_factorial(self, N):
        self.fact[0] = 1
        for i in range(N):
            self.fact[i+1] = self.fact[i] * (i+1) % MOD

    def calc_inv_factorial(self, N):
        self.fact_inv[N] = pow(self.fact[N], MOD-2, MOD)
        for i in range(N, 0, -1):
            self.fact_inv[i-1] = self.fact_inv[i] * i % MOD

    def comb(self, n, r):
        if (n < 0 or r < 0 or n < r): return 0
        res = self.fact[n]
        res = res * self.fact_inv[r] % MOD
        res = res * self.fact_inv[n-r] % MOD
        return res

    def perm(self, n, r):
        if (n < 0 or r < 0 or n < r): return 0
        res = self.fact[n]
        res = res * self.fact_inv[r] % MOD
        return res

MOD = 998244353

N, A, B, K = iInM()

fac = Factorial(300000)

ans = 0
for a in range(N+1):
    if (K - A * a) % B == 0:
        b = (K - A * a) // B
        ans = ans + fac.comb(N, a) * fac.comb(N, b) % MOD
    else:
        continue

print(ans)