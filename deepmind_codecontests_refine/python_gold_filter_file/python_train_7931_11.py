import sys
from collections import deque
readline = sys.stdin.readline

q = int(readline())

for _ in range(q):
    n = int(readline())
    p = [int(x) for x in readline().split()]
    p.sort()
    ans = 1
    if len(p) == 1:
        print(ans)
        continue
    else:
        for i in range(n - 1):
            if p[i + 1] - p[i] == 1:
                ans = 2
                break
    print(ans)