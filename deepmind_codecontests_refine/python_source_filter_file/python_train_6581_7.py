#!/usr/bin/env python3
import sys
input = sys.stdin.readline
INF = 10**9

t = int(input())
for _ in range(t):
    n = int(input())
    s = input().rstrip()
    x = 0; y = 0
    seen = {(0, 0): 0}
    min_len = INF
    ans = None
    for i, ch in enumerate(s):
        if ch == "L":
            y -= 1
        elif ch == "R":
            y += 1
        elif ch == "U":
            x -= 1
        elif ch == "D":
            x += 1
        if (x, y) not in seen:
            seen[(x, y)] = i + 1
            continue
        l = seen[(x, y)]
        if i - l < min_len:
            ans = (l+1, i+1)
            min_len = i - l
        seen[(x, y)] = i
    if ans == None:
        print(-1)
    else:
        print(*ans)