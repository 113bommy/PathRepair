from sys import stdin
import math

inp = lambda: stdin.readline().strip()

t = int(inp())
for _ in range(t):
    n, d = [int(x) for x in input().split()]
    h = [int(x) for x in input().split()]
    flag = False
    for i in range(n):
        if flag:
            break
        for j in range(n):
            if i != j:
                needed = i + j
                if needed > d:
                    flag = True
                    break
                while h[j] > 0 and d >= needed:
                    h[j] -= 1
                    h[0] += 1
                    d -= needed
    print(h[0])
