import heapq
inf=10**9
n,k=map(int,input().split())
a,d=[],{}
for i in range(n):
    a.append(-int(input()))
    d[a[-1]]=0
for i in range(k):d[a[i]]+=1
h=[inf]
for x in d:
    if d[x]==1:
        h.append(x)
heapq.heapify(h)
d[inf]=1
print (-h[0]) if h[0]<inf else 'Nothing'
for x,y in zip(a,a[k:]):
    d[x]-=1
    d[y]+=1
    if d[x]==1: heapq.heappush(h,x)
    if d[y]==1: heapq.heappush(h,y)
    while d[h[0]]!=1: heapq.heappop(h)
    print (-h[0]) if h[0]<inf else 'Nothing'
    
