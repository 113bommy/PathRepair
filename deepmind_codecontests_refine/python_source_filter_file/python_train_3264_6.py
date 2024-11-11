import heapq
t1 = []
t2 = []
n, m = map(int, input().split())
for c in map(int, input().split()):
    heapq.heappush(t1, c)
    heapq.heappush(t2, -c)
ans1 = ans2 = 0

k1 = n
while k1:
    cq = heapq.heappop(t1)
    if k1 >= cq:
        ans1 += (1 + cq) * cq // 2
        k1 -= cq
    else:
        ans1 += (cq + cq - k1) * k1 // 2
        k1 = 0

for _ in range(n):
    c1 = heapq.heappop(t2)
    ans2 += -c1
    c1 += 1
    heapq.heappush(t2, c1)
print(ans2, ans1)
