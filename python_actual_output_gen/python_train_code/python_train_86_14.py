from sys import stdin
import math

def inp():
    return stdin.readline().strip()

t = int(inp())
for _ in range(t):
    n = int(inp())
    p = [0]*n
    c = [0]*n
    no = False
    for i in range(n):
        p[i], c[i] = [int(x) for x in inp().split()]
        if i > 0:
            if p[i] < p[i-1] or c[i] < c[i-1] or (p[i] == p[i-1]) and c[i] != c[i-1]:
                no = True
        if c[i] > p[i]:
            no = True
    if no:
        print("NO")
    else:
        print("YES")