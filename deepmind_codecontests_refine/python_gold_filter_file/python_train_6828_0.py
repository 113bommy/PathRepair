from sys import stdin, stdout, setrecursionlimit
input = stdin.readline
# import string
# characters = string.ascii_lowercase
# digits = string.digits
# setrecursionlimit(int(1e5))
# dir = [-1,0,1,0,-1]
# moves = 'NESW'
inf = float('inf')
from functools import cmp_to_key
from collections import defaultdict as dd
from collections import Counter, deque
from heapq import *
import math
from math import floor, ceil, sqrt
def geti(): return map(int, input().strip().split())
def getl(): return list(map(int, input().strip().split()))
def getis(): return map(str, input().strip().split())
def getls(): return list(map(str, input().strip().split()))
def gets(): return input().strip()
def geta(): return int(input())
def print_s(s): stdout.write(s+'\n')

def solve():
    n = geta()
    a = getl()
    limit = floor(sqrt(n)) + 1
    dp = [[0 for i in range(limit)] for _ in range(n+1)]
    for p in range(n-1, -1, -1):
        for k in range(1, limit):
            new = a[p] + k + p + 1
            if new > n:
                dp[p+1][k] = 1
                break
            else:
                dp[p+1][k] = max(1, dp[new][k]) + 1
    for i in range(geta()):
        p, k = geti()
        if k < limit:
            print(max(1, dp[p][k]))
        else:
            ans = 0
            while p <= n:
                p = a[p-1] + p + k
                ans += 1
            print(ans)


if __name__=='__main__':
    solve()
