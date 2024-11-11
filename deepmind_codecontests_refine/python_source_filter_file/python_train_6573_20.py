n,k=map(int,input().split())
sm= 0 
l=[int(i) for i in input().split()]
l=[i%k for i in l]
from collections import defaultdict 
d=defaultdict(int)
for i in l:
    if i==0:
        if d[0]>0:
            sm+=2 
            d[0]=0 
        else:
            d[0]+=1 
        continue 
    if d[k-i]>0:
        sm+=2 
        d[k-i]=0 
        d[i]=0 
    else:
        d[i]+=1 
print(sm)