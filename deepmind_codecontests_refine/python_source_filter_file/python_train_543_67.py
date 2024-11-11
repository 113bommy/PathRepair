from sys import stdin
import math

inp = lambda: stdin.readline().strip()

t = int(inp())
for _ in range(t):
    n = int(inp())
    if n >= 5:
        total = 8
        c = 5
        c2 = 2
        for i in range((n//2)-1):
            total += c2 * (c * c - ((c - 2) * (c - 2)))
            c += 2
            c2 += 1
        print(total)
    else:
        print(0)
