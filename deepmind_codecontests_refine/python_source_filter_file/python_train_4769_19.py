import heapq
Q = int(input())
qs = [tuple(map(int,input().split())) for i in range(Q)]

lq = []
rq = []
heapq.heapify(lq)
heapq.heapify(rq)
ans = 0

for q in qs:
    if q[0] == 2:
        print(-lq[0], ans)
        continue
    _,a,b = q
    ans += b
    heapq.heappush(lq, -a)
    heapq.heappush(rq, a)
    if -lq[0] > rq[0]:
        l = -heapq.heappop(lq)
        r = heapq.heappop(rq)
        ans += abs(l-r)
        heapq.heappush(lq,-r)
        heapq.heappush(rq,r)