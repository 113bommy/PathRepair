# Author: S Mahesh Raju
# Username: maheshraju2020
# Date: 19/09/2020
from sys import stdin, stdout, setrecursionlimit
import heapq
from math import gcd, ceil, sqrt
from collections import Counter, deque
from bisect import bisect_left, bisect_right
ii1 = lambda: int(stdin.readline().strip())
is1 = lambda: stdin.readline().strip()
iia = lambda: list(map(int, stdin.readline().strip().split()))
isa = lambda: stdin.readline().strip().split()
setrecursionlimit(100000)
mod = 1000000007

def bfs(d):
    queue = deque([1])
    order = []
    par = {1: 0}
    seen = set([1])
    while len(queue):
        cur = queue.popleft()
        order.append(cur)
        for neigh in d.get(cur, []):
            if neigh not in seen:
                seen.add(neigh)
                par[neigh] = cur
                queue.append(neigh)
    order = order[::-1]
    childs = [1] * len(d)
    cnt = [0] * len(d)
    for i in order:
        if par[i] != 0:
            childs[par[i] - 1] += childs[i - 1]
    
    for i in range(len(d)):
        if childs[i] * 2 == len(d):
            for j in d[i + 1]:
                if j != par[i + 1]:
                    cur = j
            print(i + 1, cur)
            print(par[i + 1], cur)
            break
    else:
        print(1, d[1][0])
        print(1, d[1][0])
            

tc = ii1()
for _ in range(tc):
    n = ii1()
    d = {}
    for i in range(n - 1):
        a, b = iia()
        d.setdefault(a, []).append(b)
        d.setdefault(b, []).append(a)
    bfs(d)
    