# aadiupadhyay
import os.path
from math import gcd, floor, ceil
from collections import *
import sys
from heapq import *
mod = 1000000007
INF = float('inf')
def st(): return list(sys.stdin.readline().strip())
def li(): return list(map(int, sys.stdin.readline().split()))
def mp(): return map(int, sys.stdin.readline().split())
def inp(): return int(sys.stdin.readline())
def pr(n): return sys.stdout.write(str(n)+"\n")
def prl(n): return sys.stdout.write(str(n)+" ")


if os.path.exists('input.txt'):
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')


def solve():
    def dfs(x):
        stack = [x]
        v[x] = 1
        while stack:
            a = stack.pop()
            for i in d[a]:
                if v[i]:
                    if color[i] == color[a]:
                        pr('NO')
                        return
                else:
                    color[i] = color[a] ^ 1
                    v[i] = 1
                    stack.append(i)

    n, m = mp()
    d = defaultdict(list)
    l = []
    for i in range(m):
        a, b = mp()
        l.append([a, b])
        d[a].append(b)
        d[b].append(a)
    color = defaultdict(lambda: -1)
    color[1] = 0
    v = defaultdict(int)
    dfs(1)
    ans = []
    pr('YES')
    for i in l:
        a, b = i
        if color[a] == 0:
            ans.append('1')
        else:
            ans.append('0')
    print(*ans, sep='')


for _ in range(1):
    solve()
