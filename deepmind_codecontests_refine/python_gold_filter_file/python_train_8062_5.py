import heapq


N = int(input())
L = list(map(lambda x: int(x) * -1, input().split()))
ans = 0
heapq.heapify(L)

while N > 1:
    t = heapq.heappop(L) + heapq.heappop(L)
    ans -= t

    heapq.heappush(L, t)
    N -= 1

print(ans - L[0])
