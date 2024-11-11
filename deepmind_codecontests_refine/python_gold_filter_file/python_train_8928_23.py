H,W,K=map(int,input().split())
x1,y1,x2,y2=map(lambda x:int(x)-1,input().split())

pond=[]
for _ in range(H):
    pond.append(list(input()))

inf=10**7
cost=[[inf]*W for _ in range(H)]
cost[x1][y1]=0
from heapq import heapify,heappop,heappush
hq=[(0,x1,y1)]

while hq:
    t,x,y=heappop(hq)
    #北へ
    for i in range(1,K+1):
        if x-i<0 or pond[x-i][y]=="@" or cost[x-i][y]<t+1:
            break
        if cost[x-i][y]>t+1:
            cost[x-i][y]=t+1
            heappush(hq,(t+1,x-i,y))
    #東へ
    for i in range(1,K+1):
        if y+i>W-1 or pond[x][y+i]=="@" or cost[x][y+i]<t+1:
            break
        if cost[x][y+i]>t+1:
            cost[x][y+i]=t+1
            heappush(hq,(t+1,x,y+i))
    #南へ
    for i in range(1,K+1):
        if x+i>H-1 or pond[x+i][y]=="@" or cost[x+i][y]<t+1:
            break
        if cost[x+i][y]>t+1:
            cost[x+i][y]=t+1
            heappush(hq,(t+1,x+i,y))
    #西へ
    for i in range(1,K+1):
        if y-i<0 or pond[x][y-i]=="@" or cost[x][y-i]<t+1:
            break
        if cost[x][y-i]>t+1:
            cost[x][y-i]=t+1
            heappush(hq,(t+1,x,y-i))

if cost[x2][y2]==inf:
    print(-1)
    exit()  
print(cost[x2][y2])
