from collections import defaultdict, deque
from heapq import heappush, heappop
from math import inf


def solve():
    n, m = map(int, input().split())
    cnt = defaultdict(int)
    res = []
    for i in range(n):
        A = list(map(int, list(input())))
        res.append(A)
        for j in range(m):
            if A[j]:
                cnt[j] += 1
    valid = False
    for r in res:
        j = [i for i in range(m) if A[i]]
        if all(cnt[i] > 1 for i in j):
            valid = True
            break
    if valid:
        print("YES")
    else:
        print("NO")

t = 1
# t = int(input())
while t:
    t -= 1
    solve()

