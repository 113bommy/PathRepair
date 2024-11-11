from heapq import *
s=input()
k=int(input())
l=len(s)
if k>(l+1)*l/2:
    print('No such line.')
else:
    sub=[[s[i],i] for i in range(l)]
    heapify(sub)
    while k>1:
        k-=1
        a=heappop(sub)
        if a[1]<l-1:
            b=a[0]+s[a[1]+1]
            heappush(sub,[b,a[1]+1])
print(a[0])
