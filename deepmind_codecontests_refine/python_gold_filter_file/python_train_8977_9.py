import math
from sys import stdin,stdout
#% 998244353
from heapq import heapify,heappop,heappush

res=[1]
b=1
i=1
while i<math.pow(10,18)+1:
    res.append(res[-1]*2+1) 
    i<<=1
#print(res)
T = int(stdin.readline())
for i in range(T):
    N=int(stdin.readline())
    ans=0
    ind=0
    while N:
        if N&1:
            ans+=res[ind]
        ind+=1
        N>>=1
    
    print(ans)


