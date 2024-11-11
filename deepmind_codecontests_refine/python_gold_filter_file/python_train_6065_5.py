n=int(input())
f= list(map(int,input().split()))
from collections import Counter
c=Counter(f)
sumi=0
for item in c.keys():
    if(item>n and (c[item]>1 or c[item]<=1)):
        sumi=sumi+c[item]
    elif(item<=n and c[item]>=1):
        sumi=sumi+c[item]-1
        
print (sumi)