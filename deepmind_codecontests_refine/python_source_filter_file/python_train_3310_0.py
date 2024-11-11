import heapq
n, m = map(int, input().split())
li = [-int(x) for x in input().split()]
heapq.heapify(li)
for i in range(n):
  a = heapq.heappop(li)
  heapq.heappush(li, a/2)
print(-sum(int(x) for x in li))