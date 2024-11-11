from heapq import heappush, heappop
import sys
input = sys.stdin.readline

N, K = map(int, input().split())
P = list(map(int, input().split()))
mn = [N] * (N-K)
mx = [-1] * (N-K)
min_heap = []
max_heap = []
for i in range(K):
    heappush(min_heap, P[i])
    heappush(max_heap, -P[i])
used = set()
for i in range(N-K):
    heappush(min_heap, P[i+K])
    heappush(max_heap, -P[i+K])
    while min_heap[0] in used:
        heappop(min_heap)
    while -max_heap[0] in used:
        heappop(max_heap)
    mn[i] = min_heap[0]
    mx[i] = -max_heap[0]
    used.add(P[i])
ans = 1
for i in range(N-K):
    if P[i] != mn[i] or P[i+K] != mx[i]:
        ans += 1
inc = 1
cnt = 0
for i in range(1, N):
    if P[i-1] < P[i]:
        inc += 1
    else:
        inc = 1
    if inc == K:
        cnt += 1
ans -= max(0, cnt-1)
print(ans)


