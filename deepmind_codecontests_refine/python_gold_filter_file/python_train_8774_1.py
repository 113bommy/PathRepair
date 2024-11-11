from heapq import heapify,heappop,heappush
from collections import defaultdict
coun=0
minheap=[]
maxheap=[]
ans=[]
dic=defaultdict(int)
try:
    for _ in range(int(input())):
        a=list(map(int,input().split()))
        if a[0]==1:
            coun+=1
            dic[coun]=0
            heappush(maxheap,(-a[1],coun))
            heappush(minheap,(coun,a[1]))
        elif a[0]==2:
            x,y=heappop(minheap)
            while dic[x]==1:
                x,y=heappop(minheap)
            dic[x]=1
            ans.append(x)
        else:
            x, y = heappop(maxheap)
            while dic[y] == 1:
                x, y = heappop(maxheap)
            dic[y] = 1
            ans.append(y)
        #print(maxheap,minheap)
    print(*ans)
except:
    print(*ans)