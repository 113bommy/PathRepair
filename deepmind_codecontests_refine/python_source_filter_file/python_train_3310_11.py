import heapq
n,m=map(int,input().split())
l=list(map(lambda x:-int(x),input().split()))
heapq.heapify(l)
for _ in range(m):
  heapq.haeppush(l,-(-heapq.heappop(l)//2))
print(-sum(l))