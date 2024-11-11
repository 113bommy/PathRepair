from collections import defaultdict
import math
n=int(input())
d=defaultdict(int)
o=defaultdict(int)
for i in range(n):
    x,y=map(int,input().split())
    o[x]+=1
    d[x]+=1
    if y!=x:
        d[y]+=1
mi=10**5+1
for i in d:
    print(d[i])
    if d[i]>=math.ceil(n/2):
        mi=min(mi,max(math.ceil(n/2)-o[i],0))
if mi==10**5+1:
    print(-1)
else:
    print(mi)
        
    
    
