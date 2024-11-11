from heapq import heappush, heappop
n, m = map(int, input().split())
B = [[] for _ in range(m+1)]
for _ in range(n):
    a, b = map(int, input().split())
    if a <= m: B[a] += [-b]
print(B)
C = []
s = 0
for i in range(m+1):
    for b in B[i]: heappush(C, b)
    if C: s += heappop(C)
print(-s)