import heapq
n, m = map(int, input().split())
lst = list(map(lambda x:-1*int(x), input().split()))
heapq.heapify(lst)
for i in range(m):
  heapq.heappush(lst, -(-heapq.heappop(lst))//2)
print(-1*sum(lst))