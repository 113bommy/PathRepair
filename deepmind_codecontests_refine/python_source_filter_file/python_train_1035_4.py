import heapq
n=int(input())
abs=sorted([list(map(int,input().split())) for _ in range(n)])
s=0
best=0
heap=[]
for k in range(1,n+1):
    while(s < n and abs[s][0] <= k+1):
        heapq.heappush(heap, -abs[s][1])
        s+=1
    while(len(heap) > 0 and -heap[0] <= k):
        heapq.heappop(heap)
    if(len(heap) >= k):
        best = k
print(best)