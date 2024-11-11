import sys 
from sys import stdin

from bisect import bisect_left, bisect_right
from collections import defaultdict, deque, namedtuple
from math import gcd, ceil, floor
from itertools import combinations, permutations

# https://codeforces.com/contest/1559/problem/D1

def find(p, x):
    if p[x] != x:
        p[x] = find(p, p[x])
    return p[x]

def main():
    n, m1, m2 = map(int, input().split())

    p1 = [i for i in range(n)]
    for i in range(m1):
        a, b = map(int, input().split())
        a -= 1 
        b -= 1 
        x, y = find(p1, a), find(p1, b)
        if x != y:
            p1[y] = x 
    
    p2 = [i for i in range(n)]
    for i in range(m2):
        a, b = map(int, input().split())
        a -= 1 
        b -= 1 
        x, y = find(p2, a), find(p2, b)
        if x != y:
            p2[y] = x 
    
    for i in range(n):
        find(p1, i)
        find(p2, i)
    
    ans = 0 
    es = []
    for i in range(n):
        for j in range(n):
            if i == j:
                continue 
            x1 = find(p1, i)
            y1 = find(p1, j)
            if x1 == y1:
                continue 
            x2 = find(p2, i)
            y2 = find(p2, j)
            if x2 == y2:
                continue
            
            p1[y1] = x1 
            p2[y2] = x2 
            ans += 1 
            es.append([i, j])
    print(ans)
    for a, b in es:
        print(f"{a + 1} {b + 1}")
    return 


if __name__ == '__main__':
    main()