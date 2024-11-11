a=int(input())
from bisect import *
z=list(map(int,input().split()))
from collections import *
al=defaultdict(list)
for i in range(len(z)):
    al[z[i]].append(i)
cnt=0
for i in range(len(z)):
    for j in range(32):
        
        r=bisect_right(al[pow(2,j)-z[i]],i)
        cnt+=len(al[pow(2,j)])-r
print(cnt)
        
            
            
