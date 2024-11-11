"""
Author    : co_devil Chirag Garg
Institute : JIIT
"""
from math import *
from sys import stdin, stdout
import itertools, os, sys, threading
from collections import deque, Counter, OrderedDict, defaultdict
from heapq import *
#from math import ceil, floor, log, sqrt, factorial, pow, pi, gcd
# from bisect import bisect_left,bisect_right
# from decimal import *,threading
from fractions import Fraction
mod=100000009
def ii(): return int(input())
def si(): return str(input())
def mi(): return map(int, input().split())
def li(): return list(mi())
def fii(): return int(stdin.readline())
def fsi(): return str(stdin.readline())
def fmi(): return map(int, stdin.readline().split())
def fli(): return list(fmi())
abd = {'a': 0, 'b': 1, 'c': 2, 'd': 3, 'e': 4, 'f': 5, 'g': 6, 'h': 7, 'i': 8, 'j': 9, 'k': 10, 'l': 11, 'm': 12,
       'n': 13, 'o': 14, 'p': 15, 'q': 16, 'r': 17, 's': 18, 't': 19, 'u': 20, 'v': 21, 'w': 22, 'x': 23, 'y': 24,
       'z': 25}
def getKey(item): return item[0]
def sort2(l): return sorted(l, key=getKey)
def d2(n, m, num): return [[num for x in range(m)] for y in range(n)]
def isPowerOfTwo(x): return (x and (not (x & (x - 1))))
def decimalToBinary(n): return bin(n).replace("0b", "")
def ntl(n): return [int(i) for i in str(n)]
def powerMod(x, y, p):
    res = 1
    x %= p
    while y > 0:
        if y & 1:
            res = (res * x) % p
        y = y >> 1
        x = (x * x) % p
    return res
graph = defaultdict(list)
visited = [0] * 1000000
col = [-1] * 1000000
def bfs(d, v):
    q = []
    q.append(v)
    visited[v] = 1
    while len(q) != 0:
        x = q[0]
        q.pop(0)
        for i in d[x]:
            if visited[i] != 1:
                visited[i] = 1
                q.append(i)
        print(x)
def make_graph(e):
    d = {}
    for i in range(e):
        x, y= mi()
        if x not in d:
            d[x]=[y]
        else:
            d[x].append(y)
        if y not in d:
            d[y]=[x]
        else:
            d[y].append(x)
    return d
def gr2(n):
    d = defaultdict(list)
    for i in range(n):
        x, y = mi()
        d[x].append(y)
    return d
def connected_components(graph):
    seen = set()
    def dfs(v):
        vs = set([v])
        component = []
        while vs:
            v = vs.pop()
            seen.add(v)
            vs |= set(graph[v]) - seen
            component.append(v)
        return component

    ans = []
    for v in graph:
        if v not in seen:
            d = dfs(v)
            ans.append(d)
    return ans
def primeFactors(n):
    s = set()
    while n % 2 == 0:
        s.add(2)
        n = n // 2
    for i in range(3, int(sqrt(n)) + 1, 2):
        while n % i == 0:
            s.add(i)
            n = n // i
    if n > 2:
        s.add(n)
    return s
def find_all(a_str, sub):
    start = 0
    while True:
        start = a_str.find(sub, start)
        if start == -1: return
        yield start
        start += len(sub)
def SieveOfEratosthenes(n, isPrime):
    isPrime[0] = isPrime[1] = False
    for i in range(2, n):
        isPrime[i] = True
    p = 2
    while (p * p <= n):
        if (isPrime[p] == True):
            i = p * p
            while (i <= n):
                isPrime[i] = False
                i += p
        p += 1
    return isPrime
def dijkstra(edges, f, t):
    g = defaultdict(list)
    for l,r,c in edges:
        g[l].append((c,r))

    q, seen, mins = [(0,f,())], set(), {f: 0}
    while q:
        (cost,v1,path) = heappop(q)
        if v1 not in seen:
            seen.add(v1)
            path = (v1, path)
            if v1 == t: return (cost, path)

            for c, v2 in g.get(v1, ()):
                if v2 in seen: continue
                prev = mins.get(v2, None)
                next = cost + c
                if prev is None or next < prev:
                    mins[v2] = next
                    heappush(q, (next, v2, path))
    return float("inf")

t=ii()
for a0 in range(t):
    n,x,a,b=mi()
    ma=n-1
    if n>0:
        print(min(ma,abs(a-b)+x))
    else:
        print(abs(a-b))