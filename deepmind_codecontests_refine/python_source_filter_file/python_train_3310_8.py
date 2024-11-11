import heapq

n,m=map(int,input().split())
A=[int(i)*(-1) for i in input().split()]
heapq.heapify(A)

for i in range(m):
  M=heapq.heappop(A)
  heapq.heappush(A,M//2)
  
ans=-sum(A)
print(ans)
