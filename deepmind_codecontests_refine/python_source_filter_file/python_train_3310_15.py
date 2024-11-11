import heapq

n,m=map(int,input().split())
a=list[map(int,input().split())]
b=[-int(i) for i in a]

heapq.heapify(b)

for i in range(m):
    x=heapq.heappop(b)//2
    heapq.heappush(b,x)

print(-sum(b))
