import heapq

N , M = map(int,input().split())
A = [-int(i) for i in input().split()]

heapq.heapify(A)
for _ in range(M):
    a = heapq.heappop(A) >> 1
    heapq.heappush(A,a)
print(-sum(A))
