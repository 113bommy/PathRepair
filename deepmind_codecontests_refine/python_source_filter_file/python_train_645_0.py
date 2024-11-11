import heapq
n=int(input())
a=list(map(int,input().split()))
t=list(map(int,input().split()))
d={}
for i in range(len(a)):
    if a[i] not in d:
        d[a[i]]=[]
    d[a[i]].append(t[i])
k=list(d.keys())
heapq.heapify(k)
cost=0
mxh=[]
sum_=0
while k:
    key=heapq.heappop(k)
    for i in d[key]:
        sum_+=i 
        heapq.heappush(mxh,-i)
    
    if not mxh:
        continue
    sum_+=heapq.heappop(mxh)
    cost+=sum_
    
    if not mxh:
        continue
    if key+1 not in d:
        heapq.heappush(mxh,key+1)
        d[key+1]=[]
    del d[key]
        
print(cost)
    