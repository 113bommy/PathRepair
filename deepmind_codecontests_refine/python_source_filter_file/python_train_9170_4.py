from sys import stdin
from math import ceil

inp = stdin.readline
n, t = [int(x) for x in inp().strip().split()]
for _ in range(t):
    x, y = [int(x) for x in inp().strip().split()]
    s = (x-1)*n+y
    if (x+y)%2:
        print((s+1)//2 + (n**2+1)/2)
    else:
        print((s+1)//2)

