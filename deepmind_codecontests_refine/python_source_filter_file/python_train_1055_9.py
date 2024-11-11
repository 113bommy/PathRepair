import sys
input = sys.stdin.readline
from heapq import *

n, k = map(int, input().split())
tb = [tuple(map(int, input().split())) for _ in range(n)]
tb.sort(key=lambda k: k[1], reverse=True)
pq = []
ans = 0
ts = 0

for i in range(k):
    heappush(pq, tb[i][0])
    ts += tb[i][0]
    ans = max(ans, ts*tb[i][1])

for i in range(k+1, n):
    if tb[i][0]>pq[0]:
        rem_t = heappop(pq)
        heappush(pq, tb[i][0])
        ts += tb[i][0]-rem_t
    
    ans = max(ans, ts*tb[i][1])

print(ans)