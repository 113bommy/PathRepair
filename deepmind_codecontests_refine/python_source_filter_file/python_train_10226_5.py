import sys
from collections import defaultdict
from collections import  deque
import heapq
vis=defaultdict(int)
n,m=map(int,sys.stdin.readline().split())
arr=list(map(int,sys.stdin.readline().split()))
q=deque()
heap=[]
for i in range(len(arr)):
    heapq.heappush(heap,[0,arr[i]])
    #q.append([arr[i],0])
    vis[arr[i]]=1
ans=[]
dis=0
while m>0:
    d,a=heapq.heappop(heap)
    if vis[a+1]==0:
        m-=1
        vis[a+1]=1
        dis+=(d+1)
        ans.append(a+1)
        #q.append([a+1,d+1])
        heapq.heappush(heap,[d+1,a+1])
    if vis[a-1]==0:
        m-=1
        vis[a-1]=1
        dis+=(d+1)
        ans.append(a-1)
        #q.append([a-1,d+1])
        heapq.heappush(heap,[d+1,a-1])
print(dis)
print(*ans)
        
