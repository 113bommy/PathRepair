import heapq
import sys
(n, k) = map(int, sys.stdin.readline().split())
p = []
for i in range(n):
    (a, b) = tuple(map(int, input().split()))
    p.append((a, b))
p.sort(reverse=True)
ans = 0
time = 0
a = []
for b, t in p:
    time += t
    heapq.heappush(a, t)
    if len(a) > k:
        c = heapq.heappop(a)
        time -= c
    ans = max(ans, time * b)
print(ans)
