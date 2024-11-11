from sys import stdin, stdout
from heapq import *
n = int(input())
v = list(map(int, input().split()))
t = list(map(int, input().split()))
heap = []
eps = 0
for i in range(n):
    ans = 0
    heappush(heap, eps + v[i])
    while heap :
        if heap[0] < eps + t[i]:
            break
        ans += heap[0] - eps
        heappop(heap)
    ans += len(heap) * t[i]
    eps += t[i]
    print(ans, end=" ")