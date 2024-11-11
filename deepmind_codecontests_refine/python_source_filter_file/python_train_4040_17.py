import heapq

n,m = map(int, input().split())

c = [[]for i in range(10**5)]

for i in range(n):
    a,b = map(int,input().split())
    c[a].append(-b)


h = []
heapq.heapify(h)
ans = 0

for i in range(m):
    for x in c[i+1]:
        heapq.heappush(h,x)
    if h:
        ans += heapq.heappop(h)

print(-ans)
