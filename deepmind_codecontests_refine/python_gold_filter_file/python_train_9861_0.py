import heapq
n, k = [int(_) for _ in input().split()]
p = list(map(int, input().split()))
c = list(map(int, input().split()))
ans = [0] * n
heap = []
count = 0
ana1 = sorted(list(zip(p, c, range(n))))
for power, coin, index in ana1:
    count += coin
    ans[index] = count
    heapq.heappush(heap, coin)
    if len(heap) > k:
        count -= heapq.heappop(heap)
print(*ans)