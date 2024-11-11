import heapq
from math import ceil
 
t=int(input())
for _ in range(t):
    n=int(input())
    a=[0]*(n+1)
    h=[]
    heapq.heappush(h,(-n,1,n))
    for i in range(1,n+1):
        e=heapq.heappop(h)
        _,l,r = e;
        if(r-l+1)%2!=0:
            a[(l+r)//2]=i
            new_ind=(l+r)//2
        else:
            a[(l+r-1)//2]=i
            new_ind=(l+r-1)//2
        if new_ind !=l:
            heapq.heappush(h,(l-new_ind,l,new_ind-1))
        if new_ind !=r:
            heapq.heappush(h,(new_ind-r,new_ind+1,r))
    print(' '.join([str(x) for x in a[1:]]))