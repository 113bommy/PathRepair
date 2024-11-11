import math
import collections
from collections import defaultdict
n=int(input())
l=[list(map(int,input().split())) for i in range(n)]
mod=10**9+7

L=[]
ct0=0
for i in range(n):
  if l[i][0]==0 and l[i][1]==0:
    ct0+=1
  elif l[i][0]==0:
    L.append((0,1))
  elif l[i][1]==0:
    L.append((1,0))
  elif l[i][0]<0:
    L.append((-l[i][0]//math.gcd(l[i][0],l[i][1]),-l[i][1]//math.gcd(l[i][0],l[i][1])))
  else:
    L.append((l[i][0]//math.gcd(l[i][0],l[i][1]),l[i][1]//math.gcd(l[i][0],l[i][1])))

ans=1
d=set()
c=collections.Counter(L)
for i in c.keys():
  if i[0]==0:
    x=(1,0)
  elif i[1]==0:
    x=(0,1)
  elif i[1]<0:
    x=(-i[1],i[0])
  else:
    x=(i[1],-i[0])
  if i not in d:
    ans*=pow(2,c[i],mod)+pow(2,c[x],mod)-1
    ans%=mod
    d.add(x)
print((ans-1)%mod)